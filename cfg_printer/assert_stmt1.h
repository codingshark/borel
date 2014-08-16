#ifndef ASSERT_STMT1_H_
#define ASSERT_STMT1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "data_member_inst.h"
#include "assert_stmt.h"
ASSERT_STMT1_DERIVED_H_USR_DEF_1
using namespace std;
class assert_stmt1 :public assert_stmt ASSERT_STMT1_DERIVED_H_USR_DEF_2
{
	public:
		assert_stmt1();
		assert_stmt1(const assert_stmt1 & a_assert_stmt1);
		virtual ~assert_stmt1();
		assert_stmt1& operator = (const assert_stmt1 & a_assert_stmt1);
		void set(data_member_inst *  a_m_1);
		void print_this(std::ostream & out);
		assert_stmt1 * duplicate();
	public:
		data_member_inst *	m_1;	// data_member_inst
	ASSERT_STMT1_DERIVED_H_USR_DEF_3
};
#endif

