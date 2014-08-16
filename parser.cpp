#include "parser.h"

#include <stdlib.h>
#include <iostream>

#include "cfg_tree_defs.h"

using std::cout;
using std::endl;

parser::parser (list<string> & a_str_stack): str_stack(a_str_stack)
{
	p_cfg = NULL;
	func_id_list_size = 0;
}

parser::~parser ()
{
	if(p_cfg != NULL)
	{
		delete p_cfg;
	}
}

cfg * parser::get_tree()
{
	return p_cfg;
}

void parser::on_cfg_n_func()
{
	func_list * p_func_list = NULL;
	rule_list * p_rule_list = NULL;
	if(ptr_stack.back().ptr_type == T_FUNC_LIST)
	{
		p_func_list = dynamic_cast<func_list *>(ptr_stack.back().ptr);
		ptr_stack.pop_back();
	}
	
	assert(ptr_stack.back().ptr_type == T_RULE_LIST);
	p_rule_list = dynamic_cast<rule_list *>(ptr_stack.back().ptr);
	ptr_stack.pop_back();

	p_cfg = new cfg;	
	p_cfg->set("", tmp_symbol_list, p_rule_list, p_func_list);
//print_stacks();
//p_cfg->print_this(cout);
}

void parser::on_grammar()
{	
	
}

void parser::on_rule_list()
{
	assert(ptr_stack.back().ptr_type == T_RULE_DEF);
	rule_def * p_rule_def = dynamic_cast<rule_def *>(ptr_stack.back().ptr);
	ptr_stack.pop_back();
	
	rule_list_c * p_rule_list_c = new rule_list_c;
	if(ptr_stack.back().ptr_type != T_RULE_LIST)
	{
		p_rule_list_c->set(NULL, p_rule_def);
		ptr_stack.push_back(parser::ptr_pair(p_rule_list_c, T_RULE_LIST));
	}else
	{
		p_rule_list_c->set(dynamic_cast<rule_list_c *>(ptr_stack.back().ptr), p_rule_def);
		ptr_stack.back() = parser::ptr_pair(p_rule_list_c, T_RULE_LIST);
	}
}

void parser::on_rule()
{
	assert(ptr_stack.back().ptr_type == T_PRODUCTIONS_LIST);
	string name = trim(str_stack.back());
	str_stack.pop_back();
	
	if(tmp_symbol_list.get_symbol_type(name).cfg_type != SYM_TYPE)
	{
		cout<<"***semantic error: non-terminal symbol "<<name<<" must declared with \"%type\"."<<endl;
		tmp_symbol_list.insert_symbol(name, symbol_list_item(SYM_TYPE, ""));//try best to recover from error
	}
	
	rule_def * p_rule_def = new rule_def;
	p_rule_def->set(name, dynamic_cast<productions_list_c *>(ptr_stack.back().ptr) );
	ptr_stack.pop_back();
	ptr_stack.push_back(parser::ptr_pair(p_rule_def, T_RULE_DEF));
}

void parser::on_branches()
{
	assert(ptr_stack.back().ptr_type == T_PRODUCTION);
	production * p_production = dynamic_cast<production *>(ptr_stack.back().ptr);
	ptr_stack.pop_back();
	
	productions_list_c * p_productions_list = new productions_list_c;
	if(ptr_stack.back().ptr_type != T_PRODUCTIONS_LIST)
	{
		p_productions_list->set(NULL, p_production);
		ptr_stack.push_back(parser::ptr_pair(p_productions_list, T_PRODUCTIONS_LIST));
	}else
	{
		p_productions_list->set(dynamic_cast<productions_list_c *>(ptr_stack.back().ptr), p_production);
		ptr_stack.back() = parser::ptr_pair(p_productions_list, T_PRODUCTIONS_LIST);
	}
}

