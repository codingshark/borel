#ifndef DATA_MEMBER_INST_H_
#define DATA_MEMBER_INST_H_
#include "glb_def_0xbfebbaa4.h"
#include "symbol_base.h"
#include <iostream>
DATA_MEMBER_INST_DERIVED_H_USR_DEF_1
using namespace std;
class data_member_inst :public symbol_base DATA_MEMBER_INST_DERIVED_H_USR_DEF_2
{
	public:
		data_member_inst();
		data_member_inst(const data_member_inst & a_data_member_inst);
		virtual ~data_member_inst();
		data_member_inst& operator = (const data_member_inst & a_data_member_inst);
		void set(const unsigned int &  a_m_1);
		void print_this(std::ostream & out);
		data_member_inst * duplicate();
	public:
		unsigned int	m_1;	// data_member_index
	DATA_MEMBER_INST_DERIVED_H_USR_DEF_3
};
#endif

