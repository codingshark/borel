#ifndef PRINT_LIST3_H_
#define PRINT_LIST3_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "print_list.h"
#include <string.h>
#include "print_list.h"
PRINT_LIST3_DERIVED_H_USR_DEF_1
using namespace std;
class print_list3 :public print_list PRINT_LIST3_DERIVED_H_USR_DEF_2
{
	public:
		print_list3();
		print_list3(const print_list3 & a_print_list3);
		virtual ~print_list3();
		print_list3& operator = (const print_list3 & a_print_list3);
		void set(print_list *  a_m_1, const string &  a_m_2);
		void print_this(std::ostream & out);
		print_list3 * duplicate();
	public:
		print_list *	m_1;	// print_list
		string	m_2;	// str_member
	PRINT_LIST3_DERIVED_H_USR_DEF_3
};
#endif

