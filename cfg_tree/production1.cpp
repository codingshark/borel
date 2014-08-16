#include "production1.h"
PRODUCTION1_DERIVED_CPP_USR_DEF
production1::production1()
{
	m_1 = NULL;
	m_2 = NULL;
}
production1::production1(const production1 & a_production1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_production1.m_1 != NULL)
	{
		m_1 = a_production1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_production1.m_2 != NULL)
	{
		m_2 = a_production1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
production1::~production1()
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
production1 & production1::operator = (const production1 & a_production1)
{
	if(this == & a_production1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_production1.m_1 != NULL)
	{
		m_1 = a_production1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_production1.m_2 != NULL)
	{
		m_2 = a_production1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void production1::print_this(std::ostream & out)
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
void production1::set(production *  a_m_1, symbol *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
production1 * production1::duplicate()
{
	production1 * a_copy = new production1;
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
void production1::visit_this(context & a_context)
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
