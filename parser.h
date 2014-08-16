#ifndef PARSER_H_
#define PARSER_H_

#include <list>
#include <string>
#include <map>

#include "./cfg_tree/symbol_base.h"
#include "./cfg_tree/cfg.h"

using std::list;
using std::string;
using std::map;

class parser
{
	public:
		parser (list<string> & a_str_stack);
		virtual ~parser ();
		
		cfg * get_tree();

		void on_grammar();
		void on_type_list();
		void on_token();
		void on_type();
		void on_rules_id();
		void on_rule_list();
		void on_rule();
		void on_branches();
		void on_branches_empty();
		void on_rules_str();
		
		////func related
		void on_func_def_rec(unsigned int is_empty_body);
		void on_func_def_nonrec(unsigned int is_empty_body);
		void on_func_body_lsymbol();
		void on_func_body_rsymbol();
		
		//new
		void on_cfg_n_func();
		void on_function();
		void on_func_id_list(unsigned int need_init);
		void on_func_decl();
		void on_func_decl_nonrec(unsigned int is_empty_body);
		void on_func_list();
		void on_rules_rec_func();
		void on_rules_nonrec_func();
		////
				
		////handle sytax errors
//		void on_rule_missing_colon();//difficult to handle this kind of error
//		void on_rule_missing_semicolon();
		void on_grammar_reversed();
		void on_grammar_missing_rules();
		void on_grammar_missing_types();
		////

	protected:
		string trim(const string & a_str);
		/*void clear_env_on_error();*/
		
#ifdef DEBUG
		void print_stacks();
#endif
	protected:
		enum pointer_type_e
		{
			T_RULE_LIST		= 4,
			T_RULE_DEF		= 5,
			T_PRODUCTIONS_LIST	= 6,
			T_PRODUCTION		= 7,
			T_FUNC_BODY		= 8,
			T_FUNC_DEF		= 9,
			T_FUNC_DEL		= 10,
			T_FUNC_LIST		= 11,
			T_FUNC_PLACE_HOLDER	= 12
		};
	
		struct ptr_pair
		{
			ptr_pair(symbol_base * a_ptr, pointer_type_e a_ptr_type);
			~ptr_pair();
			ptr_pair & operator = (const ptr_pair & a_ptr_pair);
			symbol_base *	ptr;
			pointer_type_e	ptr_type;
		};
	private:
		list<parser::ptr_pair> ptr_stack;
		list<string> & str_stack;
		
		cfg *	p_cfg;
		symbol_list tmp_symbol_list;
		
		int func_id_list_size;
};

#endif
