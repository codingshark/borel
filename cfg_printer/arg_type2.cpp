#include "arg_type2.h"
ARG_TYPE2_DERIVED_CPP_USR_DEF
arg_type2::arg_type2()
{
}
arg_type2::arg_type2(const arg_type2 & a_arg_type2)
{
	m_1 = a_arg_type2.m_1;
}
arg_type2::~arg_type2()
{
}
arg_type2 & arg_type2::operator = (const arg_type2 & a_arg_type2)
{
	if(this == & a_arg_type2)
		return *this;
	m_1 = a_arg_type2.m_1;
	return *this;
}
void arg_type2::print_this(std::ostream & out)
{
	out<<m_1;
	out<<" * ";
}
void arg_type2::set(const string &  a_m_1)
{
	m_1 = a_m_1;
}
arg_type2 * arg_type2::duplicate()
{
	arg_type2 * a_copy = new arg_type2;
	a_copy->m_1 = m_1;
	return a_copy;
}
