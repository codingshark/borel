#ifndef RECURSIVE_FUNC_DECL_LIST_BASE_H_
#define RECURSIVE_FUNC_DECL_LIST_BASE_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
RECURSIVE_FUNC_DECL_LIST_BASE_BASE_H_USR_DEF_1
using namespace std;
class recursive_func_decl_list_base :public symbol_base RECURSIVE_FUNC_DECL_LIST_BASE_BASE_H_USR_DEF_2
{
	public:
		recursive_func_decl_list_base(){};
		recursive_func_decl_list_base(const recursive_func_decl_list_base & a_recursive_func_decl_list_base){}
		virtual ~recursive_func_decl_list_base(){};
		virtual recursive_func_decl_list_base& operator = (const recursive_func_decl_list_base & a_recursive_func_decl_list_base){};
		virtual void print_this(std::ostream & out){};
		virtual recursive_func_decl_list_base * duplicate(){};
	RECURSIVE_FUNC_DECL_LIST_BASE_BASE_H_USR_DEF_3
};
#endif

