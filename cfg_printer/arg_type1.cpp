#include "arg_type1.h"
ARG_TYPE1_DERIVED_CPP_USR_DEF
arg_type1::arg_type1()
{
}
arg_type1::arg_type1(const arg_type1 & a_arg_type1)
{
	m_1 = a_arg_type1.m_1;
}
arg_type1::~arg_type1()
{
}
arg_type1 & arg_type1::operator = (const arg_type1 & a_arg_type1)
{
	if(this == & a_arg_type1)
		return *this;
	m_1 = a_arg_type1.m_1;
	return *this;
}
void arg_type1::print_this(std::ostream & out)
{
	out<<m_1;
	out<<" & ";
}
void arg_type1::set(const string &  a_m_1)
{
	m_1 = a_m_1;
}
arg_type1 * arg_type1::duplicate()
{
	arg_type1 * a_copy = new arg_type1;
	a_copy->m_1 = m_1;
	return a_copy;
}
