#include "func_list_cpp1.h"
FUNC_LIST_CPP1_DERIVED_CPP_USR_DEF
func_list_cpp1::func_list_cpp1()
{
	m_1 = NULL;
	m_6 = NULL;
}
func_list_cpp1::func_list_cpp1(const func_list_cpp1 & a_func_list_cpp1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_list_cpp1.m_1 != NULL)
	{
		m_1 = a_func_list_cpp1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_func_list_cpp1.m_2;
	m_3 = a_func_list_cpp1.m_3;
	m_4 = a_func_list_cpp1.m_4;
	m_5 = a_func_list_cpp1.m_5;
	if( m_6!= NULL )
	{
		delete m_6;
	}
	if(a_func_list_cpp1.m_6 != NULL)
	{
		m_6 = a_func_list_cpp1.m_6->duplicate();
	}else{
		m_6 = NULL;
	}
}
func_list_cpp1::~func_list_cpp1()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if( m_6!= NULL )
	{
		delete m_6;
	}
}
func_list_cpp1 & func_list_cpp1::operator = (const func_list_cpp1 & a_func_list_cpp1)
{
	if(this == & a_func_list_cpp1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_list_cpp1.m_1 != NULL)
	{
		m_1 = a_func_list_cpp1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_func_list_cpp1.m_2;
	m_3 = a_func_list_cpp1.m_3;
	m_4 = a_func_list_cpp1.m_4;
	m_5 = a_func_list_cpp1.m_5;
	if( m_6!= NULL )
	{
		delete m_6;
	}
	if(a_func_list_cpp1.m_6 != NULL)
	{
		m_6 = a_func_list_cpp1.m_6->duplicate();
	}else{
		m_6 = NULL;
	}
	return *this;
}
void func_list_cpp1::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<m_2;
	out<<m_3;
	out<<"::";
	out<<m_4;
	out<<m_5;
	out<<"\n";
	out<<"{\n";
	if( m_6!= NULL )
	{
		m_6->print_this(out);
	}
	out<<"}\n";
}
void func_list_cpp1::set(func_list_cpp *  a_m_1, const string &  a_m_2, const string &  a_m_3, const string &  a_m_4, const string &  a_m_5, recursive_func_def *  a_m_6)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
	m_4 = a_m_4;
	m_5 = a_m_5;
	m_6 = a_m_6;
}
func_list_cpp1 * func_list_cpp1::duplicate()
{
	func_list_cpp1 * a_copy = new func_list_cpp1;
	if( m_1!= NULL )
	{
		a_copy->m_1 = m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	a_copy->m_2 = m_2;
	a_copy->m_3 = m_3;
	a_copy->m_4 = m_4;
	a_copy->m_5 = m_5;
	if( m_6!= NULL )
	{
		a_copy->m_6 = m_6->duplicate();
	}else{
		m_6 = NULL;
	}
	return a_copy;
}
