#ifndef FUNC_BODY1_H_
#define FUNC_BODY1_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include "func_body.h"
#include <string.h>
#include "func_body.h"
FUNC_BODY1_DERIVED_H_USR_DEF_1
using namespace std;
class func_body1 :public func_body FUNC_BODY1_DERIVED_H_USR_DEF_2
{
	public:
		func_body1();
		func_body1(const func_body1 & a_func_body1);
		virtual ~func_body1();
		func_body1& operator = (const func_body1 & a_func_body1);
		void set(func_body *  a_m_1, const string &  a_m_2);
		void print_this(std::ostream & out);
		func_body1 * duplicate();
		virtual void visit_this(context & a_context);
	public:
		func_body *	m_1;	// func_body
		string	m_2;	// func_str
	FUNC_BODY1_DERIVED_H_USR_DEF_3
};
#endif

