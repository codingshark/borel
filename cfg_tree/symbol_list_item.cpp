#include "symbol_list_item.h"
#include <iostream>
symbol_list_item::symbol_list_item()
{
}

symbol_list_item::symbol_list_item(int a_cfg_type, const std::string & a_usr_type)
{
	cfg_type = a_cfg_type;
	usr_type = a_usr_type;
	is_nullable =	0;
}

symbol_list_item::symbol_list_item(const symbol_list_item & a_symbol_list_item)
{
	cfg_type = a_symbol_list_item.cfg_type;
	usr_type = a_symbol_list_item.usr_type;
	is_nullable =	a_symbol_list_item.is_nullable;
}
symbol_list_item::~symbol_list_item()
{
}
symbol_list_item & symbol_list_item::operator = (const symbol_list_item & a_symbol_list_item)
{
	
	cfg_type = a_symbol_list_item.cfg_type;
	usr_type = a_symbol_list_item.usr_type;
	is_nullable =	a_symbol_list_item.is_nullable;
	
	return *this;
}
void symbol_list_item::print_this(std::ostream & out)
{
	out<<"( ";
	out<< cfg_type;
	out<<" , ";
	out<< usr_type;
	out<<" , ";
	out<< is_nullable;
	out<<" )";
}

void symbol_list_item::set(int a_cfg_type, const std::string & a_usr_type)
{
	cfg_type =	a_cfg_type;
	usr_type =	a_usr_type;
	is_nullable =	0;
}
void symbol_list_item::set(int a_cfg_type, const std::string & a_usr_type, int a_is_nullable)
{
	cfg_type =	a_cfg_type;
	usr_type =	a_usr_type;
	is_nullable =	a_is_nullable;
}

symbol_list_item * symbol_list_item::duplicate()
{
	symbol_list_item * a_copy = new symbol_list_item;
	a_copy->cfg_type = cfg_type;
	a_copy->usr_type = usr_type;
	a_copy->is_nullable = is_nullable;
	return a_copy;
}
