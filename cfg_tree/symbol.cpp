#include "symbol.h"
#include "cfg_printer_defs.h"
SYMBOL_DERIVED_CPP_USR_DEF
symbol::symbol()
{
}
symbol::symbol(const symbol & a_symbol)
{
	m_1 = a_symbol.m_1;
	m_2 = a_symbol.m_2;
}
symbol::~symbol()
{
}
symbol & symbol::operator = (const symbol & a_symbol)
{
	if(this == & a_symbol)
		return *this;
	m_1 = a_symbol.m_1;
	m_2 = a_symbol.m_2;
	return *this;
}
void symbol::print_this(std::ostream & out)
{
	out<<m_1;
	out<<m_2;
}
void symbol::set(const string &  a_m_1, const int &  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
symbol * symbol::duplicate()
{
	symbol * a_copy = new symbol;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	return a_copy;
}
void symbol::visit_this(context & a_context)
{

	assert(a_context.p_symbol_list != NULL);
	
	std::string class_name = a_context.production_name;
	std::stringstream ss;
	if(a_context.production_counter != 1)//at least 2 productions
	{//if only one production, so the index is not necessary
		ss<<a_context.production_idx;
		class_name += ss.str();
	}
	
	if(m_2 == SYM_TYPE || m_2 == SYM_TOKEN)
	{
		a_context.symbol_idx++;
	}
	unsigned int idx = a_context.symbol_idx;
	
	data_member_inst * p_data_member_inst;
	arg_type_type * p_arg_type_type;
	arg_type_token * p_arg_type_token;
	
	
//	visit_list * p_last_visit_list		= dynamic_cast<visit_list *>(a_context.p_last[VISIT_LIST_IDX]);
	duplicate_list * p_last_duplicate_list	= dynamic_cast<duplicate_list *>(a_context.p_last[DUPLICATE_LIST_IDX]);
	copy_list * p_last_copy_list		= dynamic_cast<copy_list *>(a_context.p_last[COPY_LIST_IDX]);
	deconstruction_list_c * p_last_deconstruction_list_c	= dynamic_cast<deconstruction_list_c *>(a_context.p_last[DECONSTRUCTION_LIST_IDX]);
	construction_list_c * p_last_construction_list_c	= dynamic_cast<construction_list_c *>(a_context.p_last[CONSTRUCTION_LIST_IDX]);
	print_list * p_last_print_list		= dynamic_cast<print_list *>(a_context.p_last[PRINT_LIST_IDX]);
	set_list_c * p_last_set_list_c				= dynamic_cast<set_list_c *>(a_context.p_last[SET_LIST_IDX]);
	include_file_list * p_last_include_file_list	= dynamic_cast<include_file_list *>(a_context.p_last[INCLUDE_FILE_LIST_IDX]);
	set_method_arg_list * p_last_set_method_arg_list	= dynamic_cast<set_method_arg_list *>(a_context.p_last[SET_METHOD_ARG_LIST_IDX]);
	data_member_list * p_last_data_member_list		= dynamic_cast<data_member_list *>(a_context.p_last[DATA_MEMBER_LIST_IDX]);
	
//	visit_list_type * p_visit_list_type		;
	duplicate_list_type * p_duplicate_list_type	;
	copy_list_type * p_copy_list_type		;
	deconstruction_list_c * p_deconstruction_list_c	;
	construction_list_c * p_construction_list_c	;
	print_list_type * p_print_list_type		;
	set_list_c * p_set_list_c			;
	data_member_list_type * p_data_member_list_type	;
	
	set_method_arg_list_first * p_set_method_arg_list_first	;
	set_method_arg_list_other * p_set_method_arg_list_other	;
	
	include_file_list_usr * p_include_file_list_usr	;
	include_file_list_std * p_include_file_list_std	;

	duplicate_list_token * p_duplicate_list_token	;
	copy_list_token * p_copy_list_token		;
//	deconstruction_list_c * p_deconstruction_list_c	;
//	construction_list_c * p_construction_list_c	;
	print_list_token * p_print_list_token		;
//	set_list_c * p_set_list_c			;
//	include_file_list_c * p_include_file_list_c	;
//	set_method_arg_list_c * p_set_method_arg_list_c	;
	data_member_list_token * p_data_member_list_token;
	
	print_list_str * p_print_list_str		;
			
	switch(m_2)
	{
		case SYM_TYPE:
			p_data_member_inst 	= new data_member_inst;
			p_data_member_inst	->set(idx);
			p_arg_type_type		= new arg_type_type;
			p_arg_type_type		->set(m_1);
			
//			p_visit_list_type	= new visit_list_type;
			p_duplicate_list_type	= new duplicate_list_type;
			p_copy_list_type	= new copy_list_type;
			p_deconstruction_list_c	= new deconstruction_list_c;
			p_construction_list_c	= new construction_list_c;
			p_print_list_type	= new print_list_type;
			p_set_list_c		= new set_list_c;
			p_include_file_list_usr	= new include_file_list_usr;
			p_data_member_list_type	= new data_member_list_type;
			
			if(idx == 1)
			{
				p_set_method_arg_list_first = new set_method_arg_list_first;
				p_set_method_arg_list_first->set(p_last_set_method_arg_list, p_arg_type_type, p_data_member_inst->duplicate());
				a_context.p_last[SET_METHOD_ARG_LIST_IDX] =p_set_method_arg_list_first;
			}else
			{
				p_set_method_arg_list_other = new set_method_arg_list_other;
				p_set_method_arg_list_other->set(p_last_set_method_arg_list, p_arg_type_type, p_data_member_inst->duplicate());
				a_context.p_last[SET_METHOD_ARG_LIST_IDX] =p_set_method_arg_list_other;
			}
			
//			p_visit_list_type	->set(p_last_visit_list, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_duplicate_list_type	->set(p_last_duplicate_list, p_data_member_inst->duplicate(), p_data_member_inst->duplicate(), p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_copy_list_type	->set(p_last_copy_list, p_data_member_inst->duplicate(), p_data_member_inst->duplicate(), class_name, p_data_member_inst->duplicate(), p_data_member_inst->duplicate(), class_name, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_deconstruction_list_c	->set(p_last_deconstruction_list_c, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_construction_list_c	->set(p_last_construction_list_c, p_data_member_inst->duplicate());
			p_print_list_type	->set(p_last_print_list, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_set_list_c		->set(p_last_set_list_c, NULL, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_include_file_list_usr	->set(p_last_include_file_list, m_1);
			p_data_member_list_type	->set(p_last_data_member_list, /*(a_context.p_symbol_list->get_symbol_type(name0)).usr_type*/m_1, p_data_member_inst/*->duplicate()*/, m_1);
			
//			a_context.p_last[VISIT_LIST_IDX] =	p_visit_list_type	;
			a_context.p_last[DUPLICATE_LIST_IDX] =	p_duplicate_list_type	;
			a_context.p_last[COPY_LIST_IDX] =	p_copy_list_type	;
			a_context.p_last[DECONSTRUCTION_LIST_IDX] =p_deconstruction_list_c;
			a_context.p_last[CONSTRUCTION_LIST_IDX] =p_construction_list_c	;
			a_context.p_last[PRINT_LIST_IDX] =	p_print_list_type	;
			a_context.p_last[SET_LIST_IDX] =	p_set_list_c		;
			a_context.p_last[INCLUDE_FILE_LIST_IDX] =p_include_file_list_usr;
			a_context.p_last[DATA_MEMBER_LIST_IDX] =p_data_member_list_type	;
		break;
		
		case SYM_TOKEN:
			p_data_member_inst 	= new data_member_inst;
			p_data_member_inst->set(idx);
			p_arg_type_token	= new arg_type_token;
			p_arg_type_token	->set((a_context.p_symbol_list->get_symbol_type(m_1)).usr_type);

			if(!a_context.is_build_in((a_context.p_symbol_list->get_symbol_type(m_1)).usr_type))
			{// not a build in type, need to include a head file
				string a_type = a_context.p_symbol_list->get_symbol_type(m_1).usr_type;
				if(a_context.is_std_type(a_type) != 0)
				{
					p_include_file_list_std	= new include_file_list_std;
					p_include_file_list_std	->set(p_last_include_file_list, a_type);
					a_context.p_last[INCLUDE_FILE_LIST_IDX] =p_include_file_list_std;
				}//else{ user will decide what to include }
			}

			p_duplicate_list_token	= new duplicate_list_token;
			p_copy_list_token	= new copy_list_token;
//			p_deconstruction_list_c	= p_last_deconstruction_list_c;//not used
//			p_construction_list_c	= p_last_construction_list_c;//not used
			p_print_list_token	= new print_list_token;
			p_set_list_c		= new set_list_c;
//			p_set_method_arg_list_c	= new set_method_arg_list_c;
			p_data_member_list_token= new data_member_list_token;
			
			if(idx == 1)
			{
				p_set_method_arg_list_first = new set_method_arg_list_first;
				p_set_method_arg_list_first->set(p_last_set_method_arg_list, p_arg_type_token, p_data_member_inst->duplicate());
				a_context.p_last[SET_METHOD_ARG_LIST_IDX] =p_set_method_arg_list_first;
			}else
			{
				p_set_method_arg_list_other = new set_method_arg_list_other;
				p_set_method_arg_list_other->set(p_last_set_method_arg_list, p_arg_type_token, p_data_member_inst->duplicate());
				a_context.p_last[SET_METHOD_ARG_LIST_IDX] =p_set_method_arg_list_other;
			}
			
			p_duplicate_list_token	->set(p_last_duplicate_list, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_copy_list_token	->set(p_last_copy_list, p_data_member_inst->duplicate(), class_name, p_data_member_inst->duplicate());
//			p_deconstruction_list_c	->set(p_last_deconstruction_c);
//			p_construction_list_c	->set(p_last_construction_c);
			p_print_list_token	->set(p_last_print_list, p_data_member_inst->duplicate());
			p_set_list_c		->set(p_last_set_list_c, NULL, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
//			p_set_method_arg_list_c	->set(p_last_set_method_arg_list, p_arg_type_token, p_data_member_inst->duplicate());
			p_data_member_list_token->set(p_last_data_member_list, (a_context.p_symbol_list->get_symbol_type(m_1)).usr_type, p_data_member_inst/*->duplicate()*/, m_1);
			
			a_context.p_last[DUPLICATE_LIST_IDX] =	p_duplicate_list_token;
			a_context.p_last[COPY_LIST_IDX] =	p_copy_list_token;
//			a_context.p_last[DECONSTRUCTION_LIST_IDX] =p_deconstruction_list_c;
//			a_context.p_last[CONSTRUCTION_LIST_IDX] =p_construction_list_c;
			a_context.p_last[PRINT_LIST_IDX] =	p_print_list_token;
			a_context.p_last[SET_LIST_IDX] =	p_set_list_c;
//			a_context.p_last[INCLUDE_FILE_LIST_IDX] =p_include_file_list_std;//modified
//			a_context.p_last[SET_METHOD_ARG_LIST_IDX] =p_set_method_arg_list_c;
			a_context.p_last[DATA_MEMBER_LIST_IDX] =p_data_member_list_token;
		break;
		
		case SYM_STR:
			p_print_list_str	= new print_list_str;
			p_print_list_str	->set(p_last_print_list, "\""+m_1+"\"");
			a_context.p_last[PRINT_LIST_IDX] = p_print_list_str;
		break;
		
		default://SYM_UNKNOWN
			cout<<"*** internal error: unknown symbol type"<<endl;
			assert(0);
		break;
	}
	
	
	////recusive func def bkn
	if(m_2 == SYM_TYPE)
	{
		bkn_symbol * p_bkn_symbol = new bkn_symbol;
		p_bkn_symbol->set(m_1, m_2, idx);
		
		bkn_production_symb * p_bkn_production_symb = new bkn_production_symb;
		p_bkn_production_symb->set(dynamic_cast<bkn_rule_id *>(a_context.bkn_production_stack.back())->get_bkn_production(), p_bkn_symbol);
		dynamic_cast<bkn_rule_id *>(a_context.bkn_production_stack.back())->m_3 = p_bkn_production_symb;
	}
	////end recusive func def bkn
}
