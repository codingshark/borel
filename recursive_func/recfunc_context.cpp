#include "recfunc_context.h"

recfunc_context::recfunc_context (std::map<std::string, std::map<int, symbol_base *> > & a_map):
func_name_idx2def(a_map)
{
}

recfunc_context::~recfunc_context ()
{
}

