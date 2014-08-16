#ifndef PRINT_DERIVED_H_H_
#define PRINT_DERIVED_H_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include "include_file_list.h"
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include "set_method_arg_list.h"
#include <string.h>
#include "recursive_func_decl_list_derived.h"
#include "nonrecursive_func_decl_list.h"
#include "data_member_list.h"
#include <string.h>
PRINT_DERIVED_H_DERIVED_H_USR_DEF_1
using namespace std;
class print_derived_h :public symbol_base PRINT_DERIVED_H_DERIVED_H_USR_DEF_2
{
	public:
		print_derived_h();
		print_derived_h(const print_derived_h & a_print_derived_h);
		virtual ~print_derived_h();
		print_derived_h& operator = (const print_derived_h & a_print_derived_h);
		void set(const string &  a_m_1, const string &  a_m_2, const string &  a_m_3, const string &  a_m_4, include_file_list *  a_m_5, const string &  a_m_6, const string &  a_m_7, const string &  a_m_8, const string &  a_m_9, const string &  a_m_10, const string &  a_m_11, const string &  a_m_12, const string &  a_m_13, const string &  a_m_14, const string &  a_m_15, const string &  a_m_16, const string &  a_m_17, set_method_arg_list *  a_m_18, const string &  a_m_19, recursive_func_decl_list_derived *  a_m_20, nonrecursive_func_decl_list *  a_m_21, data_member_list *  a_m_22, const string &  a_m_23);
		void print_this(std::ostream & out);
		print_derived_h * duplicate();
	public:
		string	m_1;	// upper_name
		string	m_2;	// upper_name
		string	m_3;	// global_def_h
		string	m_4;	// base_class
		include_file_list *	m_5;	// include_file_list
		string	m_6;	// upper_name
		string	m_7;	// class_name
		string	m_8;	// base_of_drived
		string	m_9;	// upper_name
		string	m_10;	// class_name
		string	m_11;	// class_name
		string	m_12;	// class_name
		string	m_13;	// class_name
		string	m_14;	// class_name
		string	m_15;	// class_name
		string	m_16;	// class_name
		string	m_17;	// class_name
		set_method_arg_list *	m_18;	// set_method_arg_list
		string	m_19;	// class_name
		recursive_func_decl_list_derived *	m_20;	// recursive_func_decl_list_derived
		nonrecursive_func_decl_list *	m_21;	// nonrecursive_func_decl_list
		data_member_list *	m_22;	// data_member_list
		string	m_23;	// upper_name
	PRINT_DERIVED_H_DERIVED_H_USR_DEF_3
};
#endif

