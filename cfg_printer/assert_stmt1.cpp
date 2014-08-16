#include "assert_stmt1.h"
ASSERT_STMT1_DERIVED_CPP_USR_DEF
assert_stmt1::assert_stmt1()
{
	m_1 = NULL;
}
assert_stmt1::assert_stmt1(const assert_stmt1 & a_assert_stmt1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_assert_stmt1.m_1 != NULL)
	{
		m_1 = a_assert_stmt1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
}
assert_stmt1::~assert_stmt1()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
}
assert_stmt1 & assert_stmt1::operator = (const assert_stmt1 & a_assert_stmt1)
{
	if(this == & a_assert_stmt1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_assert_stmt1.m_1 != NULL)
	{
		m_1 = a_assert_stmt1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	return *this;
}
void assert_stmt1::print_this(std::ostream & out)
{
	out<<"\tassert( a_";
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	out<<" != NULL);\n";
}
void assert_stmt1::set(data_member_inst *  a_m_1)
{
	m_1 = a_m_1;
}
assert_stmt1 * assert_stmt1::duplicate()
{
	assert_stmt1 * a_copy = new assert_stmt1;
	if( m_1!= NULL )
	{
		a_copy->m_1 = m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	return a_copy;
}
