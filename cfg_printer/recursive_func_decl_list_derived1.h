#ifndef RECURSIVE_FUNC_DECL_LIST_DERIVED1_H_
#define RECURSIVE_FUNC_DECL_LIST_DERIVED1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "recursive_func_decl_list_derived.h"
#include "printer_func_decl.h"
#include "recursive_func_decl_list_derived.h"
RECURSIVE_FUNC_DECL_LIST_DERIVED1_DERIVED_H_USR_DEF_1
using namespace std;
class recursive_func_decl_list_derived1 :public recursive_func_decl_list_derived RECURSIVE_FUNC_DECL_LIST_DERIVED1_DERIVED_H_USR_DEF_2
{
	public:
		recursive_func_decl_list_derived1();
		recursive_func_decl_list_derived1(const recursive_func_decl_list_derived1 & a_recursive_func_decl_list_derived1);
		virtual ~recursive_func_decl_list_derived1();
		recursive_func_decl_list_derived1& operator = (const recursive_func_decl_list_derived1 & a_recursive_func_decl_list_derived1);
		void set(recursive_func_decl_list_derived *  a_m_1, printer_func_decl *  a_m_2);
		void print_this(std::ostream & out);
		recursive_func_decl_list_derived1 * duplicate();
	public:
		recursive_func_decl_list_derived *	m_1;	// recursive_func_decl_list_derived
		printer_func_decl *	m_2;	// printer_func_decl
	RECURSIVE_FUNC_DECL_LIST_DERIVED1_DERIVED_H_USR_DEF_3
};
#endif

