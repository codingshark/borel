#include "duplicate_list1.h"
DUPLICATE_LIST1_DERIVED_CPP_USR_DEF
duplicate_list1::duplicate_list1()
{
	m_1 = NULL;
	m_2 = NULL;
	m_3 = NULL;
	m_4 = NULL;
	m_5 = NULL;
}
duplicate_list1::duplicate_list1(const duplicate_list1 & a_duplicate_list1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_duplicate_list1.m_1 != NULL)
	{
		m_1 = a_duplicate_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_duplicate_list1.m_2 != NULL)
	{
		m_2 = a_duplicate_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_duplicate_list1.m_3 != NULL)
	{
		m_3 = a_duplicate_list1.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	if( m_4!= NULL )
	{
		delete m_4;
	}
	if(a_duplicate_list1.m_4 != NULL)
	{
		m_4 = a_duplicate_list1.m_4->duplicate();
	}else{
		m_4 = NULL;
	}
	if( m_5!= NULL )
	{
		delete m_5;
	}
	if(a_duplicate_list1.m_5 != NULL)
	{
		m_5 = a_duplicate_list1.m_5->duplicate();
	}else{
		m_5 = NULL;
	}
}
duplicate_list1::~duplicate_list1()
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
	if( m_5!= NULL )
	{
		delete m_5;
	}
}
duplicate_list1 & duplicate_list1::operator = (const duplicate_list1 & a_duplicate_list1)
{
	if(this == & a_duplicate_list1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_duplicate_list1.m_1 != NULL)
	{
		m_1 = a_duplicate_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_duplicate_list1.m_2 != NULL)
	{
		m_2 = a_duplicate_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_duplicate_list1.m_3 != NULL)
	{
		m_3 = a_duplicate_list1.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	if( m_4!= NULL )
	{
		delete m_4;
	}
	if(a_duplicate_list1.m_4 != NULL)
	{
		m_4 = a_duplicate_list1.m_4->duplicate();
	}else{
		m_4 = NULL;
	}
	if( m_5!= NULL )
	{
		delete m_5;
	}
	if(a_duplicate_list1.m_5 != NULL)
	{
		m_5 = a_duplicate_list1.m_5->duplicate();
	}else{
		m_5 = NULL;
	}
	return *this;
}
void duplicate_list1::print_this(std::ostream & out)
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
	out<<"\t\ta_copy->";
	if( m_3!= NULL )
	{
		m_3->print_this(out);
	}
	out<<" = ";
	if( m_4!= NULL )
	{
		m_4->print_this(out);
	}
	out<<"->duplicate();\n";
	out<<"\t}else{\n";
	out<<"\t\t";
	if( m_5!= NULL )
	{
		m_5->print_this(out);
	}
	out<<" = NULL;\n";
	out<<"\t}\n";
}
void duplicate_list1::set(duplicate_list *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3, data_member_inst *  a_m_4, data_member_inst *  a_m_5)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
	m_4 = a_m_4;
	m_5 = a_m_5;
}
duplicate_list1 * duplicate_list1::duplicate()
{
	duplicate_list1 * a_copy = new duplicate_list1;
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
	if( m_5!= NULL )
	{
		a_copy->m_5 = m_5->duplicate();
	}else{
		m_5 = NULL;
	}
	return a_copy;
}
