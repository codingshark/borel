#ifndef BKN_SYMBOL_H_
#define BKN_SYMBOL_H_
#include "rec_func_glb_def.h"
#include "recfunc_context.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
BKN_SYMBOL_DERIVED_H_USR_DEF_1
using namespace std;
class bkn_symbol :public symbol_base BKN_SYMBOL_DERIVED_H_USR_DEF_2
{
	public:
		bkn_symbol();
		bkn_symbol(const bkn_symbol & a_bkn_symbol);
		virtual ~bkn_symbol();
		bkn_symbol& operator = (const bkn_symbol & a_bkn_symbol);
		void set(const string &  a_m_1, const int &  a_m_2, const int &  a_m_3);
		void print_this(std::ostream & out);
		bkn_symbol * duplicate();
		virtual void visit_this(recfunc_context & a_recfunc_context);
	public:
		string	m_1;	// name
		int	m_2;	// cfg_type
		int	m_3;	// symb_idx
	BKN_SYMBOL_DERIVED_H_USR_DEF_3
};
#endif

