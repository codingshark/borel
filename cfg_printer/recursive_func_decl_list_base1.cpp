#include "recursive_func_decl_list_base1.h"
RECURSIVE_FUNC_DECL_LIST_BASE1_DERIVED_CPP_USR_DEF
recursive_func_decl_list_base1::recursive_func_decl_list_base1()
{
	m_1 = NULL;
	m_2 = NULL;
}
recursive_func_decl_list_base1::recursive_func_decl_list_base1(const recursive_func_decl_list_base1 & a_recursive_func_decl_list_base1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_recursive_func_decl_list_base1.m_1 != NULL)
	{
		m_1 = a_recursive_func_decl_list_base1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_recursive_func_decl_list_base1.m_2 != NULL)
	{
		m_2 = a_recursive_func_decl_list_base1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
recursive_func_decl_list_base1::~recursive_func_decl_list_base1()
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
recursive_func_decl_list_base1 & recursive_func_decl_list_base1::operator = (const recursive_func_decl_list_base1 & a_recursive_func_decl_list_base1)
{
	if(this == & a_recursive_func_decl_list_base1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_recursive_func_decl_list_base1.m_1 != NULL)
	{
		m_1 = a_recursive_func_decl_list_base1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_recursive_func_decl_list_base1.m_2 != NULL)
	{
		m_2 = a_recursive_func_decl_list_base1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void recursive_func_decl_list_base1::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<"\t\tvirtual ";
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
	out<<"{};\n";
}
void recursive_func_decl_list_base1::set(recursive_func_decl_list_base *  a_m_1, printer_func_decl *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
recursive_func_decl_list_base1 * recursive_func_decl_list_base1::duplicate()
{
	recursive_func_decl_list_base1 * a_copy = new recursive_func_decl_list_base1;
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
