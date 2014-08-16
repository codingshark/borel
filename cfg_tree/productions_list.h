#ifndef PRODUCTIONS_LIST_H_
#define PRODUCTIONS_LIST_H_
#include <iostream>
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
PRODUCTIONS_LIST_BASE_H_USR_DEF_1
using namespace std;
class productions_list :public symbol_base PRODUCTIONS_LIST_BASE_H_USR_DEF_2
{
	public:
		productions_list(){};
		productions_list(const productions_list & a_productions_list){}
		virtual ~productions_list(){};
		virtual productions_list& operator = (const productions_list & a_productions_list){};
		virtual void print_this(std::ostream & out){};
		virtual productions_list * duplicate(){};
		virtual void visit_this(context & a_context){};
	PRODUCTIONS_LIST_BASE_H_USR_DEF_3
};
#endif

