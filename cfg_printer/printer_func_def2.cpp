#include "printer_func_def2.h"
PRINTER_FUNC_DEF2_DERIVED_CPP_USR_DEF
printer_func_def2::printer_func_def2()
{
	m_1 = NULL;
	m_2 = NULL;
}
printer_func_def2::printer_func_def2(const printer_func_def2 & a_printer_func_def2)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_printer_func_def2.m_1 != NULL)
	{
		m_1 = a_printer_func_def2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_printer_func_def2.m_2 != NULL)
	{
		m_2 = a_printer_func_def2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
printer_func_def2::~printer_func_def2()
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
printer_func_def2 & printer_func_def2::operator = (const printer_func_def2 & a_printer_func_def2)
{
	if(this == & a_printer_func_def2)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_printer_func_def2.m_1 != NULL)
	{
		m_1 = a_printer_func_def2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_printer_func_def2.m_2 != NULL)
	{
		m_2 = a_printer_func_def2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void printer_func_def2::print_this(std::ostream & out)
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
void printer_func_def2::set(printer_func_def *  a_m_1, data_member_inst *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
printer_func_def2 * printer_func_def2::duplicate()
{
	printer_func_def2 * a_copy = new printer_func_def2;
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
