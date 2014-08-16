#ifndef FUNC_LIST2_H_
#define FUNC_LIST2_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include "func_list.h"
#include "func_decl.h"
#include "func_list.h"
FUNC_LIST2_DERIVED_H_USR_DEF_1
using namespace std;
class func_list2 :public func_list FUNC_LIST2_DERIVED_H_USR_DEF_2
{
	public:
		func_list2();
		func_list2(const func_list2 & a_func_list2);
		virtual ~func_list2();
		func_list2& operator = (const func_list2 & a_func_list2);
		void set(func_list *  a_m_1, func_decl *  a_m_2);
		void print_this(std::ostream & out);
		func_list2 * duplicate();
		virtual void visit_this(context & a_context);
	public:
		func_list *	m_1;	// func_list
		func_decl *	m_2;	// func_decl
	FUNC_LIST2_DERIVED_H_USR_DEF_3
};
#endif

