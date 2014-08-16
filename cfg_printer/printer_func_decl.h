#ifndef PRINTER_FUNC_DECL_H_
#define PRINTER_FUNC_DECL_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
#include <string.h>
#include <string.h>
PRINTER_FUNC_DECL_DERIVED_H_USR_DEF_1
using namespace std;
class printer_func_decl :public symbol_base PRINTER_FUNC_DECL_DERIVED_H_USR_DEF_2
{
	public:
		printer_func_decl();
		printer_func_decl(const printer_func_decl & a_printer_func_decl);
		virtual ~printer_func_decl();
		printer_func_decl& operator = (const printer_func_decl & a_printer_func_decl);
		void set(const string &  a_m_1, const string &  a_m_2, const string &  a_m_3);
		void print_this(std::ostream & out);
		printer_func_decl * duplicate();
		string get_return_value();
		string get_func_name();
		string get_func_parameter();
	public:
		string	m_1;	// return_value
		string	m_2;	// func_name
		string	m_3;	// func_parameter
	PRINTER_FUNC_DECL_DERIVED_H_USR_DEF_3
};
#endif

