#ifndef RULE_DEF_H_
#define RULE_DEF_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
#include "productions_list.h"
RULE_DEF_DERIVED_H_USR_DEF_1
using namespace std;
class rule_def :public symbol_base RULE_DEF_DERIVED_H_USR_DEF_2
{
	public:
		rule_def();
		rule_def(const rule_def & a_rule_def);
		virtual ~rule_def();
		rule_def& operator = (const rule_def & a_rule_def);
		void set(const string &  a_m_1, productions_list *  a_m_2);
		void print_this(std::ostream & out);
		rule_def * duplicate();
		virtual void visit_this(context & a_context);
	public:
		string	m_1;	// name
		productions_list *	m_2;	// productions_list
	RULE_DEF_DERIVED_H_USR_DEF_3
};
#endif

