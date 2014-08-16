#ifndef PRINT_DERIVED_CPP_H_
#define PRINT_DERIVED_CPP_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include "construction_list.h"
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include "copy_list.h"
#include <string.h>
#include <string.h>
#include "deconstruction_list.h"
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include "copy_list.h"
#include <string.h>
#include "print_list.h"
#include <string.h>
#include "set_method_arg_list.h"
#include "set_list.h"
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include "duplicate_list.h"
#include "func_list_cpp.h"
PRINT_DERIVED_CPP_DERIVED_H_USR_DEF_1
using namespace std;
class print_derived_cpp :public symbol_base PRINT_DERIVED_CPP_DERIVED_H_USR_DEF_2
{
	public:
		print_derived_cpp();
		print_derived_cpp(const print_derived_cpp & a_print_derived_cpp);
		virtual ~print_derived_cpp();
		print_derived_cpp& operator = (const print_derived_cpp & a_print_derived_cpp);
		void set(const string &  a_m_1, const string &  a_m_2, const string &  a_m_3, const string &  a_m_4, construction_list *  a_m_5, const string &  a_m_6, const string &  a_m_7, const string &  a_m_8, const string &  a_m_9, copy_list *  a_m_10, const string &  a_m_11, const string &  a_m_12, deconstruction_list *  a_m_13, const string &  a_m_14, const string &  a_m_15, const string &  a_m_16, const string &  a_m_17, const string &  a_m_18, copy_list *  a_m_19, const string &  a_m_20, print_list *  a_m_21, const string &  a_m_22, set_method_arg_list *  a_m_23, set_list *  a_m_24, const string &  a_m_25, const string &  a_m_26, const string &  a_m_27, const string &  a_m_28, duplicate_list *  a_m_29, func_list_cpp *  a_m_30);
		void print_this(std::ostream & out);
		print_derived_cpp * duplicate();
		string get_class_name();
	public:
		string	m_1;	// class_name
		string	m_2;	// upper_name
		string	m_3;	// class_name
		string	m_4;	// class_name
		construction_list *	m_5;	// construction_list
		string	m_6;	// class_name
		string	m_7;	// class_name
		string	m_8;	// class_name
		string	m_9;	// class_name
		copy_list *	m_10;	// copy_list
		string	m_11;	// class_name
		string	m_12;	// class_name
		deconstruction_list *	m_13;	// deconstruction_list
		string	m_14;	// class_name
		string	m_15;	// class_name
		string	m_16;	// class_name
		string	m_17;	// class_name
		string	m_18;	// class_name
		copy_list *	m_19;	// copy_list
		string	m_20;	// class_name
		print_list *	m_21;	// print_list
		string	m_22;	// class_name
		set_method_arg_list *	m_23;	// set_method_arg_list
		set_list *	m_24;	// set_list
		string	m_25;	// class_name
		string	m_26;	// class_name
		string	m_27;	// class_name
		string	m_28;	// class_name
		duplicate_list *	m_29;	// duplicate_list
		func_list_cpp *	m_30;	// func_list_cpp
	PRINT_DERIVED_CPP_DERIVED_H_USR_DEF_3
};
#endif

