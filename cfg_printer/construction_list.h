#ifndef CONSTRUCTION_LIST_H_
#define CONSTRUCTION_LIST_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
CONSTRUCTION_LIST_BASE_H_USR_DEF_1
using namespace std;
class construction_list :public symbol_base CONSTRUCTION_LIST_BASE_H_USR_DEF_2
{
	public:
		construction_list(){};
		construction_list(const construction_list & a_construction_list){}
		virtual ~construction_list(){};
		virtual construction_list& operator = (const construction_list & a_construction_list){};
		virtual void print_this(std::ostream & out){};
		virtual construction_list * duplicate(){};
	CONSTRUCTION_LIST_BASE_H_USR_DEF_3
};
#endif

