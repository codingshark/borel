#ifndef DATA_MEMBER_LIST1_H_
#define DATA_MEMBER_LIST1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "data_member_list.h"
#include <string.h>
#include "data_member_inst.h"
#include <string.h>
#include "data_member_list.h"
DATA_MEMBER_LIST1_DERIVED_H_USR_DEF_1
using namespace std;
class data_member_list1 :public data_member_list DATA_MEMBER_LIST1_DERIVED_H_USR_DEF_2
{
	public:
		data_member_list1();
		data_member_list1(const data_member_list1 & a_data_member_list1);
		virtual ~data_member_list1();
		data_member_list1& operator = (const data_member_list1 & a_data_member_list1);
		void set(data_member_list *  a_m_1, const string &  a_m_2, data_member_inst *  a_m_3, const string &  a_m_4);
		void print_this(std::ostream & out);
		data_member_list1 * duplicate();
	public:
		data_member_list *	m_1;	// data_member_list
		string	m_2;	// data_member_type
		data_member_inst *	m_3;	// data_member_inst
		string	m_4;	// data_member_name
	DATA_MEMBER_LIST1_DERIVED_H_USR_DEF_3
};
#endif