void parser::on_branches_empty()
{
	productions_list_c * p_productions_list = new productions_list_c;
	if(ptr_stack.back().ptr_type != T_PRODUCTIONS_LIST)
	{
		p_productions_list->set(NULL, NULL);
		ptr_stack.push_back(parser::ptr_pair(p_productions_list, T_PRODUCTIONS_LIST));
	}else
	{
		p_productions_list->set(dynamic_cast<productions_list_c *>(ptr_stack.back().ptr), NULL);
		ptr_stack.back() = parser::ptr_pair(p_productions_list, T_PRODUCTIONS_LIST);
	}
}

void parser::on_type_list()
{

}

void parser::on_token()
{
 	string term_name = trim(str_stack.back());
	str_stack.pop_back();
	string usr_type = trim(str_stack.back());
	str_stack.pop_back();
	
	if(usr_type.length() == 0)
	{
		cout<<"***syntax error: %token <> "<<term_name<<", missing usr_type"<<endl;
	}
	tmp_symbol_list.insert_symbol(term_name, symbol_list_item(SYM_TOKEN, usr_type));
}

void parser::on_type()
{
 	string nonterm_name = trim(str_stack.back());
	str_stack.pop_back();
	string usr_type = trim(str_stack.back());
	str_stack.pop_back();
	
	if(usr_type.length() != 0)
	{
		cout<<"***syntax error: %type <"<<usr_type;
		cout<<"> "<<nonterm_name<<", can not has a usr_type"<<endl;
	}
	tmp_symbol_list.insert_symbol(nonterm_name, symbol_list_item(SYM_TYPE, usr_type));
}

void parser::on_rules_id()
{	
	symbol * p_symbol = NULL;
	
	string name = trim(str_stack.back());
	str_stack.pop_back();
	
	int a_cfg_type = tmp_symbol_list.get_symbol_type(name).cfg_type;
	if( a_cfg_type == SYM_TYPE)
	{
		p_symbol = new symbol;
		p_symbol->set(name, a_cfg_type);
		
		production_symb * p_production = new production_symb;
		if(ptr_stack.back().ptr_type != T_PRODUCTION)
		{
			p_production->set(NULL, p_symbol);
			ptr_stack.push_back(parser::ptr_pair(p_production, T_PRODUCTION));
		}else
		{
			p_production->set(dynamic_cast<production *>(ptr_stack.back().ptr), p_symbol);
			ptr_stack.back() = parser::ptr_pair(p_production, T_PRODUCTION);
		}
	}else if(a_cfg_type == SYM_TOKEN)
	{
		p_symbol = new symbol;
		p_symbol->set(name, a_cfg_type);
		
		production_symb * p_production = new production_symb;
		if(ptr_stack.back().ptr_type != T_PRODUCTION)
		{
			p_production->set(NULL, p_symbol);
			ptr_stack.push_back(parser::ptr_pair(p_production, T_PRODUCTION));
		}else
		{
			p_production->set(dynamic_cast<production *>(ptr_stack.back().ptr), p_symbol);
			ptr_stack.back() = parser::ptr_pair(p_production, T_PRODUCTION);
		}
	}else if(a_cfg_type == SYM_STR)
	{
		cout<<"***semantic error: "<<name<<" is not a non-terminal symbol."<<endl;
		assert(0);
	}else
	{
		cout<<"***semantic error: "<<name<<" unknown type."<<endl;
		assert(0);
	}
}


void parser::on_rules_str()
{
	symbol * p_symbol = 	new symbol;
	p_symbol->set(str_stack.back(), SYM_STR);
	str_stack.pop_back();
	production_symb * p_production = new production_symb;
	if(ptr_stack.back().ptr_type != T_PRODUCTION)
	{
		p_production->set(NULL, p_symbol);
		ptr_stack.push_back(parser::ptr_pair(p_production, T_PRODUCTION));
	}else
	{
		p_production->set(dynamic_cast<production *>(ptr_stack.back().ptr), p_symbol);
		ptr_stack.back() = parser::ptr_pair(p_production, T_PRODUCTION);
	}
}

