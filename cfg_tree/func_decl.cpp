#include "func_decl.h"
#include "cfg_printer_defs.h"
FUNC_DECL_DERIVED_CPP_USR_DEF
func_decl::func_decl()
{
}
func_decl::func_decl(const func_decl & a_func_decl)
{
	m_1 = a_func_decl.m_1;
	m_2 = a_func_decl.m_2;
	m_3 = a_func_decl.m_3;
	m_4 = a_func_decl.m_4;
}
func_decl::~func_decl()
{
}
func_decl & func_decl::operator = (const func_decl & a_func_decl)
{
	if(this == & a_func_decl)
		return *this;
	m_1 = a_func_decl.m_1;
	m_2 = a_func_decl.m_2;
	m_3 = a_func_decl.m_3;
	m_4 = a_func_decl.m_4;
	return *this;
}
void func_decl::print_this(std::ostream & out)
{
	out<<m_1;
	out<<m_2;
	out<<m_3;
	out<<m_4;
}
void func_decl::set(const int &  a_m_1, const string &  a_m_2, const string &  a_m_3, const string &  a_m_4)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
	m_4 = a_m_4;
}
func_decl * func_decl::duplicate()
{
	func_decl * a_copy = new func_decl;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	a_copy->m_3 = m_3;
	a_copy->m_4 = m_4;
	return a_copy;
}
void func_decl::visit_this(context & a_context)
{

	printer_func_decl * p_printer_func_decl = new printer_func_decl;
	p_printer_func_decl->set(m_2, m_3, m_4);
	a_context.func_declarations.push_back(name_n_ptr(m_3, p_printer_func_decl));
}
