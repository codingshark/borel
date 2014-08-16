#ifndef BACKEND_H_
#define BACKEND_H_

#include <string>

#include "./cfg_tree/symbol_base.h"
#include "./cfg_tree/cfg.h"
#include "./utils/context.h"

using std::string;

class backend
{
	public:
		backend (cfg * a_cfg_ptr);
		virtual ~backend ();

		void generate_output();

	protected:
		
		void print_to_file(const string & a_file_name, symbol_base * p_symb);
		
		void print_def_file(const context & a_context);
	private:
		cfg * p_cfg;
};

#endif
