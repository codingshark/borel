#ifndef ARG_TYPE2_H_
#define ARG_TYPE2_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
#include "arg_type.h"
ARG_TYPE2_DERIVED_H_USR_DEF_1
using namespace std;
class arg_type2 :public arg_type ARG_TYPE2_DERIVED_H_USR_DEF_2
{
	public:
		arg_type2();
		arg_type2(const arg_type2 & a_arg_type2);
		virtual ~arg_type2();
		arg_type2& operator = (const arg_type2 & a_arg_type2);
		void set(const string &  a_m_1);
		void print_this(std::ostream & out);
		arg_type2 * duplicate();
	public:
		string	m_1;	// data_member_type
	ARG_TYPE2_DERIVED_H_USR_DEF_3
};
#endif

