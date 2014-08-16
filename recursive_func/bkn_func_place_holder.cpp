#include "bkn_func_place_holder.h"
#include "cfg_printer_defs.h"
BKN_FUNC_PLACE_HOLDER_DERIVED_CPP_USR_DEF
bkn_func_place_holder::bkn_func_place_holder()
{
}
bkn_func_place_holder::bkn_func_place_holder(const bkn_func_place_holder & a_bkn_func_place_holder)
{
	m_1 = a_bkn_func_place_holder.m_1;
	m_2 = a_bkn_func_place_holder.m_2;
}
bkn_func_place_holder::~bkn_func_place_holder()
{
}
bkn_func_place_holder & bkn_func_place_holder::operator = (const bkn_func_place_holder & a_bkn_func_place_holder)
{
	if(this == & a_bkn_func_place_holder)
		return *this;
	m_1 = a_bkn_func_place_holder.m_1;
	m_2 = a_bkn_func_place_holder.m_2;
	return *this;
}
void bkn_func_place_holder::print_this(std::ostream & out)
{
	out<<m_1;
	out<<m_2;
}
void bkn_func_place_holder::set(const string &  a_m_1, const int &  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
bkn_func_place_holder * bkn_func_place_holder::duplicate()
{
	bkn_func_place_holder * a_copy = new bkn_func_place_holder;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	return a_copy;
}
void bkn_func_place_holder::visit_this(recfunc_context & a_recfunc_context)
{

	if(a_recfunc_context.func_name.compare(m_1) == 0)
	{
		std::map<string, std::map<int, symbol_base *> >::iterator it = 
			a_recfunc_context.func_name_idx2def.find(m_1);
		if(it == a_recfunc_context.func_name_idx2def.end())
		{
			cout<<"*** semantic error: there is no definition for"<<m_1<<endl;
			assert(0);
		}else
		{
			std::map<int, symbol_base *>::iterator jt = (it->second).find(m_2);
			if(jt == (it->second).end())
			{
				cout<<"*** semantic error: there is no definition for"<<m_1<<"."<<m_2<<endl;
				assert(0);
			}else
			{
				recursive_func_def_func * p_recursive_func_def_func = new recursive_func_def_func;
				p_recursive_func_def_func->set(
					dynamic_cast<recursive_func_def *>(a_recfunc_context.p_func_def),
					dynamic_cast<printer_func_def *>(jt->second)->duplicate()
								);
				a_recfunc_context.p_func_def = p_recursive_func_def_func;
			}
		}
	}
}
