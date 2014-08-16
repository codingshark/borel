#include "data_member_inst.h"
DATA_MEMBER_INST_DERIVED_CPP_USR_DEF
data_member_inst::data_member_inst()
{
}
data_member_inst::data_member_inst(const data_member_inst & a_data_member_inst)
{
	m_1 = a_data_member_inst.m_1;
}
data_member_inst::~data_member_inst()
{
}
data_member_inst & data_member_inst::operator = (const data_member_inst & a_data_member_inst)
{
	if(this == & a_data_member_inst)
		return *this;
	m_1 = a_data_member_inst.m_1;
	return *this;
}
void data_member_inst::print_this(std::ostream & out)
{
	out<<"m_";
	out<<m_1;
}
void data_member_inst::set(const unsigned int &  a_m_1)
{
	m_1 = a_m_1;
}
data_member_inst * data_member_inst::duplicate()
{
	data_member_inst * a_copy = new data_member_inst;
	a_copy->m_1 = m_1;
	return a_copy;
}
