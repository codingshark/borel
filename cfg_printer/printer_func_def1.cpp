#include "printer_func_def1.h"
PRINTER_FUNC_DEF1_DERIVED_CPP_USR_DEF
printer_func_def1::printer_func_def1()
{
	m_1 = NULL;
}
printer_func_def1::printer_func_def1(const printer_func_def1 & a_printer_func_def1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_printer_func_def1.m_1 != NULL)
	{
		m_1 = a_printer_func_def1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_printer_func_def1.m_2;
}
printer_func_def1::~printer_func_def1()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
}
printer_func_def1 & printer_func_def1::operator = (const printer_func_def1 & a_printer_func_def1)
{
	if(this == & a_printer_func_def1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_printer_func_def1.m_1 != NULL)
	{
		m_1 = a_printer_func_def1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_printer_func_def1.m_2;
	return *this;
}
void printer_func_def1::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<m_2;
}
void printer_func_def1::set(printer_func_def *  a_m_1, const string &  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
printer_func_def1 * printer_func_def1::duplicate()
{
	printer_func_def1 * a_copy = new printer_func_def1;
	if( m_1!= NULL )
	{
		a_copy->m_1 = m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	a_copy->m_2 = m_2;
	return a_copy;
}
