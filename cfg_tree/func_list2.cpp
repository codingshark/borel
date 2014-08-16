#include "func_list2.h"
FUNC_LIST2_DERIVED_CPP_USR_DEF
func_list2::func_list2()
{
	m_1 = NULL;
	m_2 = NULL;
}
func_list2::func_list2(const func_list2 & a_func_list2)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_list2.m_1 != NULL)
	{
		m_1 = a_func_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_func_list2.m_2 != NULL)
	{
		m_2 = a_func_list2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
func_list2::~func_list2()
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
func_list2 & func_list2::operator = (const func_list2 & a_func_list2)
{
	if(this == & a_func_list2)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_list2.m_1 != NULL)
	{
		m_1 = a_func_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_func_list2.m_2 != NULL)
	{
		m_2 = a_func_list2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void func_list2::print_this(std::ostream & out)
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
void func_list2::set(func_list *  a_m_1, func_decl *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
func_list2 * func_list2::duplicate()
{
	func_list2 * a_copy = new func_list2;
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
void func_list2::visit_this(context & a_context)
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
