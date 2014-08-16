#ifndef PRODUCTION2_H_
#define PRODUCTION2_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include "production.h"
#include "func_place_holder.h"
#include "production.h"
PRODUCTION2_DERIVED_H_USR_DEF_1
using namespace std;
class production2 :public production PRODUCTION2_DERIVED_H_USR_DEF_2
{
	public:
		production2();
		production2(const production2 & a_production2);
		virtual ~production2();
		production2& operator = (const production2 & a_production2);
		void set(production *  a_m_1, func_place_holder *  a_m_2);
		void print_this(std::ostream & out);
		production2 * duplicate();
		virtual void visit_this(context & a_context);
	public:
		production *	m_1;	// production
		func_place_holder *	m_2;	// func_place_holder
	PRODUCTION2_DERIVED_H_USR_DEF_3
};
#endif

