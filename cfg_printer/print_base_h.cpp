#include "print_base_h.h"
PRINT_BASE_H_DERIVED_CPP_USR_DEF
print_base_h::print_base_h()
{
	m_18 = NULL;
}
print_base_h::print_base_h(const print_base_h & a_print_base_h)
{
	m_1 = a_print_base_h.m_1;
	m_2 = a_print_base_h.m_2;
	m_3 = a_print_base_h.m_3;
	m_4 = a_print_base_h.m_4;
	m_5 = a_print_base_h.m_5;
	m_6 = a_print_base_h.m_6;
	m_7 = a_print_base_h.m_7;
	m_8 = a_print_base_h.m_8;
	m_9 = a_print_base_h.m_9;
	m_10 = a_print_base_h.m_10;
	m_11 = a_print_base_h.m_11;
	m_12 = a_print_base_h.m_12;
	m_13 = a_print_base_h.m_13;
	m_14 = a_print_base_h.m_14;
	m_15 = a_print_base_h.m_15;
	m_16 = a_print_base_h.m_16;
	m_17 = a_print_base_h.m_17;
	if( m_18!= NULL )
	{
		delete m_18;
	}
	if(a_print_base_h.m_18 != NULL)
	{
		m_18 = a_print_base_h.m_18->duplicate();
	}else{
		m_18 = NULL;
	}
	m_19 = a_print_base_h.m_19;
}
print_base_h::~print_base_h()
{
	if( m_18!= NULL )
	{
		delete m_18;
	}
}
print_base_h & print_base_h::operator = (const print_base_h & a_print_base_h)
{
	if(this == & a_print_base_h)
		return *this;
	m_1 = a_print_base_h.m_1;
	m_2 = a_print_base_h.m_2;
	m_3 = a_print_base_h.m_3;
	m_4 = a_print_base_h.m_4;
	m_5 = a_print_base_h.m_5;
	m_6 = a_print_base_h.m_6;
	m_7 = a_print_base_h.m_7;
	m_8 = a_print_base_h.m_8;
	m_9 = a_print_base_h.m_9;
	m_10 = a_print_base_h.m_10;
	m_11 = a_print_base_h.m_11;
	m_12 = a_print_base_h.m_12;
	m_13 = a_print_base_h.m_13;
	m_14 = a_print_base_h.m_14;
	m_15 = a_print_base_h.m_15;
	m_16 = a_print_base_h.m_16;
	m_17 = a_print_base_h.m_17;
	if( m_18!= NULL )
	{
		delete m_18;
	}
	if(a_print_base_h.m_18 != NULL)
	{
		m_18 = a_print_base_h.m_18->duplicate();
	}else{
		m_18 = NULL;
	}
	m_19 = a_print_base_h.m_19;
	return *this;
}
void print_base_h::print_this(std::ostream & out)
{
	out<<"#ifndef ";
	out<<m_1;
	out<<"_H_\n";
	out<<"#define ";
	out<<m_2;
	out<<"_H_\n";
	out<<"#include <iostream>\n";
	out<<"#include \"";
	out<<m_3;
	out<<".h\"\n";
	out<<"#include \"";
	out<<m_4;
	out<<".h\"\n";
	out<<m_5;
	out<<"_BASE_H_USR_DEF_1\n";
	out<<"using namespace std;\n";
	out<<"class ";
	out<<m_6;
	out<<" :public ";
	out<<m_7;
	out<<" ";
	out<<m_8;
	out<<"_BASE_H_USR_DEF_2\n";
	out<<"{\n";
	out<<"\tpublic:\n";
	out<<"\t\t";
	out<<m_9;
	out<<"(){};\n";
	out<<"\t\t";
	out<<m_10;
	out<<"(const ";
	out<<m_11;
	out<<" & a_";
	out<<m_12;
	out<<"){}\n";
	out<<"\t\tvirtual ~";
	out<<m_13;
	out<<"(){};\n";
	out<<"\t\tvirtual ";
	out<<m_14;
	out<<"& operator = (const ";
	out<<m_15;
	out<<" & a_";
	out<<m_16;
	out<<"){};\n";
	out<<"\t\tvirtual void print_this(std::ostream & out){};\n";
	out<<"\t\tvirtual ";
	out<<m_17;
	out<<" * duplicate(){};\n";
	if( m_18!= NULL )
	{
		m_18->print_this(out);
	}
	out<<"\t";
	out<<m_19;
	out<<"_BASE_H_USR_DEF_3\n";
	out<<"};\n";
	out<<"#endif\n\n";
}
void print_base_h::set(const string &  a_m_1, const string &  a_m_2, const string &  a_m_3, const string &  a_m_4, const string &  a_m_5, const string &  a_m_6, const string &  a_m_7, const string &  a_m_8, const string &  a_m_9, const string &  a_m_10, const string &  a_m_11, const string &  a_m_12, const string &  a_m_13, const string &  a_m_14, const string &  a_m_15, const string &  a_m_16, const string &  a_m_17, recursive_func_decl_list_base *  a_m_18, const string &  a_m_19)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
	m_4 = a_m_4;
	m_5 = a_m_5;
	m_6 = a_m_6;
	m_7 = a_m_7;
	m_8 = a_m_8;
	m_9 = a_m_9;
	m_10 = a_m_10;
	m_11 = a_m_11;
	m_12 = a_m_12;
	m_13 = a_m_13;
	m_14 = a_m_14;
	m_15 = a_m_15;
	m_16 = a_m_16;
	m_17 = a_m_17;
	m_18 = a_m_18;
	m_19 = a_m_19;
}
print_base_h * print_base_h::duplicate()
{
	print_base_h * a_copy = new print_base_h;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	a_copy->m_3 = m_3;
	a_copy->m_4 = m_4;
	a_copy->m_5 = m_5;
	a_copy->m_6 = m_6;
	a_copy->m_7 = m_7;
	a_copy->m_8 = m_8;
	a_copy->m_9 = m_9;
	a_copy->m_10 = m_10;
	a_copy->m_11 = m_11;
	a_copy->m_12 = m_12;
	a_copy->m_13 = m_13;
	a_copy->m_14 = m_14;
	a_copy->m_15 = m_15;
	a_copy->m_16 = m_16;
	a_copy->m_17 = m_17;
	if( m_18!= NULL )
	{
		a_copy->m_18 = m_18->duplicate();
	}else{
		m_18 = NULL;
	}
	a_copy->m_19 = m_19;
	return a_copy;
}
