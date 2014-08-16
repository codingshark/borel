#ifndef SYMBOL_BASE_H_
#define SYMBOL_BASE_H_

#include <ostream>
#include <assert.h>

class symbol_base
{
	public:
		symbol_base();
		virtual ~symbol_base ();

		virtual void print_this(std::ostream & out)=0;

#ifdef DEBUG
		static unsigned int obj_counter;//used to detect memory leak
#endif

};

#endif
