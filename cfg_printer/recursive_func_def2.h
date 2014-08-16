#ifndef RECURSIVE_FUNC_DEF2_H_
#define RECURSIVE_FUNC_DEF2_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "recursive_func_def.h"
#include "printer_func_def.h"
#include "recursive_func_def.h"
RECURSIVE_FUNC_DEF2_DERIVED_H_USR_DEF_1
using namespace std;
class recursive_func_def2 :public recursive_func_def RECURSIVE_FUNC_DEF2_DERIVED_H_USR_DEF_2
{
	public:
		recursive_func_def2();
		recursive_func_def2(const recursive_func_def2 & a_recursive_func_def2);
		virtual ~recursive_func_def2();
		recursive_func_def2& operator = (const recursive_func_def2 & a_recursive_func_def2);
		void set(recursive_func_def *  a_m_1, printer_func_def *  a_m_2);
		void print_this(std::ostream & out);
		recursive_func_def2 * duplicate();
	public:
		recursive_func_def *	m_1;	// recursive_func_def
		printer_func_def *	m_2;	// printer_func_def
	RECURSIVE_FUNC_DEF2_DERIVED_H_USR_DEF_3
};
#endif

