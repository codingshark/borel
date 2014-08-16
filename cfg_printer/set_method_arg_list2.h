#ifndef SET_METHOD_ARG_LIST2_H_
#define SET_METHOD_ARG_LIST2_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "set_method_arg_list.h"
#include "arg_type.h"
#include "data_member_inst.h"
#include "set_method_arg_list.h"
SET_METHOD_ARG_LIST2_DERIVED_H_USR_DEF_1
using namespace std;
class set_method_arg_list2 :public set_method_arg_list SET_METHOD_ARG_LIST2_DERIVED_H_USR_DEF_2
{
	public:
		set_method_arg_list2();
		set_method_arg_list2(const set_method_arg_list2 & a_set_method_arg_list2);
		virtual ~set_method_arg_list2();
		set_method_arg_list2& operator = (const set_method_arg_list2 & a_set_method_arg_list2);
		void set(set_method_arg_list *  a_m_1, arg_type *  a_m_2, data_member_inst *  a_m_3);
		void print_this(std::ostream & out);
		set_method_arg_list2 * duplicate();
	public:
		set_method_arg_list *	m_1;	// set_method_arg_list
		arg_type *	m_2;	// arg_type
		data_member_inst *	m_3;	// data_member_inst
	SET_METHOD_ARG_LIST2_DERIVED_H_USR_DEF_3
};
#endif

