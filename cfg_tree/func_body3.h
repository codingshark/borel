#ifndef FUNC_BODY3_H_
#define FUNC_BODY3_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include "func_body.h"
#include "func_body.h"
FUNC_BODY3_DERIVED_H_USR_DEF_1
using namespace std;
class func_body3 :public func_body FUNC_BODY3_DERIVED_H_USR_DEF_2
{
	public:
		func_body3();
		func_body3(const func_body3 & a_func_body3);
		virtual ~func_body3();
		func_body3& operator = (const func_body3 & a_func_body3);
		void set(func_body *  a_m_1, const int &  a_m_2);
		void print_this(std::ostream & out);
		func_body3 * duplicate();
		virtual void visit_this(context & a_context);
	public:
		func_body *	m_1;	// func_body
		int	m_2;	// left_symbol
	FUNC_BODY3_DERIVED_H_USR_DEF_3
};
#endif

