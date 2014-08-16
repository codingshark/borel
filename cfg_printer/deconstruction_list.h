#ifndef DECONSTRUCTION_LIST_H_
#define DECONSTRUCTION_LIST_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
DECONSTRUCTION_LIST_BASE_H_USR_DEF_1
using namespace std;
class deconstruction_list :public symbol_base DECONSTRUCTION_LIST_BASE_H_USR_DEF_2
{
	public:
		deconstruction_list(){};
		deconstruction_list(const deconstruction_list & a_deconstruction_list){}
		virtual ~deconstruction_list(){};
		virtual deconstruction_list& operator = (const deconstruction_list & a_deconstruction_list){};
		virtual void print_this(std::ostream & out){};
		virtual deconstruction_list * duplicate(){};
	DECONSTRUCTION_LIST_BASE_H_USR_DEF_3
};
#endif

