#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <list>
#include <string>
#include <map>
#include "name_n_idx.h"
#include "name_n_ptr.h"
#include "symbol_base.h"
#include "symbol_list.h"

#define CONTEXT_P_LAST_SIZE 10

class context
{
	public:
		context ();
		virtual ~context ();
		
		int is_build_in(const std::string & type_name);
		int is_std_type(const std::string & a_type);

		struct ptr_pair
		{
			ptr_pair(symbol_base * a_ptr, int a_ptr_type);
			~ptr_pair();
			ptr_pair & operator = (const ptr_pair & a_ptr_pair);
			symbol_base *	ptr;
			int		ptr_type;
		};

		void clean_up();
#ifdef	DEBUG
		void print_context();
#endif
	public:
		
		////tmp variables
		std::list<ptr_pair>	ptr_stack;

		symbol_base *	p_last[CONTEXT_P_LAST_SIZE];//cfg:symbol
		
		symbol_list *	p_symbol_list;//used to check types
		
		std::string	production_name;//production name
		unsigned int	production_idx;
		unsigned int	production_counter;//used to determin the number of producitons yield by a non-terminal symbol
		unsigned int	symbol_idx;
		////end tmp variables
		
		////for usr functions
		std::map<string, name_n_idx> nonrecfunc2prodction; //map name of nonrecursive function to production(produciton and production index)
		
		////need to clean up
		/**/std::list<name_n_ptr> for_print;//(class name, ptr). ponters to structure that need to print out
		/**/std::list<name_n_ptr> func_declarations;//(func_name, pointe to declaration) a list of all function declarations
		/**/std::list<symbol_base *> bkn_production_stack;			/**///used to re-traverse cfg_tree, this part can be interated into cfg_tree when cfg_tree has more method to traverse it, other than visit_this.
		/**/std::map<string, std::map<int, symbol_base *> > func_name_idx2def;	/**///(name of function, (function index, function definition)) a map to map function and its index to its definition
		////end need to clean up
		std::map<string, symbol_base *>	nonrec_func2func_body;//(name of function, pointer to the definition of the function)

		std::list<symbol_base *> incomplete_rec_func_decl_list_base;//pointer to the objects(print_base) which has some data member not complete
		std::list<symbol_base *> incomplete_rec_func_decl_list_derived;//pointer to the objects(print_derived) which has some data member not complete
		std::map<long int, symbol_base *> incomplete_nonrec_func_decl_list;//(hash(production_name, production_idx)) pointer to the objects(print_derived) whose data field nonrec_func_decl_list is not complete yet.
		std::map<long int, symbol_base *> incomplete_func_list_cpp;//(hash(production_name, production_idx)) pointer to the objects(print_derived) whose data field function_list is not complete yet.
		////end for usr functions
		
		////def file
		std::list<name_n_idx> name_list;//name of class, type of class used to print def file
		////end def file
};

#endif
