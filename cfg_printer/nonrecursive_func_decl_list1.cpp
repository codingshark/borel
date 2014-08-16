#include "nonrecursive_func_decl_list1.h"
NONRECURSIVE_FUNC_DECL_LIST1_DERIVED_CPP_USR_DEF
nonrecursive_func_decl_list1::nonrecursive_func_decl_list1()
{
	m_1 = NULL;
	m_2 = NULL;
}
nonrecursive_func_decl_list1::nonrecursive_func_decl_list1(const nonrecursive_func_decl_list1 & a_nonrecursive_func_decl_list1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_nonrecursive_func_decl_list1.m_1 != NULL)
	{
		m_1 = a_nonrecursive_func_decl_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_nonrecursive_func_decl_list1.m_2 != NULL)
	{
		m_2 = a_nonrecursive_func_decl_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
nonrecursive_func_decl_list1::~nonrecursive_func_decl_list1()
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
nonrecursive_func_decl_list1 & nonrecursive_func_decl_list1::operator = (const nonrecursive_func_decl_list1 & a_nonrecursive_func_decl_list1)
{
	if(this == & a_nonrecursive_func_decl_list1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_nonrecursive_func_decl_list1.m_1 != NULL)
	{
		m_1 = a_nonrecursive_func_decl_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_nonrecursive_func_decl_list1.m_2 != NULL)
	{
		m_2 = a_nonrecursive_func_decl_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void nonrecursive_func_decl_list1::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<"\t\t";
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
	out<<";\n";
}
void nonrecursive_func_decl_list1::set(nonrecursive_func_decl_list *  a_m_1, printer_func_decl *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
nonrecursive_func_decl_list1 * nonrecursive_func_decl_list1::duplicate()
{
	nonrecursive_func_decl_list1 * a_copy = new nonrecursive_func_decl_list1;
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
