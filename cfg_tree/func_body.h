#ifndef FUNC_BODY_H_
#define FUNC_BODY_H_
#include <iostream>
#include "glb_def_0xbfaea0c4.h"
#include "symbol_base.h"
FUNC_BODY_BASE_H_USR_DEF_1
using namespace std;
class func_body :public symbol_base FUNC_BODY_BASE_H_USR_DEF_2
{
	public:
		func_body(){};
		func_body(const func_body & a_func_body){}
		virtual ~func_body(){};
		virtual func_body& operator = (const func_body & a_func_body){};
		virtual void print_this(std::ostream & out){};
		virtual func_body * duplicate(){};
		virtual void visit_this(context & a_context){};
	FUNC_BODY_BASE_H_USR_DEF_3
};
#endif

