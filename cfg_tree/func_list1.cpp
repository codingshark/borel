#include "func_list1.h"
FUNC_LIST1_DERIVED_CPP_USR_DEF
func_list1::func_list1()
{
	m_1 = NULL;
	m_2 = NULL;
}
func_list1::func_list1(const func_list1 & a_func_list1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_list1.m_1 != NULL)
	{
		m_1 = a_func_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_func_list1.m_2 != NULL)
	{
		m_2 = a_func_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
func_list1::~func_list1()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
}
func_list1 & func_list1::operator = (const func_list1 & a_func_list1)
{
	if(this == & a_func_list1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_list1.m_1 != NULL)
	{
		m_1 = a_func_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_func_list1.m_2 != NULL)
	{
		m_2 = a_func_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void func_list1::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
}
void func_list1::set(func_list *  a_m_1, func_def *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
func_list1 * func_list1::duplicate()
{
	func_list1 * a_copy = new func_list1;
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
	return a_copy;
}
void func_list1::visit_this(context & a_context)
{
	if( m_1!= NULL )
	{
		m_1->visit_this(a_context);
	}
	if( m_2!= NULL )
	{
		m_2->visit_this(a_context);
	}
}
