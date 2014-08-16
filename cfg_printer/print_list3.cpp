#include "print_list3.h"
PRINT_LIST3_DERIVED_CPP_USR_DEF
print_list3::print_list3()
{
	m_1 = NULL;
}
print_list3::print_list3(const print_list3 & a_print_list3)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_print_list3.m_1 != NULL)
	{
		m_1 = a_print_list3.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_print_list3.m_2;
}
print_list3::~print_list3()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
}
print_list3 & print_list3::operator = (const print_list3 & a_print_list3)
{
	if(this == & a_print_list3)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_print_list3.m_1 != NULL)
	{
		m_1 = a_print_list3.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_print_list3.m_2;
	return *this;
}
void print_list3::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<"\tout<<";
	out<<m_2;
	out<<";\n";
}
void print_list3::set(print_list *  a_m_1, const string &  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
print_list3 * print_list3::duplicate()
{
	print_list3 * a_copy = new print_list3;
	if( m_1!= NULL )
	{
		a_copy->m_1 = m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	a_copy->m_2 = m_2;
	return a_copy;
}
