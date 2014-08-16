#ifndef FUNC_LIST_H_
#define FUNC_LIST_H_
#include <iostream>
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
FUNC_LIST_BASE_H_USR_DEF_1
using namespace std;
class func_list :public symbol_base FUNC_LIST_BASE_H_USR_DEF_2
{
	public:
		func_list(){};
		func_list(const func_list & a_func_list){}
		virtual ~func_list(){};
		virtual func_list& operator = (const func_list & a_func_list){};
		virtual void print_this(std::ostream & out){};
		virtual func_list * duplicate(){};
		virtual void visit_this(context & a_context){};
	FUNC_LIST_BASE_H_USR_DEF_3
};
#endif

