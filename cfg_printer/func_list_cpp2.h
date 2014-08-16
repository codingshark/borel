#ifndef FUNC_LIST_CPP2_H_
#define FUNC_LIST_CPP2_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "func_list_cpp.h"
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include "printer_func_def.h"
#include "func_list_cpp.h"
FUNC_LIST_CPP2_DERIVED_H_USR_DEF_1
using namespace std;
class func_list_cpp2 :public func_list_cpp FUNC_LIST_CPP2_DERIVED_H_USR_DEF_2
{
	public:
		func_list_cpp2();
		func_list_cpp2(const func_list_cpp2 & a_func_list_cpp2);
		virtual ~func_list_cpp2();
		func_list_cpp2& operator = (const func_list_cpp2 & a_func_list_cpp2);
		void set(func_list_cpp *  a_m_1, const string &  a_m_2, const string &  a_m_3, const string &  a_m_4, const string &  a_m_5, printer_func_def *  a_m_6);
		void print_this(std::ostream & out);
		func_list_cpp2 * duplicate();
	public:
		func_list_cpp *	m_1;	// func_list_cpp
		string	m_2;	// return_value
		string	m_3;	// class_name
		string	m_4;	// func_name
		string	m_5;	// func_parameter
		printer_func_def *	m_6;	// printer_func_def
	FUNC_LIST_CPP2_DERIVED_H_USR_DEF_3
};
#endif

