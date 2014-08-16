#ifndef PRODUCTION1_H_
#define PRODUCTION1_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include "production.h"
#include "symbol.h"
#include "production.h"
PRODUCTION1_DERIVED_H_USR_DEF_1
using namespace std;
class production1 :public production PRODUCTION1_DERIVED_H_USR_DEF_2
{
	public:
		production1();
		production1(const production1 & a_production1);
		virtual ~production1();
		production1& operator = (const production1 & a_production1);
		void set(production *  a_m_1, symbol *  a_m_2);
		void print_this(std::ostream & out);
		production1 * duplicate();
		virtual void visit_this(context & a_context);
	public:
		production *	m_1;	// production
		symbol *	m_2;	// symbol
	PRODUCTION1_DERIVED_H_USR_DEF_3
};
#endif

