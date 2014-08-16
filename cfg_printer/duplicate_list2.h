#ifndef DUPLICATE_LIST2_H_
#define DUPLICATE_LIST2_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "duplicate_list.h"
#include "data_member_inst.h"
#include "data_member_inst.h"
#include "duplicate_list.h"
DUPLICATE_LIST2_DERIVED_H_USR_DEF_1
using namespace std;
class duplicate_list2 :public duplicate_list DUPLICATE_LIST2_DERIVED_H_USR_DEF_2
{
	public:
		duplicate_list2();
		duplicate_list2(const duplicate_list2 & a_duplicate_list2);
		virtual ~duplicate_list2();
		duplicate_list2& operator = (const duplicate_list2 & a_duplicate_list2);
		void set(duplicate_list *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3);
		void print_this(std::ostream & out);
		duplicate_list2 * duplicate();
	public:
		duplicate_list *	m_1;	// duplicate_list
		data_member_inst *	m_2;	// data_member_inst
		data_member_inst *	m_3;	// data_member_inst
	DUPLICATE_LIST2_DERIVED_H_USR_DEF_3
};
#endif

