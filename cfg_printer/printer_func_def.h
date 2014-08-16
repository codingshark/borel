#ifndef PRINTER_FUNC_DEF_H_
#define PRINTER_FUNC_DEF_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
PRINTER_FUNC_DEF_BASE_H_USR_DEF_1
using namespace std;
class printer_func_def :public symbol_base PRINTER_FUNC_DEF_BASE_H_USR_DEF_2
{
	public:
		printer_func_def(){};
		printer_func_def(const printer_func_def & a_printer_func_def){}
		virtual ~printer_func_def(){};
		virtual printer_func_def& operator = (const printer_func_def & a_printer_func_def){};
		virtual void print_this(std::ostream & out){};
		virtual printer_func_def * duplicate(){};
	PRINTER_FUNC_DEF_BASE_H_USR_DEF_3
};
#endif