void parser::on_rules_rec_func()
{
	func_place_holder * p_func_place_holder = new func_place_holder;
	int func_index = atoi(str_stack.back().c_str());
	str_stack.pop_back();
	string func_name = str_stack.back();
	str_stack.pop_back();
	
	p_func_place_holder->set(SYM_RECURSIVE, func_name, func_index);
	
	production_func * p_production_func = new production_func;
	if(ptr_stack.back().ptr_type != T_PRODUCTION)
	{
		p_production_func->set(NULL, p_func_place_holder);
		ptr_stack.push_back(parser::ptr_pair(p_production_func, T_PRODUCTION));
	}else
	{
		p_production_func->set(dynamic_cast<production *>(ptr_stack.back().ptr), p_func_place_holder);
		ptr_stack.back() = parser::ptr_pair(p_production_func, T_PRODUCTION);
	}
}

void parser::on_rules_nonrec_func()
{
	func_place_holder * p_func_place_holder = new func_place_holder;
	string func_name = str_stack.back();
	str_stack.pop_back();
	
	p_func_place_holder->set(SYM_NONRECURSIVE, func_name, NONREC_FUNC_INDEX);
	
	production_func * p_production_func = new production_func;
	if(ptr_stack.back().ptr_type != T_PRODUCTION)
	{
		p_production_func->set(NULL, p_func_place_holder);
		ptr_stack.push_back(parser::ptr_pair(p_production_func, T_PRODUCTION));
	}else
	{
		p_production_func->set(dynamic_cast<production *>(ptr_stack.back().ptr), p_func_place_holder);
		ptr_stack.back() = parser::ptr_pair(p_production_func, T_PRODUCTION);
	}
}

void parser::on_func_list()
{
	symbol_base * p_symbol;
	if(ptr_stack.back().ptr_type == T_FUNC_DEL)
	{
		p_symbol = ptr_stack.back().ptr;
		ptr_stack.pop_back();
		
		func_list_del * p_func_list_del = new func_list_del;
		if(ptr_stack.back().ptr_type != T_FUNC_LIST)
		{
			p_func_list_del->set(NULL, dynamic_cast<func_decl *>(p_symbol));
			ptr_stack.push_back(parser::ptr_pair(p_func_list_del, T_FUNC_LIST));
		}else
		{
			p_func_list_del->set(dynamic_cast<func_list *>(ptr_stack.back().ptr), dynamic_cast<func_decl *>(p_symbol));
			ptr_stack.back() = parser::ptr_pair(p_func_list_del, T_FUNC_LIST);
		}
	
	}else if(ptr_stack.back().ptr_type == T_FUNC_DEF)
	{
		p_symbol = ptr_stack.back().ptr;
		ptr_stack.pop_back();
		
		func_list_def * p_func_list_def = new func_list_def;
		if(ptr_stack.back().ptr_type != T_FUNC_LIST)
		{
			p_func_list_def->set(NULL, dynamic_cast<func_def *>(p_symbol));
			ptr_stack.push_back(parser::ptr_pair(p_func_list_def, T_FUNC_LIST));
		}else
		{
			p_func_list_def->set(dynamic_cast<func_list *>(ptr_stack.back().ptr), dynamic_cast<func_def *>(p_symbol));
			ptr_stack.back() = parser::ptr_pair(p_func_list_def, T_FUNC_LIST);
		}
	}else
	{
		cout<<"***internal error: incompatable pointer type in on_func_list()"<<endl;
		assert(0);
	}
	
}

void parser::on_func_decl()
{
	string func_parameter = str_stack.back();
	str_stack.pop_back();
	string func_name = str_stack.back();
	str_stack.pop_back();
	func_id_list_size--;//the func_name has been poped out

	if(func_id_list_size < 1)
	{
		cout<<"***semantic error: missing function name or return value at "<<func_name<<endl;
		assert(0);
	}

	string return_value;
	for (unsigned int i = 0; i < func_id_list_size; i += 1)
	{
		return_value = str_stack.back() + " " + return_value;
		str_stack.pop_back();
	}
	func_decl * p_func_decl = new func_decl;
	p_func_decl->set(tmp_symbol_list.get_symbol_type(func_name).cfg_type, return_value, func_name, func_parameter);
	ptr_stack.push_back(parser::ptr_pair(p_func_decl, T_FUNC_DEL));
}

