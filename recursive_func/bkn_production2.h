#ifndef BKN_PRODUCTION2_H_
#define BKN_PRODUCTION2_H_
#include "rec_func_glb_def.h"
#include "recfunc_context.h"
#include "symbol_base.h"
#include <iostream>
#include "bkn_production.h"
#include "bkn_func_place_holder.h"
#include "bkn_production.h"
BKN_PRODUCTION2_DERIVED_H_USR_DEF_1
using namespace std;
class bkn_production2 :public bkn_production BKN_PRODUCTION2_DERIVED_H_USR_DEF_2
{
	public:
		bkn_production2();
		bkn_production2(const bkn_production2 & a_bkn_production2);
		virtual ~bkn_production2();
		bkn_production2& operator = (const bkn_production2 & a_bkn_production2);
		void set(bkn_production *  a_m_1, bkn_func_place_holder *  a_m_2);
		void print_this(std::ostream & out);
		bkn_production2 * duplicate();
		virtual void visit_this(recfunc_context & a_recfunc_context);
	public:
		bkn_production *	m_1;	// bkn_production
		bkn_func_place_holder *	m_2;	// bkn_func_place_holder
	BKN_PRODUCTION2_DERIVED_H_USR_DEF_3
};
#endif

