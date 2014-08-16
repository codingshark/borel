#include "include_file_list1.h"
INCLUDE_FILE_LIST1_DERIVED_CPP_USR_DEF
include_file_list1::include_file_list1()
{
	m_1 = NULL;
}
include_file_list1::include_file_list1(const include_file_list1 & a_include_file_list1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_include_file_list1.m_1 != NULL)
	{
		m_1 = a_include_file_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_include_file_list1.m_2;
}
include_file_list1::~include_file_list1()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
}
include_file_list1 & include_file_list1::operator = (const include_file_list1 & a_include_file_list1)
{
	if(this == & a_include_file_list1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_include_file_list1.m_1 != NULL)
	{
		m_1 = a_include_file_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_include_file_list1.m_2;
	return *this;
}
void include_file_list1::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<"#include \"";
	out<<m_2;
	out<<".h\"\n";
}
void include_file_list1::set(include_file_list *  a_m_1, const string &  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
include_file_list1 * include_file_list1::duplicate()
{
	include_file_list1 * a_copy = new include_file_list1;
	if( m_1!= NULL )
	{
		a_copy->m_1 = m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	a_copy->m_2 = m_2;
	return a_copy;
}
