#ifndef COPY_LIST1_H_
#define COPY_LIST1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "copy_list.h"
#include "data_member_inst.h"
#include <string.h>
#include "data_member_inst.h"
#include "copy_list.h"
COPY_LIST1_DERIVED_H_USR_DEF_1
using namespace std;
class copy_list1 :public copy_list COPY_LIST1_DERIVED_H_USR_DEF_2
{
	public:
		copy_list1();
		copy_list1(const copy_list1 & a_copy_list1);
		virtual ~copy_list1();
		copy_list1& operator = (const copy_list1 & a_copy_list1);
		void set(copy_list *  a_m_1, data_member_inst *  a_m_2, const string &  a_m_3, data_member_inst *  a_m_4);
		void print_this(std::ostream & out);
		copy_list1 * duplicate();
	public:
		copy_list *	m_1;	// copy_list
		data_member_inst *	m_2;	// data_member_inst
		string	m_3;	// class_name
		data_member_inst *	m_4;	// data_member_inst
	COPY_LIST1_DERIVED_H_USR_DEF_3
};
#endif

