#ifndef PRINTER_FUNC_DEF2_H_
#define PRINTER_FUNC_DEF2_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "printer_func_def.h"
#include "data_member_inst.h"
#include "printer_func_def.h"
PRINTER_FUNC_DEF2_DERIVED_H_USR_DEF_1
using namespace std;
class printer_func_def2 :public printer_func_def PRINTER_FUNC_DEF2_DERIVED_H_USR_DEF_2
{
	public:
		printer_func_def2();
		printer_func_def2(const printer_func_def2 & a_printer_func_def2);
		virtual ~printer_func_def2();
		printer_func_def2& operator = (const printer_func_def2 & a_printer_func_def2);
		void set(printer_func_def *  a_m_1, data_member_inst *  a_m_2);
		void print_this(std::ostream & out);
		printer_func_def2 * duplicate();
	public:
		printer_func_def *	m_1;	// printer_func_def
		data_member_inst *	m_2;	// data_member_inst
	PRINTER_FUNC_DEF2_DERIVED_H_USR_DEF_3
};
#endif

