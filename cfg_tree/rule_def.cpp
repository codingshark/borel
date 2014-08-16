#include "rule_def.h"
#include "cfg_printer_defs.h"
#include <algorithm>
RULE_DEF_DERIVED_CPP_USR_DEF
rule_def::rule_def()
{
	m_2 = NULL;
}
rule_def::rule_def(const rule_def & a_rule_def)
{
	m_1 = a_rule_def.m_1;
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_rule_def.m_2 != NULL)
	{
		m_2 = a_rule_def.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
rule_def::~rule_def()
{
	if( m_2!= NULL )
	{
		delete m_2;
	}
}
rule_def & rule_def::operator = (const rule_def & a_rule_def)
{
	if(this == & a_rule_def)
		return *this;
	m_1 = a_rule_def.m_1;
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_rule_def.m_2 != NULL)
	{
		m_2 = a_rule_def.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void rule_def::print_this(std::ostream & out)
{
	out<<m_1;
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
}
void rule_def::set(const string &  a_m_1, productions_list *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
rule_def * rule_def::duplicate()
{
	rule_def * a_copy = new rule_def;
	a_copy->m_1 = m_1;
	if( m_2!= NULL )
	{
		a_copy->m_2 = m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return a_copy;
}
void rule_def::visit_this(context & a_context)
{

	a_context.production_name = m_1;
	a_context.production_idx = 0;
	a_context.production_counter = 0;
	if( m_2!= NULL )
	{
		m_2->visit_this(a_context);
	}

	if(a_context.production_counter == 0 || a_context.production_counter > 1)
	{//a base class is necessary
		std::string class_name = m_1;
		std::string name_upper = class_name;
		stringstream ss;
		ss<<GLOBAL_DEF_H "_"<<&a_context;
		transform(name_upper.begin(), name_upper.end(), name_upper.begin(), ::toupper);
		
		print_base_h * p_print_base_h = new print_base_h;
		p_print_base_h->set(
					name_upper,
					name_upper,
					ss.str(),
					BASE_CLASS,
					name_upper,
					class_name,
					BASE_CLASS,
					name_upper,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					NULL,//recursive_func_del_list
					name_upper
					);
		a_context.for_print.push_back(name_n_ptr(class_name+".h", p_print_base_h));
		a_context.incomplete_rec_func_decl_list_base.push_back(p_print_base_h);
		
		////def file
		a_context.name_list.push_back(name_n_idx(class_name, DEF_BASE));
		////end def file
	}
}
