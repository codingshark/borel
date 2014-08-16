#ifndef INCLUDE_FILE_LIST_H_
#define INCLUDE_FILE_LIST_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
INCLUDE_FILE_LIST_BASE_H_USR_DEF_1
using namespace std;
class include_file_list :public symbol_base INCLUDE_FILE_LIST_BASE_H_USR_DEF_2
{
	public:
		include_file_list(){};
		include_file_list(const include_file_list & a_include_file_list){}
		virtual ~include_file_list(){};
		virtual include_file_list& operator = (const include_file_list & a_include_file_list){};
		virtual void print_this(std::ostream & out){};
		virtual include_file_list * duplicate(){};
	INCLUDE_FILE_LIST_BASE_H_USR_DEF_3
};
#endif

