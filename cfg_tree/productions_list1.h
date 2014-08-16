#ifndef PRODUCTIONS_LIST1_H_
#define PRODUCTIONS_LIST1_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include "productions_list.h"
#include "production.h"
#include "productions_list.h"
PRODUCTIONS_LIST1_DERIVED_H_USR_DEF_1
using namespace std;
class productions_list1 :public productions_list PRODUCTIONS_LIST1_DERIVED_H_USR_DEF_2
{
	public:
		productions_list1();
		productions_list1(const productions_list1 & a_productions_list1);
		virtual ~productions_list1();
		productions_list1& operator = (const productions_list1 & a_productions_list1);
		void set(productions_list *  a_m_1, production *  a_m_2);
		void print_this(std::ostream & out);
		productions_list1 * duplicate();
		virtual void visit_this(context & a_context);
	public:
		productions_list *	m_1;	// productions_list
		production *	m_2;	// production
	PRODUCTIONS_LIST1_DERIVED_H_USR_DEF_3
};
#endif

