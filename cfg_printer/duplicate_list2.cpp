#include "duplicate_list2.h"
DUPLICATE_LIST2_DERIVED_CPP_USR_DEF
duplicate_list2::duplicate_list2()
{
	m_1 = NULL;
	m_2 = NULL;
	m_3 = NULL;
}
duplicate_list2::duplicate_list2(const duplicate_list2 & a_duplicate_list2)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_duplicate_list2.m_1 != NULL)
	{
		m_1 = a_duplicate_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_duplicate_list2.m_2 != NULL)
	{
		m_2 = a_duplicate_list2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_duplicate_list2.m_3 != NULL)
	{
		m_3 = a_duplicate_list2.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
}
duplicate_list2::~duplicate_list2()
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
duplicate_list2 & duplicate_list2::operator = (const duplicate_list2 & a_duplicate_list2)
{
	if(this == & a_duplicate_list2)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_duplicate_list2.m_1 != NULL)
	{
		m_1 = a_duplicate_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_duplicate_list2.m_2 != NULL)
	{
		m_2 = a_duplicate_list2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_duplicate_list2.m_3 != NULL)
	{
		m_3 = a_duplicate_list2.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	return *this;
}
void duplicate_list2::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<"\ta_copy->";
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
	out<<" = ";
	if( m_3!= NULL )
	{
		m_3->print_this(out);
	}
	out<<";\n";
}
void duplicate_list2::set(duplicate_list *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
}
duplicate_list2 * duplicate_list2::duplicate()
{
	duplicate_list2 * a_copy = new duplicate_list2;
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
