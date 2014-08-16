#ifndef ASSERT_STMT_H_
#define ASSERT_STMT_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
ASSERT_STMT_BASE_H_USR_DEF_1
using namespace std;
class assert_stmt :public symbol_base ASSERT_STMT_BASE_H_USR_DEF_2
{
	public:
		assert_stmt(){};
		assert_stmt(const assert_stmt & a_assert_stmt){}
		virtual ~assert_stmt(){};
		virtual assert_stmt& operator = (const assert_stmt & a_assert_stmt){};
		virtual void print_this(std::ostream & out){};
		virtual assert_stmt * duplicate(){};
	ASSERT_STMT_BASE_H_USR_DEF_3
};
#endif

