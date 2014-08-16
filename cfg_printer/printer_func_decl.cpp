#include "printer_func_decl.h"
PRINTER_FUNC_DECL_DERIVED_CPP_USR_DEF
printer_func_decl::printer_func_decl()
{
}
printer_func_decl::printer_func_decl(const printer_func_decl & a_printer_func_decl)
{
	m_1 = a_printer_func_decl.m_1;
	m_2 = a_printer_func_decl.m_2;
	m_3 = a_printer_func_decl.m_3;
}
printer_func_decl::~printer_func_decl()
{
}
printer_func_decl & printer_func_decl::operator = (const printer_func_decl & a_printer_func_decl)
{
	if(this == & a_printer_func_decl)
		return *this;
	m_1 = a_printer_func_decl.m_1;
	m_2 = a_printer_func_decl.m_2;
	m_3 = a_printer_func_decl.m_3;
	return *this;
}
void printer_func_decl::print_this(std::ostream & out)
{
	out<<m_1;
	out<<m_2;
	out<<m_3;
}
void printer_func_decl::set(const string &  a_m_1, const string &  a_m_2, const string &  a_m_3)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
}
printer_func_decl * printer_func_decl::duplicate()
{
	printer_func_decl * a_copy = new printer_func_decl;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	a_copy->m_3 = m_3;
	return a_copy;
}
string printer_func_decl::get_return_value()
{

	return m_1;
}
string printer_func_decl::get_func_name()
{

	return m_2;
}
string printer_func_decl::get_func_parameter()
{

	return m_3;
}
