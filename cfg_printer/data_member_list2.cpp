#include "data_member_list2.h"
DATA_MEMBER_LIST2_DERIVED_CPP_USR_DEF
data_member_list2::data_member_list2()
{
	m_1 = NULL;
	m_3 = NULL;
}
data_member_list2::data_member_list2(const data_member_list2 & a_data_member_list2)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_data_member_list2.m_1 != NULL)
	{
		m_1 = a_data_member_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_data_member_list2.m_2;
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_data_member_list2.m_3 != NULL)
	{
		m_3 = a_data_member_list2.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	m_4 = a_data_member_list2.m_4;
}
data_member_list2::~data_member_list2()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
}
data_member_list2 & data_member_list2::operator = (const data_member_list2 & a_data_member_list2)
{
	if(this == & a_data_member_list2)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_data_member_list2.m_1 != NULL)
	{
		m_1 = a_data_member_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_data_member_list2.m_2;
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_data_member_list2.m_3 != NULL)
	{
		m_3 = a_data_member_list2.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	m_4 = a_data_member_list2.m_4;
	return *this;
}
void data_member_list2::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<"\t\t";
	out<<m_2;
	out<<" *\t";
	if( m_3!= NULL )
	{
		m_3->print_this(out);
	}
	out<<";\t// ";
	out<<m_4;
	out<<"\n";
}
void data_member_list2::set(data_member_list *  a_m_1, const string &  a_m_2, data_member_inst *  a_m_3, const string &  a_m_4)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
	m_4 = a_m_4;
}
data_member_list2 * data_member_list2::duplicate()
{
	data_member_list2 * a_copy = new data_member_list2;
	if( m_1!= NULL )
	{
		a_copy->m_1 = m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	a_copy->m_2 = m_2;
	if( m_3!= NULL )
	{
		a_copy->m_3 = m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	a_copy->m_4 = m_4;
	return a_copy;
}
