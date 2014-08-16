#ifndef RULE_LIST_H_
#define RULE_LIST_H_
#include <iostream>
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
RULE_LIST_BASE_H_USR_DEF_1
using namespace std;
class rule_list :public symbol_base RULE_LIST_BASE_H_USR_DEF_2
{
	public:
		rule_list(){};
		rule_list(const rule_list & a_rule_list){}
		virtual ~rule_list(){};
		virtual rule_list& operator = (const rule_list & a_rule_list){};
		virtual void print_this(std::ostream & out){};
		virtual rule_list * duplicate(){};
		virtual void visit_this(context & a_context){};
	RULE_LIST_BASE_H_USR_DEF_3
};
#endif

