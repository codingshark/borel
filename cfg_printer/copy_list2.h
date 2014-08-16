#ifndef COPY_LIST2_H_
#define COPY_LIST2_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "copy_list.h"
#include "data_member_inst.h"
#include "data_member_inst.h"
#include <string.h>
#include "data_member_inst.h"
#include "data_member_inst.h"
#include <string.h>
#include "data_member_inst.h"
#include "data_member_inst.h"
#include "copy_list.h"
COPY_LIST2_DERIVED_H_USR_DEF_1
using namespace std;
class copy_list2 :public copy_list COPY_LIST2_DERIVED_H_USR_DEF_2
{
	public:
		copy_list2();
		copy_list2(const copy_list2 & a_copy_list2);
		virtual ~copy_list2();
		copy_list2& operator = (const copy_list2 & a_copy_list2);
		void set(copy_list *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3, const string &  a_m_4, data_member_inst *  a_m_5, data_member_inst *  a_m_6, const string &  a_m_7, data_member_inst *  a_m_8, data_member_inst *  a_m_9);
		void print_this(std::ostream & out);
		copy_list2 * duplicate();
	public:
		copy_list *	m_1;	// copy_list
		data_member_inst *	m_2;	// data_member_inst
		data_member_inst *	m_3;	// data_member_inst
		string	m_4;	// class_name
		data_member_inst *	m_5;	// data_member_inst
		data_member_inst *	m_6;	// data_member_inst
		string	m_7;	// class_name
		data_member_inst *	m_8;	// data_member_inst
		data_member_inst *	m_9;	// data_member_inst
	COPY_LIST2_DERIVED_H_USR_DEF_3
};
#endif