void parser::on_func_decl_nonrec(unsigned int is_empty_body)
{
	func_body_str * p_func_body_str = NULL;
	string func_str = str_stack.back().c_str();
	str_stack.pop_back();

	string func_parameter = str_stack.back();
	str_stack.pop_back();
	string func_name = str_stack.back();
	str_stack.pop_back();
	func_id_list_size--;//the func_name has been poped out

	if(func_id_list_size < 1)
	{
		cout<<"***semantic error: missing function name or return value at "<<func_name<<endl;
		assert(0);
	}
	
	string return_value;
	for (unsigned int i = 0; i < func_id_list_size; i += 1)
	{
		return_value = str_stack.back() + " " +return_value;
		str_stack.pop_back();
//		return_value += " ";
	}
	int func_type = tmp_symbol_list.get_symbol_type(func_name).cfg_type;

	func_decl * p_func_decl = new func_decl;
	p_func_decl->set(func_type, return_value, func_name, func_parameter);
	
	//func_def
	func_def * p_def = new func_def;

	if(is_empty_body)
	{
		assert(ptr_stack.back().ptr_type != T_FUNC_BODY);
		if(func_str.length() != 0)
		{
			p_func_body_str = new func_body_str;
			p_func_body_str->set(NULL, func_str);
		}
		p_def->set(func_type, func_name, NONREC_FUNC_INDEX, p_func_body_str);
	}else
	{
		assert(ptr_stack.back().ptr_type == T_FUNC_BODY);
		if(func_str.length() != 0)
		{
			p_func_body_str = new func_body_str;
			p_func_body_str->set(dynamic_cast<func_body *>(ptr_stack.back().ptr), func_str);
			p_def->set(func_type, func_name, NONREC_FUNC_INDEX, p_func_body_str);
		}else
		{
			p_def->set(func_type, func_name, NONREC_FUNC_INDEX, dynamic_cast<func_body *>(ptr_stack.back().ptr));
		}
		ptr_stack.pop_back();
	}

	func_list_def * p_func_list_def = new func_list_def;
	if(ptr_stack.back().ptr_type != T_FUNC_LIST)
	{
		p_func_list_def->set(NULL, p_def);
		ptr_stack.push_back(parser::ptr_pair(p_func_list_def, T_FUNC_LIST));
	}else
	{
		p_func_list_def->set(dynamic_cast<func_list *>(ptr_stack.back().ptr), p_def);
		ptr_stack.back() = parser::ptr_pair(p_func_list_def, T_FUNC_LIST);
	}
	//end func_def
	
	ptr_stack.push_back(parser::ptr_pair(p_func_decl, T_FUNC_DEL));//
}

void parser::on_func_id_list(unsigned int need_init)
{
	if(need_init)
	{
		func_id_list_size = 1;
	}else
	{
		func_id_list_size++;
	}
}

void parser::on_func_def_rec(unsigned int is_empty_body)
{
	func_body_str * p_func_body_str = NULL;
	string func_str = str_stack.back().c_str();
	str_stack.pop_back();
	
	int func_index	= atoi(str_stack.back().c_str());
	str_stack.pop_back();
	
	string func_name = str_stack.back();
	str_stack.pop_back();
	
	int func_type = tmp_symbol_list.get_symbol_type(func_name).cfg_type;
	
	func_def * p_def = new func_def;
	if(is_empty_body)
	{
		assert(ptr_stack.back().ptr_type != T_FUNC_BODY);
		if(func_str.length() != 0)
		{
			p_func_body_str = new func_body_str;
			p_func_body_str->set(NULL, func_str);
		}
		p_def->set(func_type, func_name, func_index, p_func_body_str);
		ptr_stack.push_back(parser::ptr_pair(p_def, T_FUNC_DEF));
	}else
	{
		assert(ptr_stack.back().ptr_type == T_FUNC_BODY);
		if(func_str.length() != 0)
		{
			p_func_body_str = new func_body_str;
			p_func_body_str->set(dynamic_cast<func_body *>(ptr_stack.back().ptr), func_str);
			p_def->set(func_type, func_name, func_index, p_func_body_str);
		}else
		{
			p_def->set(func_type, func_name, func_index, dynamic_cast<func_body *>(ptr_stack.back().ptr));
		}
		ptr_stack.back() = parser::ptr_pair(p_def, T_FUNC_DEF);
	}
}

