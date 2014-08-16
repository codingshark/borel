#include "context.h"


#define BUILD_IN_TYPE(FUNC)	FUNC ("int")		\
			FUNC ("double")		\
			FUNC ("float")		\
			FUNC ("char")		\
			FUNC ("long")		\
			FUNC ("short")		\
			FUNC ("short int")	\
			FUNC ("long int")	\
			FUNC ("long double ")	\
			FUNC ("long long int")	\
						\
			FUNC ("unsigned int")	\
			FUNC ("unsigned char")	\
			FUNC ("unsigned long")	\
			FUNC ("unsigned short")	\
			FUNC ("unsigned short int")	\
			FUNC ("unsigned long int")	\
			FUNC ("unsigned long long int")	\
							\
			FUNC ("signed int")		\
			FUNC ("signed char")		\
			FUNC ("signed long")		\
			FUNC ("signed short")		\
			FUNC ("signed short int")	\
			FUNC ("signed long int")	\
			FUNC ("signed long long int")	\
							

#define STD_TYPE(FUNC)	FUNC ("string")		\


#define TEST(str)	if(!a_type.compare(str))\
				return 1;

context::context ()
{
	p_symbol_list = NULL;
}

context::~context (){}

context::ptr_pair::ptr_pair(symbol_base * a_ptr, int a_ptr_type):
	ptr(a_ptr), ptr_type(a_ptr_type)
{
}

context::ptr_pair::~ptr_pair()
{
}

context::ptr_pair & context::ptr_pair::operator = (const context::ptr_pair & a_ptr_pair)
{
	ptr = a_ptr_pair.ptr;
	ptr_type = a_ptr_pair.ptr_type;
	return *this;
}

int context::is_build_in(const std::string & a_type)
{
	BUILD_IN_TYPE(TEST)
	return 0;
}

int context::is_std_type(const std::string & a_type)
{
	STD_TYPE(TEST)
	return 0;
}

void context::clean_up()
{
	while(! for_print.empty())
	{
		delete for_print.back().ptr_symbol_base;
		for_print.pop_back();
	}

	while (! func_declarations.empty())
	{
		delete func_declarations.back().ptr_symbol_base;
		func_declarations.pop_back();	
	}

	while (! bkn_production_stack.empty())
	{
		delete bkn_production_stack.back();
		bkn_production_stack.pop_back();
	}

	for (std::map<string, std::map<int, symbol_base *> >::iterator 
		it = func_name_idx2def.begin();
	 	it != func_name_idx2def.end(); it ++)
	{
		for (std::map<int, symbol_base *>::iterator
			jt = (it->second).begin(); 
			jt != (it->second).end(); jt ++)
		{
			delete jt->second;
		}
	}

}

#ifdef	DEBUG
#include <iostream>
using std::cout;
using std::endl;
void context::print_context()
{
	cout<<"production_name: "<<production_name<<endl;
	cout<<"==========ptr_stack========"<<endl;
	for (std::list<context::ptr_pair>::iterator it = ptr_stack.begin(); it != ptr_stack.end(); it ++)
	{
		(it->ptr)->print_this(cout);
		cout<<endl;
	}
	cout<<endl;
	cout<<"============p_last========="<<endl;
	for (unsigned int i = 0; i < CONTEXT_P_LAST_SIZE; i += 1)
	{
		if(p_last[i] != NULL)
		{
			(p_last[i])->print_this(cout);
			cout<<endl;
		}
	}
	
	cout<<"production_counter: "<<production_counter<<endl;
}
#endif
