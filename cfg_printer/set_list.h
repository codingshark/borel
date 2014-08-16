#ifndef SET_LIST_H_
#define SET_LIST_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
SET_LIST_BASE_H_USR_DEF_1
using namespace std;
class set_list :public symbol_base SET_LIST_BASE_H_USR_DEF_2
{
	public:
		set_list(){};
		set_list(const set_list & a_set_list){}
		virtual ~set_list(){};
		virtual set_list& operator = (const set_list & a_set_list){};
		virtual void print_this(std::ostream & out){};
		virtual set_list * duplicate(){};
	SET_LIST_BASE_H_USR_DEF_3
};
#endif

