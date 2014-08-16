#include "recursive_func_def2.h"
RECURSIVE_FUNC_DEF2_DERIVED_CPP_USR_DEF
recursive_func_def2::recursive_func_def2()
{
	m_1 = NULL;
	m_2 = NULL;
}
recursive_func_def2::recursive_func_def2(const recursive_func_def2 & a_recursive_func_def2)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_recursive_func_def2.m_1 != NULL)
	{
		m_1 = a_recursive_func_def2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_recursive_func_def2.m_2 != NULL)
	{
		m_2 = a_recursive_func_def2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
recursive_func_def2::~recursive_func_def2()
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
recursive_func_def2 & recursive_func_def2::operator = (const recursive_func_def2 & a_recursive_func_def2)
{
	if(this == & a_recursive_func_def2)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_recursive_func_def2.m_1 != NULL)
	{
		m_1 = a_recursive_func_def2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_recursive_func_def2.m_2 != NULL)
	{
		m_2 = a_recursive_func_def2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void recursive_func_def2::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
}
void recursive_func_def2::set(recursive_func_def *  a_m_1, printer_func_def *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
recursive_func_def2 * recursive_func_def2::duplicate()
{
	recursive_func_def2 * a_copy = new recursive_func_def2;
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
