#include "recursive_func_def1.h"
RECURSIVE_FUNC_DEF1_DERIVED_CPP_USR_DEF
recursive_func_def1::recursive_func_def1()
{
	m_1 = NULL;
	m_2 = NULL;
	m_3 = NULL;
}
recursive_func_def1::recursive_func_def1(const recursive_func_def1 & a_recursive_func_def1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_recursive_func_def1.m_1 != NULL)
	{
		m_1 = a_recursive_func_def1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_recursive_func_def1.m_2 != NULL)
	{
		m_2 = a_recursive_func_def1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_recursive_func_def1.m_3 != NULL)
	{
		m_3 = a_recursive_func_def1.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	m_4 = a_recursive_func_def1.m_4;
	m_5 = a_recursive_func_def1.m_5;
}
recursive_func_def1::~recursive_func_def1()
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
recursive_func_def1 & recursive_func_def1::operator = (const recursive_func_def1 & a_recursive_func_def1)
{
	if(this == & a_recursive_func_def1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_recursive_func_def1.m_1 != NULL)
	{
		m_1 = a_recursive_func_def1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_recursive_func_def1.m_2 != NULL)
	{
		m_2 = a_recursive_func_def1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_recursive_func_def1.m_3 != NULL)
	{
		m_3 = a_recursive_func_def1.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	m_4 = a_recursive_func_def1.m_4;
	m_5 = a_recursive_func_def1.m_5;
	return *this;
}
void recursive_func_def1::print_this(std::ostream & out)
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
	out<<"->";
	out<<m_4;
	out<<m_5;
	out<<";\n";
	out<<"\t}\n";
}
void recursive_func_def1::set(recursive_func_def *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3, const string &  a_m_4, const string &  a_m_5)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
	m_4 = a_m_4;
	m_5 = a_m_5;
}
recursive_func_def1 * recursive_func_def1::duplicate()
{
	recursive_func_def1 * a_copy = new recursive_func_def1;
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
	a_copy->m_5 = m_5;
	return a_copy;
}
