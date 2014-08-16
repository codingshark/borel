#include "symbol_base.h"

#ifdef DEBUG

unsigned int symbol_base::obj_counter = 0;

symbol_base::symbol_base()
{
	obj_counter++;
}

symbol_base::~symbol_base ()
{
	obj_counter--;
}

#else
symbol_base::symbol_base(){}
symbol_base::~symbol_base (){}

#endif
