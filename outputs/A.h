#ifndef A_H_
#define A_H_
#include "glb_def_0xbfb6c464.h"
#include "symbol_base.h"
#include <iostream>
A_DERIVED_H_USR_DEF_1
using namespace std;
class A :public symbol_base A_DERIVED_H_USR_DEF_2
{
	public:
		A();
		A(const A & a_A);
		virtual ~A();
		A& operator = (const A & a_A);
		void set(int &  a_m_1, int &  a_m_2);
		void print_this(std::ostream & out);
		A * duplicate();
		virtual int [ 7584798 ] int < double > * & visit();
		void * func();
	public:
		int	m_1;	// b
		int	m_2;	// b
	A_DERIVED_H_USR_DEF_3
};
#endif

