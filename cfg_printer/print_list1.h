#ifndef PRINT_LIST1_H_
#define PRINT_LIST1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "print_list.h"
#include "data_member_inst.h"
#include "data_member_inst.h"
#include "print_list.h"
PRINT_LIST1_DERIVED_H_USR_DEF_1
using namespace std;
class print_list1 :public print_list PRINT_LIST1_DERIVED_H_USR_DEF_2
{
	public:
		print_list1();
		print_list1(const print_list1 & a_print_list1);
		virtual ~print_list1();
		print_list1& operator = (const print_list1 & a_print_list1);
		void set(print_list *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3);
		void print_this(std::ostream & out);
		print_list1 * duplicate();
	public:
		print_list *	m_1;	// print_list
		data_member_inst *	m_2;	// data_member_inst
		data_member_inst *	m_3;	// data_member_inst
	PRINT_LIST1_DERIVED_H_USR_DEF_3
};
#endif

