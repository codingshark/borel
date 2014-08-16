#ifndef FUNC_DEF_H_
#define FUNC_DEF_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
#include "func_body.h"
FUNC_DEF_DERIVED_H_USR_DEF_1
using namespace std;
class func_def :public symbol_base FUNC_DEF_DERIVED_H_USR_DEF_2
{
	public:
		func_def();
		func_def(const func_def & a_func_def);
		virtual ~func_def();
		func_def& operator = (const func_def & a_func_def);
		void set(const int &  a_m_1, const string &  a_m_2, const int &  a_m_3, func_body *  a_m_4);
		void print_this(std::ostream & out);
		func_def * duplicate();
		virtual void visit_this(context & a_context);
	public:
		int	m_1;	// func_type
		string	m_2;	// func_name
		int	m_3;	// func_index
		func_body *	m_4;	// func_body
	FUNC_DEF_DERIVED_H_USR_DEF_3
};
#endif

