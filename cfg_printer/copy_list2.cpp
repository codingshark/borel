#include "copy_list2.h"
COPY_LIST2_DERIVED_CPP_USR_DEF
copy_list2::copy_list2()
{
	m_1 = NULL;
	m_2 = NULL;
	m_3 = NULL;
	m_5 = NULL;
	m_6 = NULL;
	m_8 = NULL;
	m_9 = NULL;
}
copy_list2::copy_list2(const copy_list2 & a_copy_list2)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_copy_list2.m_1 != NULL)
	{
		m_1 = a_copy_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_copy_list2.m_2 != NULL)
	{
		m_2 = a_copy_list2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_copy_list2.m_3 != NULL)
	{
		m_3 = a_copy_list2.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	m_4 = a_copy_list2.m_4;
	if( m_5!= NULL )
	{
		delete m_5;
	}
	if(a_copy_list2.m_5 != NULL)
	{
		m_5 = a_copy_list2.m_5->duplicate();
	}else{
		m_5 = NULL;
	}
	if( m_6!= NULL )
	{
		delete m_6;
	}
	if(a_copy_list2.m_6 != NULL)
	{
		m_6 = a_copy_list2.m_6->duplicate();
	}else{
		m_6 = NULL;
	}
	m_7 = a_copy_list2.m_7;
	if( m_8!= NULL )
	{
		delete m_8;
	}
	if(a_copy_list2.m_8 != NULL)
	{
		m_8 = a_copy_list2.m_8->duplicate();
	}else{
		m_8 = NULL;
	}
	if( m_9!= NULL )
	{
		delete m_9;
	}
	if(a_copy_list2.m_9 != NULL)
	{
		m_9 = a_copy_list2.m_9->duplicate();
	}else{
		m_9 = NULL;
	}
}
copy_list2::~copy_list2()
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
	if( m_5!= NULL )
	{
		delete m_5;
	}
	if( m_6!= NULL )
	{
		delete m_6;
	}
	if( m_8!= NULL )
	{
		delete m_8;
	}
	if( m_9!= NULL )
	{
		delete m_9;
	}
}
copy_list2 & copy_list2::operator = (const copy_list2 & a_copy_list2)
{
	if(this == & a_copy_list2)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_copy_list2.m_1 != NULL)
	{
		m_1 = a_copy_list2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_copy_list2.m_2 != NULL)
	{
		m_2 = a_copy_list2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_copy_list2.m_3 != NULL)
	{
		m_3 = a_copy_list2.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	m_4 = a_copy_list2.m_4;
	if( m_5!= NULL )
	{
		delete m_5;
	}
	if(a_copy_list2.m_5 != NULL)
	{
		m_5 = a_copy_list2.m_5->duplicate();
	}else{
		m_5 = NULL;
	}
	if( m_6!= NULL )
	{
		delete m_6;
	}
	if(a_copy_list2.m_6 != NULL)
	{
		m_6 = a_copy_list2.m_6->duplicate();
	}else{
		m_6 = NULL;
	}
	m_7 = a_copy_list2.m_7;
	if( m_8!= NULL )
	{
		delete m_8;
	}
	if(a_copy_list2.m_8 != NULL)
	{
		m_8 = a_copy_list2.m_8->duplicate();
	}else{
		m_8 = NULL;
	}
	if( m_9!= NULL )
	{
		delete m_9;
	}
	if(a_copy_list2.m_9 != NULL)
	{
		m_9 = a_copy_list2.m_9->duplicate();
	}else{
		m_9 = NULL;
	}
	return *this;
}
void copy_list2::print_this(std::ostream & out)
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
	out<<"\tif(a_";
	out<<m_4;
	out<<".";
	if( m_5!= NULL )
	{
		m_5->print_this(out);
	}
	out<<" != NULL)\n";
	out<<"\t{\n";
	out<<"\t\t";
	if( m_6!= NULL )
	{
		m_6->print_this(out);
	}
	out<<" = a_";
	out<<m_7;
	out<<".";
	if( m_8!= NULL )
	{
		m_8->print_this(out);
	}
	out<<"->duplicate();\n";
	out<<"\t}else{\n";
	out<<"\t\t";
	if( m_9!= NULL )
	{
		m_9->print_this(out);
	}
	out<<" = NULL;\n";
	out<<"\t}\n";
}
void copy_list2::set(copy_list *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3, const string &  a_m_4, data_member_inst *  a_m_5, data_member_inst *  a_m_6, const string &  a_m_7, data_member_inst *  a_m_8, data_member_inst *  a_m_9)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
	m_4 = a_m_4;
	m_5 = a_m_5;
	m_6 = a_m_6;
	m_7 = a_m_7;
	m_8 = a_m_8;
	m_9 = a_m_9;
}
copy_list2 * copy_list2::duplicate()
{
	copy_list2 * a_copy = new copy_list2;
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
	a_copy->m_4 = m_4;
	if( m_5!= NULL )
	{
		a_copy->m_5 = m_5->duplicate();
	}else{
		m_5 = NULL;
	}
	if( m_6!= NULL )
	{
		a_copy->m_6 = m_6->duplicate();
	}else{
		m_6 = NULL;
	}
	a_copy->m_7 = m_7;
	if( m_8!= NULL )
	{
		a_copy->m_8 = m_8->duplicate();
	}else{
		m_8 = NULL;
	}
	if( m_9!= NULL )
	{
		a_copy->m_9 = m_9->duplicate();
	}else{
		m_9 = NULL;
	}
	return a_copy;
}
