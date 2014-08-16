#ifndef FUNC_LIST1_H_
#define FUNC_LIST1_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include "func_list.h"
#include "func_def.h"
#include "func_list.h"
FUNC_LIST1_DERIVED_H_USR_DEF_1
using namespace std;
class func_list1 :public func_list FUNC_LIST1_DERIVED_H_USR_DEF_2
{
	public:
		func_list1();
		func_list1(const func_list1 & a_func_list1);
		virtual ~func_list1();
		func_list1& operator = (const func_list1 & a_func_list1);
		void set(func_list *  a_m_1, func_def *  a_m_2);
		void print_this(std::ostream & out);
		func_list1 * duplicate();
		virtual void visit_this(context & a_context);
	public:
		func_list *	m_1;	// func_list
		func_def *	m_2;	// func_def
	FUNC_LIST1_DERIVED_H_USR_DEF_3
};
#endif

