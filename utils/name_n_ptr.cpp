#include "name_n_ptr.h"
#include <iostream>
name_n_ptr::name_n_ptr()
{
	ptr_symbol_base = NULL;
}
name_n_ptr::name_n_ptr(const name_n_ptr & a_name_n_ptr)
{
	name =	a_name_n_ptr.name;
	ptr_symbol_base =	a_name_n_ptr.ptr_symbol_base;
}

name_n_ptr::name_n_ptr(const string & a_name, symbol_base * a_symbol_base)
{
	name =	a_name;
	ptr_symbol_base = a_symbol_base;
}

name_n_ptr::~name_n_ptr()
{
}
name_n_ptr & name_n_ptr::operator = (const name_n_ptr & a_name_n_ptr)
{
	name =	a_name_n_ptr.name;
	ptr_symbol_base =	a_name_n_ptr.ptr_symbol_base;
}

void name_n_ptr::print_this(std::ostream & out)
{
	out<< name;
}

void name_n_ptr::set(const string & a_name, symbol_base * a_symbol_base)
{
	name =	a_name;
	ptr_symbol_base =	a_symbol_base;
}

