#ifndef SET_METHOD_ARG_LIST_H_
#define SET_METHOD_ARG_LIST_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
SET_METHOD_ARG_LIST_BASE_H_USR_DEF_1
using namespace std;
class set_method_arg_list :public symbol_base SET_METHOD_ARG_LIST_BASE_H_USR_DEF_2
{
	public:
		set_method_arg_list(){};
		set_method_arg_list(const set_method_arg_list & a_set_method_arg_list){}
		virtual ~set_method_arg_list(){};
		virtual set_method_arg_list& operator = (const set_method_arg_list & a_set_method_arg_list){};
		virtual void print_this(std::ostream & out){};
		virtual set_method_arg_list * duplicate(){};
	SET_METHOD_ARG_LIST_BASE_H_USR_DEF_3
};
#endif

