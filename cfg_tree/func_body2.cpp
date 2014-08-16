#include "func_body2.h"
#include "cfg_printer_defs.h"
FUNC_BODY2_DERIVED_CPP_USR_DEF
func_body2::func_body2()
{
	m_1 = NULL;
}
func_body2::func_body2(const func_body2 & a_func_body2)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_body2.m_1 != NULL)
	{
		m_1 = a_func_body2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_func_body2.m_2;
}
func_body2::~func_body2()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
}
func_body2 & func_body2::operator = (const func_body2 & a_func_body2)
{
	if(this == & a_func_body2)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_func_body2.m_1 != NULL)
	{
		m_1 = a_func_body2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	m_2 = a_func_body2.m_2;
	return *this;
}
void func_body2::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<m_2;
}
void func_body2::set(func_body *  a_m_1, const int &  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
func_body2 * func_body2::duplicate()
{
	func_body2 * a_copy = new func_body2;
	if( m_1!= NULL )
	{
		a_copy->m_1 = m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	a_copy->m_2 = m_2;
	return a_copy;
}
void func_body2::visit_this(context & a_context)
{
	if( m_1!= NULL )
	{
		m_1->visit_this(a_context);
	}

	data_member_inst * p_data_member_inst = new data_member_inst;
	p_data_member_inst->set(m_2);
	
	printer_func_def_data * p_printer_func_def_data = new printer_func_def_data;
	
	if(a_context.ptr_stack.back().ptr_type != T_PRINTER_FUNC_DEF)
	{
		p_printer_func_def_data->set(NULL, p_data_member_inst);
		a_context.ptr_stack.push_back(context::ptr_pair(p_printer_func_def_data, T_PRINTER_FUNC_DEF));
	}else
	{
		p_printer_func_def_data->set(dynamic_cast<printer_func_def *>(a_context.ptr_stack.back().ptr), p_data_member_inst);
		a_context.ptr_stack.back() = context::ptr_pair(p_printer_func_def_data, T_PRINTER_FUNC_DEF);
	}
}
