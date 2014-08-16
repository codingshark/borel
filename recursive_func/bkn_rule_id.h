#ifndef BKN_RULE_ID_H_
#define BKN_RULE_ID_H_
#include "rec_func_glb_def.h"
#include "recfunc_context.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
#include "bkn_production.h"
BKN_RULE_ID_DERIVED_H_USR_DEF_1
using namespace std;
class bkn_rule_id :public symbol_base BKN_RULE_ID_DERIVED_H_USR_DEF_2
{
	public:
		bkn_rule_id();
		bkn_rule_id(const bkn_rule_id & a_bkn_rule_id);
		virtual ~bkn_rule_id();
		bkn_rule_id& operator = (const bkn_rule_id & a_bkn_rule_id);
		void set(const string &  a_m_1, const int &  a_m_2, bkn_production *  a_m_3);
		void print_this(std::ostream & out);
		bkn_rule_id * duplicate();
		virtual void visit_this(recfunc_context & a_recfunc_context);
		string get_rule_name();
		int get_rule_idx();
		bkn_production * get_bkn_production();
	public:
		string	m_1;	// rule_name
		int	m_2;	// rule_idx
		bkn_production *	m_3;	// bkn_production
	BKN_RULE_ID_DERIVED_H_USR_DEF_3
};
#endif

