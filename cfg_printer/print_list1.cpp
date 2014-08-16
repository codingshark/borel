#include "print_list1.h"
PRINT_LIST1_DERIVED_CPP_USR_DEF
print_list1::print_list1()
{
	m_1 = NULL;
	m_2 = NULL;
	m_3 = NULL;
}
print_list1::print_list1(const print_list1 & a_print_list1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_print_list1.m_1 != NULL)
	{
		m_1 = a_print_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_print_list1.m_2 != NULL)
	{
		m_2 = a_print_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_print_list1.m_3 != NULL)
	{
		m_3 = a_print_list1.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
}
print_list1::~print_list1()
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
print_list1 & print_list1::operator = (const print_list1 & a_print_list1)
{
	if(this == & a_print_list1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_print_list1.m_1 != NULL)
	{
		m_1 = a_print_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_print_list1.m_2 != NULL)
	{
		m_2 = a_print_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_print_list1.m_3 != NULL)
	{
		m_3 = a_print_list1.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	return *this;
}
void print_list1::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<"\tif( ";
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
	out<<"!= NULL )\n";
	out<<"\t{\n";
	out<<"\t\t";
	if( m_3!= NULL )
	{
		m_3->print_this(out);
	}
	out<<"->print_this(out);\n";
	out<<"\t}\n";
}
void print_list1::set(print_list *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
}
print_list1 * print_list1::duplicate()
{
	print_list1 * a_copy = new print_list1;
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
