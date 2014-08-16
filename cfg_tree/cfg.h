#ifndef CFG_H_
#define CFG_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
#include "rule_list.h"
#include "func_list.h"
CFG_DERIVED_H_USR_DEF_1
using namespace std;
class cfg :public symbol_base CFG_DERIVED_H_USR_DEF_2
{
	public:
		cfg();
		cfg(const cfg & a_cfg);
		virtual ~cfg();
		cfg& operator = (const cfg & a_cfg);
		void set(const string &  a_m_1, const symbol_list &  a_m_2, rule_list *  a_m_3, func_list *  a_m_4);
		void print_this(std::ostream & out);
		cfg * duplicate();
		virtual void visit_this(context & a_context);
	public:
		string	m_1;	// start
		symbol_list	m_2;	// symbol_list
		rule_list *	m_3;	// rule_list
		func_list *	m_4;	// func_list
	CFG_DERIVED_H_USR_DEF_3
};
#endif

