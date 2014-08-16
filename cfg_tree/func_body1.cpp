#include "func_body1.h"
#include "cfg_printer_defs.h"
FUNC_BODY1_DERIVED_CPP_USR_DEF
func_body1::func_body1()
{
	m_1 = NULL;
}
func_body1::func_body1(const func_body1 & a_func_body1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_body1.m_1 != NULL)
	{
		m_1 = a_func_body1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_func_body1.m_2;
}
func_body1::~func_body1()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
}
func_body1 & func_body1::operator = (const func_body1 & a_func_body1)
{
	if(this == & a_func_body1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_body1.m_1 != NULL)
	{
		m_1 = a_func_body1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_func_body1.m_2;
	return *this;
}
void func_body1::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<m_2;
}
void func_body1::set(func_body *  a_m_1, const string &  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
func_body1 * func_body1::duplicate()
{
	func_body1 * a_copy = new func_body1;
	if( m_1!= NULL )
	{
		a_copy->m_1 = m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	a_copy->m_2 = m_2;
	return a_copy;
}
void func_body1::visit_this(context & a_context)
{
	if( m_1!= NULL )
	{
		m_1->visit_this(a_context);
	}

	printer_func_def_str * p_printer_func_def_str = new printer_func_def_str;
	
	if(a_context.ptr_stack.back().ptr_type != T_PRINTER_FUNC_DEF)
	{
		p_printer_func_def_str->set(NULL, m_2);
		a_context.ptr_stack.push_back(context::ptr_pair(p_printer_func_def_str, T_PRINTER_FUNC_DEF));
	}else
	{
		p_printer_func_def_str->set(dynamic_cast<printer_func_def *>(a_context.ptr_stack.back().ptr), m_2);
		a_context.ptr_stack.back() = context::ptr_pair(p_printer_func_def_str, T_PRINTER_FUNC_DEF);
	}
}
