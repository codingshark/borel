#include "copy_list1.h"
COPY_LIST1_DERIVED_CPP_USR_DEF
copy_list1::copy_list1()
{
	m_1 = NULL;
	m_2 = NULL;
	m_4 = NULL;
}
copy_list1::copy_list1(const copy_list1 & a_copy_list1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_copy_list1.m_1 != NULL)
	{
		m_1 = a_copy_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_copy_list1.m_2 != NULL)
	{
		m_2 = a_copy_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	m_3 = a_copy_list1.m_3;
	if( m_4!= NULL )
	{
		delete m_4;
	}
	if(a_copy_list1.m_4 != NULL)
	{
		m_4 = a_copy_list1.m_4->duplicate();
	}else{
		m_4 = NULL;
	}
}
copy_list1::~copy_list1()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if( m_4!= NULL )
	{
		delete m_4;
	}
}
copy_list1 & copy_list1::operator = (const copy_list1 & a_copy_list1)
{
	if(this == & a_copy_list1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_copy_list1.m_1 != NULL)
	{
		m_1 = a_copy_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_copy_list1.m_2 != NULL)
	{
		m_2 = a_copy_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	m_3 = a_copy_list1.m_3;
	if( m_4!= NULL )
	{
		delete m_4;
	}
	if(a_copy_list1.m_4 != NULL)
	{
		m_4 = a_copy_list1.m_4->duplicate();
	}else{
		m_4 = NULL;
	}
	return *this;
}
void copy_list1::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<"\t";
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
	out<<" = a_";
	out<<m_3;
	out<<".";
	if( m_4!= NULL )
	{
		m_4->print_this(out);
	}
	out<<";\n";
}
void copy_list1::set(copy_list *  a_m_1, data_member_inst *  a_m_2, const string &  a_m_3, data_member_inst *  a_m_4)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
	m_4 = a_m_4;
}
copy_list1 * copy_list1::duplicate()
{
	copy_list1 * a_copy = new copy_list1;
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
	a_copy->m_3 = m_3;
	if( m_4!= NULL )
	{
		a_copy->m_4 = m_4->duplicate();
	}else{
		m_4 = NULL;
	}
	return a_copy;
}
