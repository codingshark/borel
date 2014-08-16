#ifndef RECURSIVE_FUNC_DEF1_H_
#define RECURSIVE_FUNC_DEF1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "recursive_func_def.h"
#include "data_member_inst.h"
#include "data_member_inst.h"
#include <string.h>
#include <string.h>
#include "recursive_func_def.h"
RECURSIVE_FUNC_DEF1_DERIVED_H_USR_DEF_1
using namespace std;
class recursive_func_def1 :public recursive_func_def RECURSIVE_FUNC_DEF1_DERIVED_H_USR_DEF_2
{
	public:
		recursive_func_def1();
		recursive_func_def1(const recursive_func_def1 & a_recursive_func_def1);
		virtual ~recursive_func_def1();
		recursive_func_def1& operator = (const recursive_func_def1 & a_recursive_func_def1);
		void set(recursive_func_def *  a_m_1, data_member_inst *  a_m_2, data_member_inst *  a_m_3, const string &  a_m_4, const string &  a_m_5);
		void print_this(std::ostream & out);
		recursive_func_def1 * duplicate();
	public:
		recursive_func_def *	m_1;	// recursive_func_def
		data_member_inst *	m_2;	// data_member_inst
		data_member_inst *	m_3;	// data_member_inst
		string	m_4;	// func_name
		string	m_5;	// func_parameter
	RECURSIVE_FUNC_DEF1_DERIVED_H_USR_DEF_3
};
#endif

