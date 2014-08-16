#ifndef DUPLICATE_LIST1_H_
#define DUPLICATE_LIST1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "duplicate_list.h"
#include "data_member_inst.h"
#include "data_member_inst.h"
#include "data_member_inst.h"
#include "data_member_inst.h"
#include "duplicate_list.h"
DUPLICATE_LIST1_DERIVED_H_USR_DEF_1
using namespace std;
class duplicate_list1 :public duplicate_list DUPLICATE_LIST1_DERIVED_H_USR_DEF_2
{
	public:
		duplicate_list1();
		duplicate_list1(const duplicate_list1 & a_duplicate_list1);
		virtual ~duplicate_list1();
		duplicate_list1& operator = (const duplicate_list1 & a_duplicate_list1);
		void set(duplicate_list *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3, data_member_inst *  a_m_4, data_member_inst *  a_m_5);
		void print_this(std::ostream & out);
		duplicate_list1 * duplicate();
	public:
		duplicate_list *	m_1;	// duplicate_list
		data_member_inst *	m_2;	// data_member_inst
		data_member_inst *	m_3;	// data_member_inst
		data_member_inst *	m_4;	// data_member_inst
		data_member_inst *	m_5;	// data_member_inst
	DUPLICATE_LIST1_DERIVED_H_USR_DEF_3
};
#endif

