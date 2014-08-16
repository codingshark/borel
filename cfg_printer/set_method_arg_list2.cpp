#include "set_method_arg_list2.h"
SET_METHOD_ARG_LIST2_DERIVED_CPP_USR_DEF
set_method_arg_list2::set_method_arg_list2()
{
	m_1 = NULL;
	m_2 = NULL;
	m_3 = NULL;
}
set_method_arg_list2::set_method_arg_list2(const set_method_arg_list2 & a_set_method_arg_list2)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_set_method_arg_list2.m_1 != NULL)
	{
		m_1 = a_set_method_arg_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_set_method_arg_list2.m_2 != NULL)
	{
		m_2 = a_set_method_arg_list2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_set_method_arg_list2.m_3 != NULL)
	{
		m_3 = a_set_method_arg_list2.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
}
set_method_arg_list2::~set_method_arg_list2()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
}
set_method_arg_list2 & set_method_arg_list2::operator = (const set_method_arg_list2 & a_set_method_arg_list2)
{
	if(this == & a_set_method_arg_list2)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_set_method_arg_list2.m_1 != NULL)
	{
		m_1 = a_set_method_arg_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_set_method_arg_list2.m_2 != NULL)
	{
		m_2 = a_set_method_arg_list2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_set_method_arg_list2.m_3 != NULL)
	{
		m_3 = a_set_method_arg_list2.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	return *this;
}
void set_method_arg_list2::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
	out<<" a_";
	if( m_3!= NULL )
	{
		m_3->print_this(out);
	}
}
void set_method_arg_list2::set(set_method_arg_list *  a_m_1, arg_type *  a_m_2, data_member_inst *  a_m_3)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
}
set_method_arg_list2 * set_method_arg_list2::duplicate()
{
	set_method_arg_list2 * a_copy = new set_method_arg_list2;
	if( m_1!= NULL )
	{
		a_copy->m_1 = m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		a_copy->m_2 = m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		a_copy->m_3 = m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	return a_copy;
}
