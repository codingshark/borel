#ifndef COPY_LIST_H_
#define COPY_LIST_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
COPY_LIST_BASE_H_USR_DEF_1
using namespace std;
class copy_list :public symbol_base COPY_LIST_BASE_H_USR_DEF_2
{
	public:
		copy_list(){};
		copy_list(const copy_list & a_copy_list){}
		virtual ~copy_list(){};
		virtual copy_list& operator = (const copy_list & a_copy_list){};
		virtual void print_this(std::ostream & out){};
		virtual copy_list * duplicate(){};
	COPY_LIST_BASE_H_USR_DEF_3
};
#endif

