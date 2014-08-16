#ifndef INCLUDE_FILE_LIST2_H_
#define INCLUDE_FILE_LIST2_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "include_file_list.h"
#include <string.h>
#include "include_file_list.h"
INCLUDE_FILE_LIST2_DERIVED_H_USR_DEF_1
using namespace std;
class include_file_list2 :public include_file_list INCLUDE_FILE_LIST2_DERIVED_H_USR_DEF_2
{
	public:
		include_file_list2();
		include_file_list2(const include_file_list2 & a_include_file_list2);
		virtual ~include_file_list2();
		include_file_list2& operator = (const include_file_list2 & a_include_file_list2);
		void set(include_file_list *  a_m_1, const string &  a_m_2);
		void print_this(std::ostream & out);
		include_file_list2 * duplicate();
	public:
		include_file_list *	m_1;	// include_file_list
		string	m_2;	// include_file_name
	INCLUDE_FILE_LIST2_DERIVED_H_USR_DEF_3
};
#endif

