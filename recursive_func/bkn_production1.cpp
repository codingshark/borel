#include "bkn_production1.h"
BKN_PRODUCTION1_DERIVED_CPP_USR_DEF
bkn_production1::bkn_production1()
{
	m_1 = NULL;
	m_2 = NULL;
}
bkn_production1::bkn_production1(const bkn_production1 & a_bkn_production1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_bkn_production1.m_1 != NULL)
	{
		m_1 = a_bkn_production1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_bkn_production1.m_2 != NULL)
	{
		m_2 = a_bkn_production1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
bkn_production1::~bkn_production1()
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
bkn_production1 & bkn_production1::operator = (const bkn_production1 & a_bkn_production1)
{
	if(this == & a_bkn_production1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_bkn_production1.m_1 != NULL)
	{
		m_1 = a_bkn_production1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_bkn_production1.m_2 != NULL)
	{
		m_2 = a_bkn_production1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void bkn_production1::print_this(std::ostream & out)
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
void bkn_production1::set(bkn_production *  a_m_1, bkn_symbol *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
bkn_production1 * bkn_production1::duplicate()
{
	bkn_production1 * a_copy = new bkn_production1;
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
void bkn_production1::visit_this(recfunc_context & a_recfunc_context)
{
	if( m_1!= NULL )
	{
		m_1->visit_this(a_recfunc_context);
	}
	if( m_2!= NULL )
	{
		m_2->visit_this(a_recfunc_context);
	}
}
