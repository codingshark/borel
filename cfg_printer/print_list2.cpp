#include "print_list2.h"
PRINT_LIST2_DERIVED_CPP_USR_DEF
print_list2::print_list2()
{
	m_1 = NULL;
	m_2 = NULL;
}
print_list2::print_list2(const print_list2 & a_print_list2)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_print_list2.m_1 != NULL)
	{
		m_1 = a_print_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_print_list2.m_2 != NULL)
	{
		m_2 = a_print_list2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
print_list2::~print_list2()
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
print_list2 & print_list2::operator = (const print_list2 & a_print_list2)
{
	if(this == & a_print_list2)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_print_list2.m_1 != NULL)
	{
		m_1 = a_print_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_print_list2.m_2 != NULL)
	{
		m_2 = a_print_list2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void print_list2::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<"\tout<<";
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
	out<<";\n";
}
void print_list2::set(print_list *  a_m_1, data_member_inst *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
print_list2 * print_list2::duplicate()
{
	print_list2 * a_copy = new print_list2;
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
