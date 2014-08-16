#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <iostream>
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
PRODUCTION_BASE_H_USR_DEF_1
using namespace std;
class production :public symbol_base PRODUCTION_BASE_H_USR_DEF_2
{
	public:
		production(){};
		production(const production & a_production){}
		virtual ~production(){};
		virtual production& operator = (const production & a_production){};
		virtual void print_this(std::ostream & out){};
		virtual production * duplicate(){};
		virtual void visit_this(context & a_context){};
	PRODUCTION_BASE_H_USR_DEF_3
};
#endif