void parser::on_func_def_nonrec(unsigned int is_empty_body)
{
	func_body_str * p_func_body_str = NULL;
	string func_str = str_stack.back().c_str();
	str_stack.pop_back();

	string func_name = str_stack.back();
	str_stack.pop_back();
	
	int func_type = tmp_symbol_list.get_symbol_type(func_name).cfg_type;
	
	func_def * p_def = new func_def;
	if(is_empty_body)
	{
		assert(ptr_stack.back().ptr_type != T_FUNC_BODY);
		if(func_str.length() != 0)
		{
			p_func_body_str = new func_body_str;
			p_func_body_str->set(NULL, func_str);
		}
		p_def->set(func_type, func_name, NONREC_FUNC_INDEX, p_func_body_str);
		ptr_stack.push_back(parser::ptr_pair(p_def, T_FUNC_DEF));
	}else
	{
		assert(ptr_stack.back().ptr_type == T_FUNC_BODY);
		if(func_str.length() != 0)
		{
			p_func_body_str = new func_body_str;
			p_func_body_str->set(dynamic_cast<func_body *>(ptr_stack.back().ptr), func_str);
			p_def->set(func_type, func_name, NONREC_FUNC_INDEX, p_func_body_str);
		}else
		{
			p_def->set(func_type, func_name, NONREC_FUNC_INDEX, dynamic_cast<func_body *>(ptr_stack.back().ptr));
		}
		ptr_stack.back() = parser::ptr_pair(p_def, T_FUNC_DEF);
	}
}

void parser::on_func_body_lsymbol()
{
	func_body_ls * p_ls =	new func_body_ls;
	func_body_str * p_str =	new func_body_str;

	p_ls->set( p_str, LEFT_SYMBOL);
	
	if(ptr_stack.back().ptr_type != T_FUNC_BODY)
	{
		p_str->set(NULL,str_stack.back());
		
		ptr_stack.push_back(parser::ptr_pair(p_ls, T_FUNC_BODY));
	}else
	{
		p_str->set(dynamic_cast<func_body *>(ptr_stack.back().ptr), str_stack.back());
		
		ptr_stack.back() = parser::ptr_pair(p_ls, T_FUNC_BODY);
	}
	str_stack.pop_back();
}

void parser::on_func_body_rsymbol()
{
	func_body_rs * p_rs =	new func_body_rs;
	func_body_str * p_str =	new func_body_str;

	p_rs->set( p_str, atoi((str_stack.back()).substr(1).c_str()) );
	str_stack.pop_back();
	
	if(ptr_stack.back().ptr_type != T_FUNC_BODY)
	{
		p_str->set(NULL,str_stack.back());
		
		ptr_stack.push_back(parser::ptr_pair(p_rs, T_FUNC_BODY));
	}else
	{
		p_str->set(dynamic_cast<func_body *>(ptr_stack.back().ptr), str_stack.back());
		
		ptr_stack.back() = parser::ptr_pair(p_rs, T_FUNC_BODY);
	}
	str_stack.pop_back();
}

void parser::on_function()
{
	string func_name = trim(str_stack.back());
	str_stack.pop_back();
	string func_type = trim(str_stack.back());
	str_stack.pop_back();
	
	if(func_type.length() == 0)
	{
		cout<<"***syntax error: %function <> "<<func_name<<", missing function type"<<endl;
	}
	if(func_type.compare(RECURSIVE_FUNC) == 0)
	{
		tmp_symbol_list.insert_symbol(func_name, symbol_list_item(SYM_RECURSIVE, func_type));
	}else if(func_type.compare(NONRECURSIVE_FUNC) == 0)
	{
		tmp_symbol_list.insert_symbol(func_name, symbol_list_item(SYM_NONRECURSIVE, func_type));
	}else
	{
		cout<<"***syntax error: type of function "<<func_name<<" can only be either " RECURSIVE_FUNC " or" NONRECURSIVE_FUNC<<endl;
	}
}


