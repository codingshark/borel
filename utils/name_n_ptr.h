#ifndef NAME_N_PTR_H_
#define NAME_N_PTR_H_

#include "symbol_base.h"

using namespace std;
class name_n_ptr :public symbol_base
{
	public:
		name_n_ptr();
		name_n_ptr(const name_n_ptr & a_name_n_ptr);
		name_n_ptr(const string & a_name, symbol_base * a_symbol_base);
		virtual ~name_n_ptr();
		name_n_ptr & operator = (const name_n_ptr & a_name_n_ptr);
		void set(const string & a_name, symbol_base * a_symbol_base);

		void print_this(std::ostream & out);

	public:
		name_n_ptr * duplicate();
	public:
		string	name;
		symbol_base  * 	ptr_symbol_base;
};
#endif
