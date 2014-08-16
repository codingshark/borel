#include "set_list1.h"
SET_LIST1_DERIVED_CPP_USR_DEF
set_list1::set_list1()
{
	m_1 = NULL;
	m_2 = NULL;
	m_3 = NULL;
	m_4 = NULL;
}
set_list1::set_list1(const set_list1 & a_set_list1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_set_list1.m_1 != NULL)
	{
		m_1 = a_set_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_set_list1.m_2 != NULL)
	{
		m_2 = a_set_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_set_list1.m_3 != NULL)
	{
		m_3 = a_set_list1.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	if( m_4!= NULL )
	{
		delete m_4;
	}
	if(a_set_list1.m_4 != NULL)
	{
		m_4 = a_set_list1.m_4->duplicate();
	}else{
		m_4 = NULL;
	}
}
set_list1::~set_list1()
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
	if( m_4!= NULL )
	{
		delete m_4;
	}
}
set_list1 & set_list1::operator = (const set_list1 & a_set_list1)
{
	if(this == & a_set_list1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_set_list1.m_1 != NULL)
	{
		m_1 = a_set_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_set_list1.m_2 != NULL)
	{
		m_2 = a_set_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_set_list1.m_3 != NULL)
	{
		m_3 = a_set_list1.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	if( m_4!= NULL )
	{
		delete m_4;
	}
	if(a_set_list1.m_4 != NULL)
	{
		m_4 = a_set_list1.m_4->duplicate();
	}else{
		m_4 = NULL;
	}
	return *this;
}
void set_list1::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
	out<<"\t";
	if( m_3!= NULL )
	{
		m_3->print_this(out);
	}
	out<<" = a_";
	if( m_4!= NULL )
	{
		m_4->print_this(out);
	}
	out<<";\n";
}
void set_list1::set(set_list *  a_m_1, assert_stmt *  a_m_2, data_member_inst *  a_m_3, data_member_inst *  a_m_4)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
	m_4 = a_m_4;
}
set_list1 * set_list1::duplicate()
{
	set_list1 * a_copy = new set_list1;
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
	if( m_4!= NULL )
	{
		a_copy->m_4 = m_4->duplicate();
	}else{
		m_4 = NULL;
	}
	return a_copy;
}
