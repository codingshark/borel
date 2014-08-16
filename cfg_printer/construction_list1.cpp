#include "construction_list1.h"
CONSTRUCTION_LIST1_DERIVED_CPP_USR_DEF
construction_list1::construction_list1()
{
	m_1 = NULL;
	m_2 = NULL;
}
construction_list1::construction_list1(const construction_list1 & a_construction_list1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_construction_list1.m_1 != NULL)
	{
		m_1 = a_construction_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_construction_list1.m_2 != NULL)
	{
		m_2 = a_construction_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
construction_list1::~construction_list1()
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
construction_list1 & construction_list1::operator = (const construction_list1 & a_construction_list1)
{
	if(this == & a_construction_list1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_construction_list1.m_1 != NULL)
	{
		m_1 = a_construction_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_construction_list1.m_2 != NULL)
	{
		m_2 = a_construction_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void construction_list1::print_this(std::ostream & out)
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
	out<<" = NULL;\n";
}
void construction_list1::set(construction_list *  a_m_1, data_member_inst *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
construction_list1 * construction_list1::duplicate()
{
	construction_list1 * a_copy = new construction_list1;
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
