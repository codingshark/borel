#ifndef BKN_PRODUCTION_H_
#define BKN_PRODUCTION_H_
#include <iostream>
#include "rec_func_glb_def.h"
#include "recfunc_context.h"
#include "symbol_base.h"
BKN_PRODUCTION_BASE_H_USR_DEF_1
using namespace std;
class bkn_production :public symbol_base BKN_PRODUCTION_BASE_H_USR_DEF_2
{
	public:
		bkn_production(){};
		bkn_production(const bkn_production & a_bkn_production){}
		virtual ~bkn_production(){};
		virtual bkn_production& operator = (const bkn_production & a_bkn_production){};
		virtual void print_this(std::ostream & out){};
		virtual bkn_production * duplicate(){};
		virtual void visit_this(recfunc_context & a_recfunc_context){};
	BKN_PRODUCTION_BASE_H_USR_DEF_3
};
#endif

