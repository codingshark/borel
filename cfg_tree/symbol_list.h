#ifndef SYMBOL_LIST_H_
#define SYMBOL_LIST_H_

#include <map>
#include <string>
#include <ostream>
#include "symbol_list_item.h"

class symbol_list;
std::ostream & operator << (std::ostream & out, const symbol_list & a_list);

class symbol_list: public std::map<std::string, symbol_list_item>//name symbol_def
{
	public:
		symbol_list ();
		virtual ~symbol_list ();

		friend std::ostream & operator << (std::ostream & out, const symbol_list & a_list);
		
		void insert_symbol(const std::string & a_name, symbol_list_item a_type_pair);
		symbol_list_item get_symbol_type(const std::string & a_name);
};

#endif
