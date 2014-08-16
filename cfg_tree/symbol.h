#ifndef SYMBOL_H_
#define SYMBOL_H_
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
#include <iostream>
#include <string.h>
SYMBOL_DERIVED_H_USR_DEF_1
using namespace std;
class symbol :public symbol_base SYMBOL_DERIVED_H_USR_DEF_2
{
	public:
		symbol();
		symbol(const symbol & a_symbol);
		virtual ~symbol();
		symbol& operator = (const symbol & a_symbol);
		void set(const string &  a_m_1, const int &  a_m_2);
		void print_this(std::ostream & out);
		symbol * duplicate();
		virtual void visit_this(context & a_context);
	public:
		string	m_1;	// name
		int	m_2;	// cfg_type
	SYMBOL_DERIVED_H_USR_DEF_3
};
#endif

