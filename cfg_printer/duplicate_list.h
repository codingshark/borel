#ifndef DUPLICATE_LIST_H_
#define DUPLICATE_LIST_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
DUPLICATE_LIST_BASE_H_USR_DEF_1
using namespace std;
class duplicate_list :public symbol_base DUPLICATE_LIST_BASE_H_USR_DEF_2
{
	public:
		duplicate_list(){};
		duplicate_list(const duplicate_list & a_duplicate_list){}
		virtual ~duplicate_list(){};
		virtual duplicate_list& operator = (const duplicate_list & a_duplicate_list){};
		virtual void print_this(std::ostream & out){};
		virtual duplicate_list * duplicate(){};
	DUPLICATE_LIST_BASE_H_USR_DEF_3
};
#endif

