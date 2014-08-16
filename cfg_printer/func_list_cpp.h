#ifndef FUNC_LIST_CPP_H_
#define FUNC_LIST_CPP_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
FUNC_LIST_CPP_BASE_H_USR_DEF_1
using namespace std;
class func_list_cpp :public symbol_base FUNC_LIST_CPP_BASE_H_USR_DEF_2
{
	public:
		func_list_cpp(){};
		func_list_cpp(const func_list_cpp & a_func_list_cpp){}
		virtual ~func_list_cpp(){};
		virtual func_list_cpp& operator = (const func_list_cpp & a_func_list_cpp){};
		virtual void print_this(std::ostream & out){};
		virtual func_list_cpp * duplicate(){};
	FUNC_LIST_CPP_BASE_H_USR_DEF_3
};
#endif

