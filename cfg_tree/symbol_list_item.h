#ifndef SYMBOL_LIST_ITEM_H_
#define SYMBOL_LIST_ITEM_H_

#include <string>

class symbol_list_item
{
	public:
		symbol_list_item();
		symbol_list_item(int a_cfg_type, const std::string & a_usr_type);
		symbol_list_item(const symbol_list_item & a_symbol_list_item);
		virtual ~symbol_list_item();
		symbol_list_item & operator = (const symbol_list_item & a_symbol_list_item);
		void set(int a_cfg_type, const std::string & a_usr_type);
		void set(int a_cfg_type, const std::string & a_usr_type, int a_is_nullable);

		void print_this(std::ostream & out);
	public:
		symbol_list_item * duplicate();
	public:
		int	cfg_type;
		std::string	usr_type;
		int	is_nullable;
};
#endif
