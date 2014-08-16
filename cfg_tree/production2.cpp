#include "production2.h"
PRODUCTION2_DERIVED_CPP_USR_DEF
production2::production2()
{
	m_1 = NULL;
	m_2 = NULL;
}
production2::production2(const production2 & a_production2)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_production2.m_1 != NULL)
	{
		m_1 = a_production2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_production2.m_2 != NULL)
	{
		m_2 = a_production2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
production2::~production2()
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
production2 & production2::operator = (const production2 & a_production2)
{
	if(this == & a_production2)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_production2.m_1 != NULL)
	{
		m_1 = a_production2.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_production2.m_2 != NULL)
	{
		m_2 = a_production2.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void production2::print_this(std::ostream & out)
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
void production2::set(production *  a_m_1, func_place_holder *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
production2 * production2::duplicate()
{
	production2 * a_copy = new production2;
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
void production2::visit_this(context & a_context)
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
