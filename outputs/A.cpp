#include "A.h"
A_DERIVED_CPP_USR_DEF
A::A()
{
}
A::A(const A & a_A)
{
	m_1 = a_A.m_1;
	m_2 = a_A.m_2;
}
A::~A()
{
}
A & A::operator = (const A & a_A)
{
	if(this == & a_A)
		return *this;
	m_1 = a_A.m_1;
	m_2 = a_A.m_2;
	return *this;
}
void A::print_this(std::ostream & out)
{
	out<<m_1;
	out<<m_2;
}
void A::set(int &  a_m_1, int &  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
A * A::duplicate()
{
	A * a_copy = new A;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	return a_copy;
}
int [ 7584798 ] int < double > * & A::visit()
{

	return m_1;
}
void * A::func()
{

	return NULL;
}
