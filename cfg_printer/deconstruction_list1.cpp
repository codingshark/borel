#include "deconstruction_list1.h"
DECONSTRUCTION_LIST1_DERIVED_CPP_USR_DEF
deconstruction_list1::deconstruction_list1()
{
	m_1 = NULL;
	m_2 = NULL;
	m_3 = NULL;
}
deconstruction_list1::deconstruction_list1(const deconstruction_list1 & a_deconstruction_list1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_deconstruction_list1.m_1 != NULL)
	{
		m_1 = a_deconstruction_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_deconstruction_list1.m_2 != NULL)
	{
		m_2 = a_deconstruction_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_deconstruction_list1.m_3 != NULL)
	{
		m_3 = a_deconstruction_list1.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
}
deconstruction_list1::~deconstruction_list1()
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
deconstruction_list1 & deconstruction_list1::operator = (const deconstruction_list1 & a_deconstruction_list1)
{
	if(this == & a_deconstruction_list1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_deconstruction_list1.m_1 != NULL)
	{
		m_1 = a_deconstruction_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_deconstruction_list1.m_2 != NULL)
	{
		m_2 = a_deconstruction_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_deconstruction_list1.m_3 != NULL)
	{
		m_3 = a_deconstruction_list1.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	return *this;
}
void deconstruction_list1::print_this(std::ostream & out)
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
	out<<"\t\tdelete ";
	if( m_3!= NULL )
	{
		m_3->print_this(out);
	}
	out<<";\n";
	out<<"\t}\n";
}
void deconstruction_list1::set(deconstruction_list *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
}
deconstruction_list1 * deconstruction_list1::duplicate()
{
	deconstruction_list1 * a_copy = new deconstruction_list1;
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
