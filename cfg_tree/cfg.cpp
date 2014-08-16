#include "cfg.h"
#include "cfg_printer_defs.h"
CFG_DERIVED_CPP_USR_DEF
cfg::cfg()
{
	m_3 = NULL;
	m_4 = NULL;
}
cfg::cfg(const cfg & a_cfg)
{
	m_1 = a_cfg.m_1;
	m_2 = a_cfg.m_2;
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_cfg.m_3 != NULL)
	{
		m_3 = a_cfg.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	if( m_4!= NULL )
	{
		delete m_4;
	}
	if(a_cfg.m_4 != NULL)
	{
		m_4 = a_cfg.m_4->duplicate();
	}else{
		m_4 = NULL;
	}
}
cfg::~cfg()
{
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if( m_4!= NULL )
	{
		delete m_4;
	}
}
cfg & cfg::operator = (const cfg & a_cfg)
{
	if(this == & a_cfg)
		return *this;
	m_1 = a_cfg.m_1;
	m_2 = a_cfg.m_2;
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_cfg.m_3 != NULL)
	{
		m_3 = a_cfg.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	if( m_4!= NULL )
	{
		delete m_4;
	}
	if(a_cfg.m_4 != NULL)
	{
		m_4 = a_cfg.m_4->duplicate();
	}else{
		m_4 = NULL;
	}
	return *this;
}
void cfg::print_this(std::ostream & out)
{
	out<<m_1;
	out<<m_2;
	if( m_3!= NULL )
	{
		m_3->print_this(out);
	}
	if( m_4!= NULL )
	{
		m_4->print_this(out);
	}
}
void cfg::set(const string &  a_m_1, const symbol_list &  a_m_2, rule_list *  a_m_3, func_list *  a_m_4)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
	m_4 = a_m_4;
}
cfg * cfg::duplicate()
{
	cfg * a_copy = new cfg;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	if( m_3!= NULL )
	{
		a_copy->m_3 = m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	if( m_4!= NULL )
	{
		a_copy->m_4 = m_4->duplicate();
	}else{
		m_4 = NULL;
	}
	return a_copy;
}
void cfg::visit_this(context & a_context)
{

	a_context.p_symbol_list = & m_2;
	if( m_3!= NULL )
	{
		m_3->visit_this(a_context);
	}
	if( m_4!= NULL )
	{
		m_4->visit_this(a_context);
	}

	for (std::list<name_n_ptr>::iterator it = a_context.func_declarations.begin(); 
		it != a_context.func_declarations.end(); it ++)
	{
		if(m_2.get_symbol_type(it->name).cfg_type == SYM_RECURSIVE)
		{
			//recursive function declarations
			for (std::list<symbol_base *>::iterator jt = a_context.incomplete_rec_func_decl_list_base.begin()
					; jt != a_context.incomplete_rec_func_decl_list_base.end(); jt ++)
			{
				recursive_func_decl_list_base_c * p_recursive_func_decl_list_base = 
								new recursive_func_decl_list_base_c;
				p_recursive_func_decl_list_base->set(
					dynamic_cast<print_base_h *>(*jt)->obj_rfunc_decl_list_base, 
					dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->duplicate() );
				dynamic_cast<print_base_h *>(*jt)->obj_rfunc_decl_list_base = p_recursive_func_decl_list_base;
			}
			for (std::list<symbol_base *>::iterator jt = a_context.incomplete_rec_func_decl_list_derived.begin()
					; jt != a_context.incomplete_rec_func_decl_list_derived.end(); jt ++)
			{
				recursive_func_decl_list_derived_c * p_recursive_func_decl_list_derived = 
									new recursive_func_decl_list_derived_c;
									
				p_recursive_func_decl_list_derived->set(
					dynamic_cast<print_derived_h *>(*jt)->obj_rfunc_decl_list_derived, 
					dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->duplicate() );
				dynamic_cast<print_derived_h *>(*jt)->obj_rfunc_decl_list_derived = p_recursive_func_decl_list_derived;
			}
			//
			
			///recursive function definition
			string	production_name;
			int	production_idx;
			string	func_class_name;
			string	func_return_value = dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->get_return_value();
			string	func_parameter = dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->get_func_parameter();

			bkn_production * production_ptr;
			recfunc_context a_recfunc_context(a_context.func_name_idx2def);
			
			a_recfunc_context.func_name = it->name;
			for (std::list<symbol_base *>::iterator pt = a_context.bkn_production_stack.begin(); 
					pt != a_context.bkn_production_stack.end(); pt ++)
			{
				production_name	= dynamic_cast<bkn_rule_id *>(*pt)->get_rule_name();
				production_idx	= dynamic_cast<bkn_rule_id *>(*pt)->get_rule_idx();
				production_ptr	= dynamic_cast<bkn_rule_id *>(*pt)->get_bkn_production();
				std::map<long int, symbol_base *>::iterator mt = a_context.incomplete_func_list_cpp.
					find(name_n_idx::hash_code(production_name, production_idx) );
				if(mt != a_context.incomplete_func_list_cpp.end())
				{
					dynamic_cast<bkn_rule_id *>(*pt)->visit_this(a_recfunc_context);
					
					func_class_name = dynamic_cast<print_derived_cpp *>(mt->second)->get_class_name();//class name
					
					func_list_cpp_rec * p_func_list_cpp_rec = new func_list_cpp_rec;
					p_func_list_cpp_rec->set(
						dynamic_cast<print_derived_cpp *>(mt->second)->obj_func_list,
						func_return_value,
						func_class_name,
						it->name,
						func_parameter,
						dynamic_cast<recursive_func_def *>(a_recfunc_context.p_func_def)
								);
					//install data
					dynamic_cast<print_derived_cpp *>(mt->second)->obj_func_list = p_func_list_cpp_rec;
				}//else
				//{
					//bug: cout<<"*** internal error: production(name, idx) to pointer mapping failed"<<endl;
					//bug: assert(0);
					//this might be caused by empty production
					//ex.
					// A: b | ;
				//}
			}
			///end recursive function definition
		}else if(m_2.get_symbol_type(it->name).cfg_type == SYM_NONRECURSIVE)
		{
			std::map<string, name_n_idx>::iterator kt = a_context.nonrecfunc2prodction.find(it->name);
			//given a nonrecursive function and find the corresponding production
			if(kt != a_context.nonrecfunc2prodction.end()) 
			{
				///func declararion for class head file
				std::map<long int, symbol_base *>::iterator mt = a_context.incomplete_nonrec_func_decl_list.
					find(name_n_idx::hash_code((kt->second).name, (kt->second).idx) );
				//find the pointer to incomplete print_derived_h
				if(mt != a_context.incomplete_nonrec_func_decl_list.end())
				{
					
					nonrecursive_func_decl_list_c * p_nonrecursive_func_decl_list_c = new nonrecursive_func_decl_list_c;
					p_nonrecursive_func_decl_list_c->set(
						dynamic_cast<print_derived_h *>(mt->second)->obj_nonrfunc_decl_list,
						dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->duplicate() );
					dynamic_cast<print_derived_h *>(mt->second)->obj_nonrfunc_decl_list = p_nonrecursive_func_decl_list_c;
					
				}else
				{
					cout<<"*** internal error: production to pointer mapping failed"<<endl;
					assert(0);
				}
				///end decl
				
				///func_list for print_derived_cpp
				mt = a_context.incomplete_func_list_cpp.
					find(name_n_idx::hash_code((kt->second).name, (kt->second).idx) );
				if(mt != a_context.incomplete_func_list_cpp.end())
				{
					
					std::map<string, symbol_base *>::iterator it_func_body = a_context.nonrec_func2func_body.find(it->name);
					if(it_func_body == a_context.nonrec_func2func_body.end())
					{
						cout<<"*** semantic error: function "<<it->name<<" has not been defined"<<endl;
						assert(0);
					}
					
					func_list_cpp_nonrec * p_func_list_cpp_nonrec = new func_list_cpp_nonrec;
					p_func_list_cpp_nonrec->set(
						dynamic_cast<print_derived_cpp *>(mt->second)->obj_func_list,
						dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->get_return_value(),//return value
						dynamic_cast<print_derived_cpp *>(mt->second)->get_class_name(),//class name
						dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->get_func_name(),//func name
						dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->get_func_parameter(),//func parameter
						dynamic_cast<printer_func_def *>(it_func_body->second)//->duplicate()///printer_func_def
									);
					dynamic_cast<print_derived_cpp *>(mt->second)->obj_func_list = p_func_list_cpp_nonrec;
					
				}else
				{
					cout<<"*** internal error: production to pointer mapping failed"<<endl;
					assert(0);
				}
				///end func_list
			}else
			{
				cout<<"*** internal error: noncrecursive function to production mapping failed"<<endl;
				assert(0);
			}
		}
	}
}
