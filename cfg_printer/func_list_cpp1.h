#ifndef FUNC_LIST_CPP1_H_
#define FUNC_LIST_CPP1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "func_list_cpp.h"
#include <string.h>
#include <string.h>
#include <string.h>
#include <string.h>
#include "recursive_func_def.h"
#include "func_list_cpp.h"
FUNC_LIST_CPP1_DERIVED_H_USR_DEF_1
using namespace std;
class func_list_cpp1 :public func_list_cpp FUNC_LIST_CPP1_DERIVED_H_USR_DEF_2
{
	public:
		func_list_cpp1();
		func_list_cpp1(const func_list_cpp1 & a_func_list_cpp1);
		virtual ~func_list_cpp1();
		func_list_cpp1& operator = (const func_list_cpp1 & a_func_list_cpp1);
		void set(func_list_cpp *  a_m_1, const string &  a_m_2, const string &  a_m_3, const string &  a_m_4, const string &  a_m_5, recursive_func_def *  a_m_6);
		void print_this(std::ostream & out);
		func_list_cpp1 * duplicate();
	public:
		func_list_cpp *	m_1;	// func_list_cpp
		string	m_2;	// return_value
		string	m_3;	// class_name
		string	m_4;	// func_name
		string	m_5;	// func_parameter
		recursive_func_def *	m_6;	// recursive_func_def
	FUNC_LIST_CPP1_DERIVED_H_USR_DEF_3
};
#endif

