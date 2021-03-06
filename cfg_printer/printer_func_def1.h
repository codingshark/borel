#ifndef PRINTER_FUNC_DEF1_H_
#define PRINTER_FUNC_DEF1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "printer_func_def.h"
#include <string.h>
#include "printer_func_def.h"
PRINTER_FUNC_DEF1_DERIVED_H_USR_DEF_1
using namespace std;
class printer_func_def1 :public printer_func_def PRINTER_FUNC_DEF1_DERIVED_H_USR_DEF_2
{
	public:
		printer_func_def1();
		printer_func_def1(const printer_func_def1 & a_printer_func_def1);
		virtual ~printer_func_def1();
		printer_func_def1& operator = (const printer_func_def1 & a_printer_func_def1);
		void set(printer_func_def *  a_m_1, const string &  a_m_2);
		void print_this(std::ostream & out);
		printer_func_def1 * duplicate();
	public:
		printer_func_def *	m_1;	// printer_func_def
		string	m_2;	// source_code
	PRINTER_FUNC_DEF1_DERIVED_H_USR_DEF_3
};
#endif

