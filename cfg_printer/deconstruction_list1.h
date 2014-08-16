#ifndef DECONSTRUCTION_LIST1_H_
#define DECONSTRUCTION_LIST1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "deconstruction_list.h"
#include "data_member_inst.h"
#include "data_member_inst.h"
#include "deconstruction_list.h"
DECONSTRUCTION_LIST1_DERIVED_H_USR_DEF_1
using namespace std;
class deconstruction_list1 :public deconstruction_list DECONSTRUCTION_LIST1_DERIVED_H_USR_DEF_2
{
	public:
		deconstruction_list1();
		deconstruction_list1(const deconstruction_list1 & a_deconstruction_list1);
		virtual ~deconstruction_list1();
		deconstruction_list1& operator = (const deconstruction_list1 & a_deconstruction_list1);
		void set(deconstruction_list *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3);
		void print_this(std::ostream & out);
		deconstruction_list1 * duplicate();
	public:
		deconstruction_list *	m_1;	// deconstruction_list
		data_member_inst *	m_2;	// data_member_inst
		data_member_inst *	m_3;	// data_member_inst
	DECONSTRUCTION_LIST1_DERIVED_H_USR_DEF_3
};
#endif

