#ifndef CONSTRUCTION_LIST1_H_
#define CONSTRUCTION_LIST1_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
#include "construction_list.h"
#include "data_member_inst.h"
#include "construction_list.h"
CONSTRUCTION_LIST1_DERIVED_H_USR_DEF_1
using namespace std;
class construction_list1 :public construction_list CONSTRUCTION_LIST1_DERIVED_H_USR_DEF_2
{
	public:
		construction_list1();
		construction_list1(const construction_list1 & a_construction_list1);
		virtual ~construction_list1();
		construction_list1& operator = (const construction_list1 & a_construction_list1);
		void set(construction_list *  a_m_1, data_member_inst *  a_m_2);
		void print_this(std::ostream & out);
		construction_list1 * duplicate();
	public:
		construction_list *	m_1;	// construction_list
		data_member_inst *	m_2;	// data_member_inst
	CONSTRUCTION_LIST1_DERIVED_H_USR_DEF_3
};
#endif

