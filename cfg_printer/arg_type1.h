#ifndef ARG_TYPE1_H_
#define ARG_TYPE1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
#include "arg_type.h"
ARG_TYPE1_DERIVED_H_USR_DEF_1
using namespace std;
class arg_type1 :public arg_type ARG_TYPE1_DERIVED_H_USR_DEF_2
{
	public:
		arg_type1();
		arg_type1(const arg_type1 & a_arg_type1);
		virtual ~arg_type1();
		arg_type1& operator = (const arg_type1 & a_arg_type1);
		void set(const string &  a_m_1);
		void print_this(std::ostream & out);
		arg_type1 * duplicate();
	public:
		string	m_1;	// data_member_type
	ARG_TYPE1_DERIVED_H_USR_DEF_3
};
#endif

