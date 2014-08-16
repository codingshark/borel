#ifndef RECURSIVE_FUNC_DEF_H_
#define RECURSIVE_FUNC_DEF_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
RECURSIVE_FUNC_DEF_BASE_H_USR_DEF_1
using namespace std;
class recursive_func_def :public symbol_base RECURSIVE_FUNC_DEF_BASE_H_USR_DEF_2
{
	public:
		recursive_func_def(){};
		recursive_func_def(const recursive_func_def & a_recursive_func_def){}
		virtual ~recursive_func_def(){};
		virtual recursive_func_def& operator = (const recursive_func_def & a_recursive_func_def){};
		virtual void print_this(std::ostream & out){};
		virtual recursive_func_def * duplicate(){};
	RECURSIVE_FUNC_DEF_BASE_H_USR_DEF_3
};
#endif

