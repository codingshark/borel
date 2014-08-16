#include "print_derived_h.h"
PRINT_DERIVED_H_DERIVED_CPP_USR_DEF
print_derived_h::print_derived_h()
{
	m_5 = NULL;
	m_18 = NULL;
	m_20 = NULL;
	m_21 = NULL;
	m_22 = NULL;
}
print_derived_h::print_derived_h(const print_derived_h & a_print_derived_h)
{
	m_1 = a_print_derived_h.m_1;
	m_2 = a_print_derived_h.m_2;
	m_3 = a_print_derived_h.m_3;
	m_4 = a_print_derived_h.m_4;
	if( m_5!= NULL )
	{
		delete m_5;
	}
	if(a_print_derived_h.m_5 != NULL)
	{
		m_5 = a_print_derived_h.m_5->duplicate();
	}else{
		m_5 = NULL;
	}
	m_6 = a_print_derived_h.m_6;
	m_7 = a_print_derived_h.m_7;
	m_8 = a_print_derived_h.m_8;
	m_9 = a_print_derived_h.m_9;
	m_10 = a_print_derived_h.m_10;
	m_11 = a_print_derived_h.m_11;
	m_12 = a_print_derived_h.m_12;
	m_13 = a_print_derived_h.m_13;
	m_14 = a_print_derived_h.m_14;
	m_15 = a_print_derived_h.m_15;
	m_16 = a_print_derived_h.m_16;
	m_17 = a_print_derived_h.m_17;
	if( m_18!= NULL )
	{
		delete m_18;
	}
	if(a_print_derived_h.m_18 != NULL)
	{
		m_18 = a_print_derived_h.m_18->duplicate();
	}else{
		m_18 = NULL;
	}
	m_19 = a_print_derived_h.m_19;
	if( m_20!= NULL )
	{
		delete m_20;
	}
	if(a_print_derived_h.m_20 != NULL)
	{
		m_20 = a_print_derived_h.m_20->duplicate();
	}else{
		m_20 = NULL;
	}
	if( m_21!= NULL )
	{
		delete m_21;
	}
	if(a_print_derived_h.m_21 != NULL)
	{
		m_21 = a_print_derived_h.m_21->duplicate();
	}else{
		m_21 = NULL;
	}
	if( m_22!= NULL )
	{
		delete m_22;
	}
	if(a_print_derived_h.m_22 != NULL)
	{
		m_22 = a_print_derived_h.m_22->duplicate();
	}else{
		m_22 = NULL;
	}
	m_23 = a_print_derived_h.m_23;
}
print_derived_h::~print_derived_h()
{
	if( m_5!= NULL )
	{
		delete m_5;
	}
	if( m_18!= NULL )
	{
		delete m_18;
	}
	if( m_20!= NULL )
	{
		delete m_20;
	}
	if( m_21!= NULL )
	{
		delete m_21;
	}
	if( m_22!= NULL )
	{
		delete m_22;
	}
}
print_derived_h & print_derived_h::operator = (const print_derived_h & a_print_derived_h)
{
	if(this == & a_print_derived_h)
		return *this;
	m_1 = a_print_derived_h.m_1;
	m_2 = a_print_derived_h.m_2;
	m_3 = a_print_derived_h.m_3;
	m_4 = a_print_derived_h.m_4;
	if( m_5!= NULL )
	{
		delete m_5;
	}
	if(a_print_derived_h.m_5 != NULL)
	{
		m_5 = a_print_derived_h.m_5->duplicate();
	}else{
		m_5 = NULL;
	}
	m_6 = a_print_derived_h.m_6;
	m_7 = a_print_derived_h.m_7;
	m_8 = a_print_derived_h.m_8;
	m_9 = a_print_derived_h.m_9;
	m_10 = a_print_derived_h.m_10;
	m_11 = a_print_derived_h.m_11;
	m_12 = a_print_derived_h.m_12;
	m_13 = a_print_derived_h.m_13;
	m_14 = a_print_derived_h.m_14;
	m_15 = a_print_derived_h.m_15;
	m_16 = a_print_derived_h.m_16;
	m_17 = a_print_derived_h.m_17;
	if( m_18!= NULL )
	{
		delete m_18;
	}
	if(a_print_derived_h.m_18 != NULL)
	{
		m_18 = a_print_derived_h.m_18->duplicate();
	}else{
		m_18 = NULL;
	}
	m_19 = a_print_derived_h.m_19;
	if( m_20!= NULL )
	{
		delete m_20;
	}
	if(a_print_derived_h.m_20 != NULL)
	{
		m_20 = a_print_derived_h.m_20->duplicate();
	}else{
		m_20 = NULL;
	}
	if( m_21!= NULL )
	{
		delete m_21;
	}
	if(a_print_derived_h.m_21 != NULL)
	{
		m_21 = a_print_derived_h.m_21->duplicate();
	}else{
		m_21 = NULL;
	}
	if( m_22!= NULL )
	{
		delete m_22;
	}
	if(a_print_derived_h.m_22 != NULL)
	{
		m_22 = a_print_derived_h.m_22->duplicate();
	}else{
		m_22 = NULL;
	}
	m_23 = a_print_derived_h.m_23;
	return *this;
}
void print_derived_h::print_this(std::ostream & out)
{
	out<<"#ifndef ";
	out<<m_1;
	out<<"_H_\n";
	out<<"#define ";
	out<<m_2;
	out<<"_H_\n";
	out<<"#include \"";
	out<<m_3;
	out<<".h\"\n";
	out<<"#include \"";
	out<<m_4;
	out<<".h\"\n";
	out<<"#include <iostream>\n";
	if( m_5!= NULL )
	{
		m_5->print_this(out);
	}
	out<<m_6;
	out<<"_DERIVED_H_USR_DEF_1\n";
	out<<"using namespace std;\n";
	out<<"class ";
	out<<m_7;
	out<<" :public ";
	out<<m_8;
	out<<" ";
	out<<m_9;
	out<<"_DERIVED_H_USR_DEF_2\n";
	out<<"{\n";
	out<<"\tpublic:\n";
	out<<"\t\t";
	out<<m_10;
	out<<"();\n";
	out<<"\t\t";
	out<<m_11;
	out<<"(const ";
	out<<m_12;
	out<<" & a_";
	out<<m_13;
	out<<");\n";
	out<<"\t\tvirtual ~";
	out<<m_14;
	out<<"();\n";
	out<<"\t\t";
	out<<m_15;
	out<<"& operator = (const ";
	out<<m_16;
	out<<" & a_";
	out<<m_17;
	out<<");\n";
	out<<"\t\tvoid set(";
	if( m_18!= NULL )
	{
		m_18->print_this(out);
	}
	out<<");\n";
	out<<"\t\tvoid print_this(std::ostream & out);\n";
	out<<"\t\t";
	out<<m_19;
	out<<" * duplicate();\n";
	if( m_20!= NULL )
	{
		m_20->print_this(out);
	}
	if( m_21!= NULL )
	{
		m_21->print_this(out);
	}
	out<<"\tpublic:\n";
	if( m_22!= NULL )
	{
		m_22->print_this(out);
	}
	out<<"\t";
	out<<m_23;
	out<<"_DERIVED_H_USR_DEF_3\n";
	out<<"};\n";
	out<<"#endif\n\n";
}
void print_derived_h::set(const string &  a_m_1, const string &  a_m_2, const string &  a_m_3, const string &  a_m_4, include_file_list *  a_m_5, const string &  a_m_6, const string &  a_m_7, const string &  a_m_8, const string &  a_m_9, const string &  a_m_10, const string &  a_m_11, const string &  a_m_12, const string &  a_m_13, const string &  a_m_14, const string &  a_m_15, const string &  a_m_16, const string &  a_m_17, set_method_arg_list *  a_m_18, const string &  a_m_19, recursive_func_decl_list_derived *  a_m_20, nonrecursive_func_decl_list *  a_m_21, data_member_list *  a_m_22, const string &  a_m_23)
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
	m_20 = a_m_20;
	m_21 = a_m_21;
	m_22 = a_m_22;
	m_23 = a_m_23;
}
print_derived_h * print_derived_h::duplicate()
{
	print_derived_h * a_copy = new print_derived_h;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	a_copy->m_3 = m_3;
	a_copy->m_4 = m_4;
	if( m_5!= NULL )
	{
		a_copy->m_5 = m_5->duplicate();
	}else{
		m_5 = NULL;
	}
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
	if( m_20!= NULL )
	{
		a_copy->m_20 = m_20->duplicate();
	}else{
		m_20 = NULL;
	}
	if( m_21!= NULL )
	{
		a_copy->m_21 = m_21->duplicate();
	}else{
		m_21 = NULL;
	}
	if( m_22!= NULL )
	{
		a_copy->m_22 = m_22->duplicate();
	}else{
		m_22 = NULL;
	}
	a_copy->m_23 = m_23;
	return a_copy;
}