parser::ptr_pair::ptr_pair(symbol_base * a_ptr, pointer_type_e a_ptr_type):
	ptr(a_ptr), ptr_type(a_ptr_type)
{
}

parser::ptr_pair::~ptr_pair()
{
}

parser::ptr_pair & parser::ptr_pair::operator = (const parser::ptr_pair & a_ptr_pair)
{
	ptr = a_ptr_pair.ptr;
	ptr_type = a_ptr_pair.ptr_type;
	return *this;
}

string parser::trim(const string & a_str)
{
	unsigned int lpos = a_str.find_first_not_of(" \a\b\t\n\v\f\r");
	if(lpos == string::npos)
	{
		return "";
	}
	unsigned int rpos = a_str.find_last_not_of(" \a\b\t\n\v\f\r");
	return a_str.substr(lpos, rpos-lpos+1);
}

#ifdef DEBUG
void parser::print_stacks()
{
	cout<<"------------------------"<<endl;
	cout<<"ptr_stack: (addr , type)"<<endl;
	for (list<parser::ptr_pair>::iterator it = ptr_stack.begin(); it != ptr_stack.end(); it ++)
	{
		cout<<"("<<it->ptr<<" , ";
		switch(it->ptr_type)
		{
			case T_RULE_LIST:
				cout<<"T_RULE_LIST";
			break;
			case T_RULE_DEF:
				cout<<"T_RULE_DEF";
			break;
			case T_PRODUCTIONS_LIST:
				cout<<"T_PRODUCTIONS_LIST";
			break;
			case T_PRODUCTION:
				cout<<"T_PRODUCTION";
			break;
			case T_FUNC_BODY:
				cout<<"T_FUNC_BODY";
			break;
			case T_FUNC_DEF:
				cout<<"T_FUNC_DEF";
			break;
			case T_FUNC_DEL:
				cout<<"T_FUNC_DEL";
			break;
			case T_FUNC_LIST:
				cout<<"T_FUNC_LIST";
			break;
			case T_FUNC_PLACE_HOLDER:
				cout<<"T_FUNC_PLACE_HOLDER";
			break;
			default:
				cout<<"*** internal error: unknown pointer type in prt_stack"<<endl;
				assert(0);
			break;
		}
		cout<<")"<<endl;
	}
	cout<<"----------"<<endl;
	cout<<"str_stack:"<<endl;
	for (list<string>::iterator it = str_stack.begin(); it != str_stack.end(); it ++)
	{
		cout<<": "<<(*it)<<endl;
	}
	cout<<"------------------------"<<endl;
	cout<<endl;
}
#endif

////handle sytax errors
/* void parser::on_rule_missing_colon()
{
	//this syntax error is critical, cannot recover from this kind of error
 	cout<<"***syntax error: missing \":\", near \""<<str_stack.back()<<"\""<<endl;
}

void parser::on_rule_missing_semicolon()
{
	//this syntax error is critical, cannot recover from this kind of error
 	cout<<"***syntax error: missing \";\", near \""<<str_stack.back()<<"\""<<endl;
} */

void parser::on_grammar_reversed()
{
 	cout<<"***syntax error: %type and %token must declared before production rules."<<endl;
	
	////////
	//although error occurred, still try best to continue
	on_grammar();
	////////
}

void parser::on_grammar_missing_rules()
{
	cout<<"***syntax error: missing production rules"<<endl;
}

void parser::on_grammar_missing_types()
{
 	cout<<"***syntax error: missing %type and %token declarations"<<endl;
	
	////////
	//although error occurred, still try best to continue
	on_grammar();
	////////
}
////
/*
void parser::clear_env_on_error()
{
	for (list<parser::ptr_pair>::iterator it = ptr_stack.begin(); it != ptr_stack.end(); it ++)
	{
		delete it->ptr;
	}
	ptr_stack.clear();
	assert(0);
}*/

