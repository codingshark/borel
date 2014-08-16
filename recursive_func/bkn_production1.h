#ifndef BKN_PRODUCTION1_H_
#define BKN_PRODUCTION1_H_
#include "rec_func_glb_def.h"
#include "recfunc_context.h"
#include "symbol_base.h"
#include <iostream>
#include "bkn_production.h"
#include "bkn_symbol.h"
#include "bkn_production.h"
BKN_PRODUCTION1_DERIVED_H_USR_DEF_1
using namespace std;
class bkn_production1 :public bkn_production BKN_PRODUCTION1_DERIVED_H_USR_DEF_2
{
	public:
		bkn_production1();
		bkn_production1(const bkn_production1 & a_bkn_production1);
		virtual ~bkn_production1();
		bkn_production1& operator = (const bkn_production1 & a_bkn_production1);
		void set(bkn_production *  a_m_1, bkn_symbol *  a_m_2);
		void print_this(std::ostream & out);
		bkn_production1 * duplicate();
		virtual void visit_this(recfunc_context & a_recfunc_context);
	public:
		bkn_production *	m_1;	// bkn_production
		bkn_symbol *	m_2;	// bkn_symbol
	BKN_PRODUCTION1_DERIVED_H_USR_DEF_3
};
#endif

