#ifndef RULE_LIST1_H_
#define RULE_LIST1_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include "rule_list.h"
#include "rule_def.h"
#include "rule_list.h"
RULE_LIST1_DERIVED_H_USR_DEF_1
using namespace std;
class rule_list1 :public rule_list RULE_LIST1_DERIVED_H_USR_DEF_2
{
	public:
		rule_list1();
		rule_list1(const rule_list1 & a_rule_list1);
		virtual ~rule_list1();
		rule_list1& operator = (const rule_list1 & a_rule_list1);
		void set(rule_list *  a_m_1, rule_def *  a_m_2);
		void print_this(std::ostream & out);
		rule_list1 * duplicate();
		virtual void visit_this(context & a_context);
	public:
		rule_list *	m_1;	// rule_list
		rule_def *	m_2;	// rule_def
	RULE_LIST1_DERIVED_H_USR_DEF_3
};
#endif

