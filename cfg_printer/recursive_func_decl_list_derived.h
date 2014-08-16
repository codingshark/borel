#ifndef RECURSIVE_FUNC_DECL_LIST_DERIVED_H_
#define RECURSIVE_FUNC_DECL_LIST_DERIVED_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
RECURSIVE_FUNC_DECL_LIST_DERIVED_BASE_H_USR_DEF_1
using namespace std;
class recursive_func_decl_list_derived :public symbol_base RECURSIVE_FUNC_DECL_LIST_DERIVED_BASE_H_USR_DEF_2
{
	public:
		recursive_func_decl_list_derived(){};
		recursive_func_decl_list_derived(const recursive_func_decl_list_derived & a_recursive_func_decl_list_derived){}
		virtual ~recursive_func_decl_list_derived(){};
		virtual recursive_func_decl_list_derived& operator = (const recursive_func_decl_list_derived & a_recursive_func_decl_list_derived){};
		virtual void print_this(std::ostream & out){};
		virtual recursive_func_decl_list_derived * duplicate(){};
	RECURSIVE_FUNC_DECL_LIST_DERIVED_BASE_H_USR_DEF_3
};
#endif

