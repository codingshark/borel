#ifndef NONRECURSIVE_FUNC_DECL_LIST1_H_
#define NONRECURSIVE_FUNC_DECL_LIST1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "nonrecursive_func_decl_list.h"
#include "printer_func_decl.h"
#include "nonrecursive_func_decl_list.h"
NONRECURSIVE_FUNC_DECL_LIST1_DERIVED_H_USR_DEF_1
using namespace std;
class nonrecursive_func_decl_list1 :public nonrecursive_func_decl_list NONRECURSIVE_FUNC_DECL_LIST1_DERIVED_H_USR_DEF_2
{
	public:
		nonrecursive_func_decl_list1();
		nonrecursive_func_decl_list1(const nonrecursive_func_decl_list1 & a_nonrecursive_func_decl_list1);
		virtual ~nonrecursive_func_decl_list1();
		nonrecursive_func_decl_list1& operator = (const nonrecursive_func_decl_list1 & a_nonrecursive_func_decl_list1);
		void set(nonrecursive_func_decl_list *  a_m_1, printer_func_decl *  a_m_2);
		void print_this(std::ostream & out);
		nonrecursive_func_decl_list1 * duplicate();
	public:
		nonrecursive_func_decl_list *	m_1;	// nonrecursive_func_decl_list
		printer_func_decl *	m_2;	// printer_func_decl
	NONRECURSIVE_FUNC_DECL_LIST1_DERIVED_H_USR_DEF_3
};
#endif

