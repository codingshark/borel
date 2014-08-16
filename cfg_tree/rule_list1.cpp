#include "rule_list1.h"
RULE_LIST1_DERIVED_CPP_USR_DEF
rule_list1::rule_list1()
{
	m_1 = NULL;
	m_2 = NULL;
}
rule_list1::rule_list1(const rule_list1 & a_rule_list1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_rule_list1.m_1 != NULL)
	{
		m_1 = a_rule_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_rule_list1.m_2 != NULL)
	{
		m_2 = a_rule_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
rule_list1::~rule_list1()
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
rule_list1 & rule_list1::operator = (const rule_list1 & a_rule_list1)
{
	if(this == & a_rule_list1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_rule_list1.m_1 != NULL)
	{
		m_1 = a_rule_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_rule_list1.m_2 != NULL)
	{
		m_2 = a_rule_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void rule_list1::print_this(std::ostream & out)
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
void rule_list1::set(rule_list *  a_m_1, rule_def *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
rule_list1 * rule_list1::duplicate()
{
	rule_list1 * a_copy = new rule_list1;
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
void rule_list1::visit_this(context & a_context)
{
	if( m_1!= NULL )
	{
		m_1->visit_this(a_context);
	}
	if( m_2!= NULL )
	{
		m_2->visit_this(a_context);
	}
}
