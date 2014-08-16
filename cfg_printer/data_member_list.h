#ifndef DATA_MEMBER_LIST_H_
#define DATA_MEMBER_LIST_H_
#include <iostream>
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
DATA_MEMBER_LIST_BASE_H_USR_DEF_1
using namespace std;
class data_member_list :public symbol_base DATA_MEMBER_LIST_BASE_H_USR_DEF_2
{
	public:
		data_member_list(){};
		data_member_list(const data_member_list & a_data_member_list){}
		virtual ~data_member_list(){};
		virtual data_member_list& operator = (const data_member_list & a_data_member_list){};
		virtual void print_this(std::ostream & out){};
		virtual data_member_list * duplicate(){};
	DATA_MEMBER_LIST_BASE_H_USR_DEF_3
};
#endif

