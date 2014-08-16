#ifndef FUNC_PLACE_HOLDER_H_
#define FUNC_PLACE_HOLDER_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
FUNC_PLACE_HOLDER_DERIVED_H_USR_DEF_1
using namespace std;
class func_place_holder :public symbol_base FUNC_PLACE_HOLDER_DERIVED_H_USR_DEF_2
{
	public:
		func_place_holder();
		func_place_holder(const func_place_holder & a_func_place_holder);
		virtual ~func_place_holder();
		func_place_holder& operator = (const func_place_holder & a_func_place_holder);
		void set(const int &  a_m_1, const string &  a_m_2, const int &  a_m_3);
		void print_this(std::ostream & out);
		func_place_holder * duplicate();
		virtual void visit_this(context & a_context);
	public:
		int	m_1;	// func_type
		string	m_2;	// func_name
		int	m_3;	// func_index
	FUNC_PLACE_HOLDER_DERIVED_H_USR_DEF_3
};
#endif

