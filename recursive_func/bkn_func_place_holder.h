#ifndef BKN_FUNC_PLACE_HOLDER_H_
#define BKN_FUNC_PLACE_HOLDER_H_
#include "rec_func_glb_def.h"
#include "recfunc_context.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
BKN_FUNC_PLACE_HOLDER_DERIVED_H_USR_DEF_1
using namespace std;
class bkn_func_place_holder :public symbol_base BKN_FUNC_PLACE_HOLDER_DERIVED_H_USR_DEF_2
{
	public:
		bkn_func_place_holder();
		bkn_func_place_holder(const bkn_func_place_holder & a_bkn_func_place_holder);
		virtual ~bkn_func_place_holder();
		bkn_func_place_holder& operator = (const bkn_func_place_holder & a_bkn_func_place_holder);
		void set(const string &  a_m_1, const int &  a_m_2);
		void print_this(std::ostream & out);
		bkn_func_place_holder * duplicate();
		virtual void visit_this(recfunc_context & a_recfunc_context);
	public:
		string	m_1;	// func_name
		int	m_2;	// func_index
	BKN_FUNC_PLACE_HOLDER_DERIVED_H_USR_DEF_3
};
#endif

