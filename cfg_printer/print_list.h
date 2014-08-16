#ifndef PRINT_LIST_H_
#define PRINT_LIST_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
PRINT_LIST_BASE_H_USR_DEF_1
using namespace std;
class print_list :public symbol_base PRINT_LIST_BASE_H_USR_DEF_2
{
	public:
		print_list(){};
		print_list(const print_list & a_print_list){}
		virtual ~print_list(){};
		virtual print_list& operator = (const print_list & a_print_list){};
		virtual void print_this(std::ostream & out){};
		virtual print_list * duplicate(){};
	PRINT_LIST_BASE_H_USR_DEF_3
};
#endif

