#include "func_body3.h"
FUNC_BODY3_DERIVED_CPP_USR_DEF
func_body3::func_body3()
{
	m_1 = NULL;
}
func_body3::func_body3(const func_body3 & a_func_body3)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_body3.m_1 != NULL)
	{
		m_1 = a_func_body3.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_func_body3.m_2;
}
func_body3::~func_body3()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
}
func_body3 & func_body3::operator = (const func_body3 & a_func_body3)
{
	if(this == & a_func_body3)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_body3.m_1 != NULL)
	{
		m_1 = a_func_body3.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_func_body3.m_2;
	return *this;
}
void func_body3::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<m_2;
}
void func_body3::set(func_body *  a_m_1, const int &  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
func_body3 * func_body3::duplicate()
{
	func_body3 * a_copy = new func_body3;
	if( m_1!= NULL )
	{
		a_copy->m_1 = m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	a_copy->m_2 = m_2;
	return a_copy;
}
void func_body3::visit_this(context & a_context)
{
	if( m_1!= NULL )
	{
		m_1->visit_this(a_context);
	}

	cout<<"***warning: left symbol is not supported in this version"<<endl;
}
