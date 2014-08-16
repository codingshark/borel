#ifndef RECFUNC_CONTEXT_H_
#define RECFUNC_CONTEXT_H_

#include <string>
#include <map>

#include "symbol_base.h"

class recfunc_context
{
	public:
		recfunc_context (std::map<std::string, std::map<int, symbol_base *> > & a_map);
		virtual ~recfunc_context ();

	public:
		std::string	func_name;//function that in processing
		std::string	func_parameter;
		
		std::map<std::string, std::map<int, symbol_base *> > & func_name_idx2def;
		
		symbol_base *	p_func_def;
};

#endif
