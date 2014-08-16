#ifndef SET_LIST1_H_
#define SET_LIST1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "set_list.h"
#include "assert_stmt.h"
#include "data_member_inst.h"
#include "data_member_inst.h"
#include "set_list.h"
SET_LIST1_DERIVED_H_USR_DEF_1
using namespace std;
class set_list1 :public set_list SET_LIST1_DERIVED_H_USR_DEF_2
{
	public:
		set_list1();
		set_list1(const set_list1 & a_set_list1);
		virtual ~set_list1();
		set_list1& operator = (const set_list1 & a_set_list1);
		void set(set_list *  a_m_1, assert_stmt *  a_m_2, data_member_inst *  a_m_3, data_member_inst *  a_m_4);
		void print_this(std::ostream & out);
		set_list1 * duplicate();
	public:
		set_list *	m_1;	// set_list
		assert_stmt *	m_2;	// assert_stmt
		data_member_inst *	m_3;	// data_member_inst
		data_member_inst *	m_4;	// data_member_inst
	SET_LIST1_DERIVED_H_USR_DEF_3
};
#endif

