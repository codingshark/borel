#include "symbol_list.h"

#include "cfg_tree_defs.h"

symbol_list::symbol_list ()
{
}

symbol_list::~symbol_list ()
{
}

void symbol_list::insert_symbol(const std::string & a_name, symbol_list_item an_item)
{
	map<std::string, symbol_list_item>::iterator it= find(a_name);
	if(it == end()) 
	{
		insert(map<std::string, symbol_list_item>::value_type(a_name, an_item));
	}
}

symbol_list_item symbol_list::get_symbol_type(const std::string & a_name)
{
	map<std::string, symbol_list_item>::iterator it= find(a_name);
	if(it == end()) 
	{
		return symbol_list_item(SYM_UNKNOWN, "");
	}
	return it->second;
}

std::ostream & operator << (std::ostream & out, const symbol_list & a_list)
{
	return out;
}
