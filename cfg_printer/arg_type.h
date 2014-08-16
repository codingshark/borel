#ifndef ARG_TYPE_H_
#define ARG_TYPE_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
ARG_TYPE_BASE_H_USR_DEF_1
using namespace std;
class arg_type :public symbol_base ARG_TYPE_BASE_H_USR_DEF_2
{
	public:
		arg_type(){};
		arg_type(const arg_type & a_arg_type){}
		virtual ~arg_type(){};
		virtual arg_type& operator = (const arg_type & a_arg_type){};
		virtual void print_this(std::ostream & out){};
		virtual arg_type * duplicate(){};
	ARG_TYPE_BASE_H_USR_DEF_3
};
#endif

