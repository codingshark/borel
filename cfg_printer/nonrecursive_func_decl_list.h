#ifndef NONRECURSIVE_FUNC_DECL_LIST_H_
#define NONRECURSIVE_FUNC_DECL_LIST_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
NONRECURSIVE_FUNC_DECL_LIST_BASE_H_USR_DEF_1
using namespace std;
class nonrecursive_func_decl_list :public symbol_base NONRECURSIVE_FUNC_DECL_LIST_BASE_H_USR_DEF_2
{
	public:
		nonrecursive_func_decl_list(){};
		nonrecursive_func_decl_list(const nonrecursive_func_decl_list & a_nonrecursive_func_decl_list){}
		virtual ~nonrecursive_func_decl_list(){};
		virtual nonrecursive_func_decl_list& operator = (const nonrecursive_func_decl_list & a_nonrecursive_func_decl_list){};
		virtual void print_this(std::ostream & out){};
		virtual nonrecursive_func_decl_list * duplicate(){};
	NONRECURSIVE_FUNC_DECL_LIST_BASE_H_USR_DEF_3
};
#endif

