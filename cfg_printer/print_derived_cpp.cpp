#include "print_derived_cpp.h"
PRINT_DERIVED_CPP_DERIVED_CPP_USR_DEF
print_derived_cpp::print_derived_cpp()
{
	m_5 = NULL;
	m_10 = NULL;
	m_13 = NULL;
	m_19 = NULL;
	m_21 = NULL;
	m_23 = NULL;
	m_24 = NULL;
	m_29 = NULL;
	m_30 = NULL;
}
print_derived_cpp::print_derived_cpp(const print_derived_cpp & a_print_derived_cpp)
{
	m_1 = a_print_derived_cpp.m_1;
	m_2 = a_print_derived_cpp.m_2;
	m_3 = a_print_derived_cpp.m_3;
	m_4 = a_print_derived_cpp.m_4;
	if( m_5!= NULL )
	{
		delete m_5;
	}
	if(a_print_derived_cpp.m_5 != NULL)
	{
		m_5 = a_print_derived_cpp.m_5->duplicate();
	}else{
		m_5 = NULL;
	}
	m_6 = a_print_derived_cpp.m_6;
	m_7 = a_print_derived_cpp.m_7;
	m_8 = a_print_derived_cpp.m_8;
	m_9 = a_print_derived_cpp.m_9;
	if( m_10!= NULL )
	{
		delete m_10;
	}
	if(a_print_derived_cpp.m_10 != NULL)
	{
		m_10 = a_print_derived_cpp.m_10->duplicate();
	}else{
		m_10 = NULL;
	}
	m_11 = a_print_derived_cpp.m_11;
	m_12 = a_print_derived_cpp.m_12;
	if( m_13!= NULL )
	{
		delete m_13;
	}
	if(a_print_derived_cpp.m_13 != NULL)
	{
		m_13 = a_print_derived_cpp.m_13->duplicate();
	}else{
		m_13 = NULL;
	}
	m_14 = a_print_derived_cpp.m_14;
	m_15 = a_print_derived_cpp.m_15;
	m_16 = a_print_derived_cpp.m_16;
	m_17 = a_print_derived_cpp.m_17;
	m_18 = a_print_derived_cpp.m_18;
	if( m_19!= NULL )
	{
		delete m_19;
	}
	if(a_print_derived_cpp.m_19 != NULL)
	{
		m_19 = a_print_derived_cpp.m_19->duplicate();
	}else{
		m_19 = NULL;
	}
	m_20 = a_print_derived_cpp.m_20;
	if( m_21!= NULL )
	{
		delete m_21;
	}
	if(a_print_derived_cpp.m_21 != NULL)
	{
		m_21 = a_print_derived_cpp.m_21->duplicate();
	}else{
		m_21 = NULL;
	}
	m_22 = a_print_derived_cpp.m_22;
	if( m_23!= NULL )
	{
		delete m_23;
	}
	if(a_print_derived_cpp.m_23 != NULL)
	{
		m_23 = a_print_derived_cpp.m_23->duplicate();
	}else{
		m_23 = NULL;
	}
	if( m_24!= NULL )
	{
		delete m_24;
	}
	if(a_print_derived_cpp.m_24 != NULL)
	{
		m_24 = a_print_derived_cpp.m_24->duplicate();
	}else{
		m_24 = NULL;
	}
	m_25 = a_print_derived_cpp.m_25;
	m_26 = a_print_derived_cpp.m_26;
	m_27 = a_print_derived_cpp.m_27;
	m_28 = a_print_derived_cpp.m_28;
	if( m_29!= NULL )
	{
		delete m_29;
	}
	if(a_print_derived_cpp.m_29 != NULL)
	{
		m_29 = a_print_derived_cpp.m_29->duplicate();
	}else{
		m_29 = NULL;
	}
	if( m_30!= NULL )
	{
		delete m_30;
	}
	if(a_print_derived_cpp.m_30 != NULL)
	{
		m_30 = a_print_derived_cpp.m_30->duplicate();
	}else{
		m_30 = NULL;
	}
}
print_derived_cpp::~print_derived_cpp()
{
	if( m_5!= NULL )
	{
		delete m_5;
	}
	if( m_10!= NULL )
	{
		delete m_10;
	}
	if( m_13!= NULL )
	{
		delete m_13;
	}
	if( m_19!= NULL )
	{
		delete m_19;
	}
	if( m_21!= NULL )
	{
		delete m_21;
	}
	if( m_23!= NULL )
	{
		delete m_23;
	}
	if( m_24!= NULL )
	{
		delete m_24;
	}
	if( m_29!= NULL )
	{
		delete m_29;
	}
	if( m_30!= NULL )
	{
		delete m_30;
	}
}
print_derived_cpp & print_derived_cpp::operator = (const print_derived_cpp & a_print_derived_cpp)
{
	if(this == & a_print_derived_cpp)
		return *this;
	m_1 = a_print_derived_cpp.m_1;
	m_2 = a_print_derived_cpp.m_2;
	m_3 = a_print_derived_cpp.m_3;
	m_4 = a_print_derived_cpp.m_4;
	if( m_5!= NULL )
	{
		delete m_5;
	}
	if(a_print_derived_cpp.m_5 != NULL)
	{
		m_5 = a_print_derived_cpp.m_5->duplicate();
	}else{
		m_5 = NULL;
	}
	m_6 = a_print_derived_cpp.m_6;
	m_7 = a_print_derived_cpp.m_7;
	m_8 = a_print_derived_cpp.m_8;
	m_9 = a_print_derived_cpp.m_9;
	if( m_10!= NULL )
	{
		delete m_10;
	}
	if(a_print_derived_cpp.m_10 != NULL)
	{
		m_10 = a_print_derived_cpp.m_10->duplicate();
	}else{
		m_10 = NULL;
	}
	m_11 = a_print_derived_cpp.m_11;
	m_12 = a_print_derived_cpp.m_12;
	if( m_13!= NULL )
	{
		delete m_13;
	}
	if(a_print_derived_cpp.m_13 != NULL)
	{
		m_13 = a_print_derived_cpp.m_13->duplicate();
	}else{
		m_13 = NULL;
	}
	m_14 = a_print_derived_cpp.m_14;
	m_15 = a_print_derived_cpp.m_15;
	m_16 = a_print_derived_cpp.m_16;
	m_17 = a_print_derived_cpp.m_17;
	m_18 = a_print_derived_cpp.m_18;
	if( m_19!= NULL )
	{
		delete m_19;
	}
	if(a_print_derived_cpp.m_19 != NULL)
	{
		m_19 = a_print_derived_cpp.m_19->duplicate();
	}else{
		m_19 = NULL;
	}
	m_20 = a_print_derived_cpp.m_20;
	if( m_21!= NULL )
	{
		delete m_21;
	}
	if(a_print_derived_cpp.m_21 != NULL)
	{
		m_21 = a_print_derived_cpp.m_21->duplicate();
	}else{
		m_21 = NULL;
	}
	m_22 = a_print_derived_cpp.m_22;
	if( m_23!= NULL )
	{
		delete m_23;
	}
	if(a_print_derived_cpp.m_23 != NULL)
	{
		m_23 = a_print_derived_cpp.m_23->duplicate();
	}else{
		m_23 = NULL;
	}
	if( m_24!= NULL )
	{
		delete m_24;
	}
	if(a_print_derived_cpp.m_24 != NULL)
	{
		m_24 = a_print_derived_cpp.m_24->duplicate();
	}else{
		m_24 = NULL;
	}
	m_25 = a_print_derived_cpp.m_25;
	m_26 = a_print_derived_cpp.m_26;
	m_27 = a_print_derived_cpp.m_27;
	m_28 = a_print_derived_cpp.m_28;
	if( m_29!= NULL )
	{
		delete m_29;
	}
	if(a_print_derived_cpp.m_29 != NULL)
	{
		m_29 = a_print_derived_cpp.m_29->duplicate();
	}else{
		m_29 = NULL;
	}
	if( m_30!= NULL )
	{
		delete m_30;
	}
	if(a_print_derived_cpp.m_30 != NULL)
	{
		m_30 = a_print_derived_cpp.m_30->duplicate();
	}else{
		m_30 = NULL;
	}
	return *this;
}
void print_derived_cpp::print_this(std::ostream & out)
{
	out<<"#include \"";
	out<<m_1;
	out<<".h\"\n";
	out<<m_2;
	out<<"_DERIVED_CPP_USR_DEF\n";
	out<<m_3;
	out<<"::";
	out<<m_4;
	out<<"()\n";
	out<<"{\n";
	if( m_5!= NULL )
	{
		m_5->print_this(out);
	}
	out<<"}\n";
	out<<m_6;
	out<<"::";
	out<<m_7;
	out<<"(const ";
	out<<m_8;
	out<<" & a_";
	out<<m_9;
	out<<")\n";
	out<<"{\n";
	if( m_10!= NULL )
	{
		m_10->print_this(out);
	}
	out<<"}\n";
	out<<m_11;
	out<<"::~";
	out<<m_12;
	out<<"()\n";
	out<<"{\n";
	if( m_13!= NULL )
	{
		m_13->print_this(out);
	}
	out<<"}\n";
	out<<m_14;
	out<<" & ";
	out<<m_15;
	out<<"::operator = (const ";
	out<<m_16;
	out<<" & a_";
	out<<m_17;
	out<<")\n";
	out<<"{\n";
	out<<"\tif(this == & a_";
	out<<m_18;
	out<<")\n";
	out<<"\t\treturn *this;\n";
	if( m_19!= NULL )
	{
		m_19->print_this(out);
	}
	out<<"\treturn *this;\n";
	out<<"}\n";
	out<<"void ";
	out<<m_20;
	out<<"::print_this(std::ostream & out)\n";
	out<<"{\n";
	if( m_21!= NULL )
	{
		m_21->print_this(out);
	}
	out<<"}\n";
	out<<"void ";
	out<<m_22;
	out<<"::set(";
	if( m_23!= NULL )
	{
		m_23->print_this(out);
	}
	out<<")\n";
	out<<"{\n";
	if( m_24!= NULL )
	{
		m_24->print_this(out);
	}
	out<<"}\n";
	out<<m_25;
	out<<" * ";
	out<<m_26;
	out<<"::duplicate()\n";
	out<<"{\n";
	out<<"\t";
	out<<m_27;
	out<<" * a_copy = new ";
	out<<m_28;
	out<<";\n";
	if( m_29!= NULL )
	{
		m_29->print_this(out);
	}
	out<<"\treturn a_copy;\n";
	out<<"}\n";
	if( m_30!= NULL )
	{
		m_30->print_this(out);
	}
}
void print_derived_cpp::set(const string &  a_m_1, const string &  a_m_2, const string &  a_m_3, const string &  a_m_4, construction_list *  a_m_5, const string &  a_m_6, const string &  a_m_7, const string &  a_m_8, const string &  a_m_9, copy_list *  a_m_10, const string &  a_m_11, const string &  a_m_12, deconstruction_list *  a_m_13, const string &  a_m_14, const string &  a_m_15, const string &  a_m_16, const string &  a_m_17, const string &  a_m_18, copy_list *  a_m_19, const string &  a_m_20, print_list *  a_m_21, const string &  a_m_22, set_method_arg_list *  a_m_23, set_list *  a_m_24, const string &  a_m_25, const string &  a_m_26, const string &  a_m_27, const string &  a_m_28, duplicate_list *  a_m_29, func_list_cpp *  a_m_30)
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
	m_24 = a_m_24;
	m_25 = a_m_25;
	m_26 = a_m_26;
	m_27 = a_m_27;
	m_28 = a_m_28;
	m_29 = a_m_29;
	m_30 = a_m_30;
}
print_derived_cpp * print_derived_cpp::duplicate()
{
	print_derived_cpp * a_copy = new print_derived_cpp;
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
	if( m_10!= NULL )
	{
		a_copy->m_10 = m_10->duplicate();
	}else{
		m_10 = NULL;
	}
	a_copy->m_11 = m_11;
	a_copy->m_12 = m_12;
	if( m_13!= NULL )
	{
		a_copy->m_13 = m_13->duplicate();
	}else{
		m_13 = NULL;
	}
	a_copy->m_14 = m_14;
	a_copy->m_15 = m_15;
	a_copy->m_16 = m_16;
	a_copy->m_17 = m_17;
	a_copy->m_18 = m_18;
	if( m_19!= NULL )
	{
		a_copy->m_19 = m_19->duplicate();
	}else{
		m_19 = NULL;
	}
	a_copy->m_20 = m_20;
	if( m_21!= NULL )
	{
		a_copy->m_21 = m_21->duplicate();
	}else{
		m_21 = NULL;
	}
	a_copy->m_22 = m_22;
	if( m_23!= NULL )
	{
		a_copy->m_23 = m_23->duplicate();
	}else{
		m_23 = NULL;
	}
	if( m_24!= NULL )
	{
		a_copy->m_24 = m_24->duplicate();
	}else{
		m_24 = NULL;
	}
	a_copy->m_25 = m_25;
	a_copy->m_26 = m_26;
	a_copy->m_27 = m_27;
	a_copy->m_28 = m_28;
	if( m_29!= NULL )
	{
		a_copy->m_29 = m_29->duplicate();
	}else{
		m_29 = NULL;
	}
	if( m_30!= NULL )
	{
		a_copy->m_30 = m_30->duplicate();
	}else{
		m_30 = NULL;
	}
	return a_copy;
}
string print_derived_cpp::get_class_name()
{

	return m_1;
}
