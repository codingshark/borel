#ifndef FUNC_DECL_H_
#define FUNC_DECL_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
#include <string.h>
#include <string.h>
FUNC_DECL_DERIVED_H_USR_DEF_1
using namespace std;
class func_decl :public symbol_base FUNC_DECL_DERIVED_H_USR_DEF_2
{
	public:
		func_decl();
		func_decl(const func_decl & a_func_decl);
		virtual ~func_decl();
		func_decl& operator = (const func_decl & a_func_decl);
		void set(const int &  a_m_1, const string &  a_m_2, const string &  a_m_3, const string &  a_m_4);
		void print_this(std::ostream & out);
		func_decl * duplicate();
		virtual void visit_this(context & a_context);
	public:
		int	m_1;	// func_type
		string	m_2;	// return_value
		string	m_3;	// func_name
		string	m_4;	// func_parameter
	FUNC_DECL_DERIVED_H_USR_DEF_3
};
#endif

