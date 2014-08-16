#include "bkn_rule_id.h"
BKN_RULE_ID_DERIVED_CPP_USR_DEF
bkn_rule_id::bkn_rule_id()
{
	m_3 = NULL;
}
bkn_rule_id::bkn_rule_id(const bkn_rule_id & a_bkn_rule_id)
{
	m_1 = a_bkn_rule_id.m_1;
	m_2 = a_bkn_rule_id.m_2;
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_bkn_rule_id.m_3 != NULL)
	{
		m_3 = a_bkn_rule_id.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
}
bkn_rule_id::~bkn_rule_id()
{
	if( m_3!= NULL )
	{
		delete m_3;
	}
}
bkn_rule_id & bkn_rule_id::operator = (const bkn_rule_id & a_bkn_rule_id)
{
	if(this == & a_bkn_rule_id)
		return *this;
	m_1 = a_bkn_rule_id.m_1;
	m_2 = a_bkn_rule_id.m_2;
	if( m_3!= NULL )
	{
		delete m_3;
	}
	if(a_bkn_rule_id.m_3 != NULL)
	{
		m_3 = a_bkn_rule_id.m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	return *this;
}
void bkn_rule_id::print_this(std::ostream & out)
{
	out<<m_1;
	out<<m_2;
	if( m_3!= NULL )
	{
		m_3->print_this(out);
	}
}
void bkn_rule_id::set(const string &  a_m_1, const int &  a_m_2, bkn_production *  a_m_3)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
}
bkn_rule_id * bkn_rule_id::duplicate()
{
	bkn_rule_id * a_copy = new bkn_rule_id;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	if( m_3!= NULL )
	{
		a_copy->m_3 = m_3->duplicate();
	}else{
		m_3 = NULL;
	}
	return a_copy;
}
string bkn_rule_id::get_rule_name()
{

	return m_1;
}
int bkn_rule_id::get_rule_idx()
{

	return m_2;
}
bkn_production * bkn_rule_id::get_bkn_production()
{

	return m_3;
}
void bkn_rule_id::visit_this(recfunc_context & a_recfunc_context)
{

	a_recfunc_context.p_func_def = NULL;
	if( m_3!= NULL )
	{
		m_3->visit_this(a_recfunc_context);
	}
}
