#include "func_place_holder.h"
#include "cfg_printer_defs.h"

FUNC_PLACE_HOLDER_DERIVED_CPP_USR_DEF
func_place_holder::func_place_holder()
{
}
func_place_holder::func_place_holder(const func_place_holder & a_func_place_holder)
{
	m_1 = a_func_place_holder.m_1;
	m_2 = a_func_place_holder.m_2;
	m_3 = a_func_place_holder.m_3;
}
func_place_holder::~func_place_holder()
{
}
func_place_holder & func_place_holder::operator = (const func_place_holder & a_func_place_holder)
{
	if(this == & a_func_place_holder)
		return *this;
	m_1 = a_func_place_holder.m_1;
	m_2 = a_func_place_holder.m_2;
	m_3 = a_func_place_holder.m_3;
	return *this;
}
void func_place_holder::print_this(std::ostream & out)
{
	out<<m_1;
	out<<m_2;
	out<<m_3;
}
void func_place_holder::set(const int &  a_m_1, const string &  a_m_2, const int &  a_m_3)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
}
func_place_holder * func_place_holder::duplicate()
{
	func_place_holder * a_copy = new func_place_holder;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	a_copy->m_3 = m_3;
	return a_copy;
}
void func_place_holder::visit_this(context & a_context)
{

	if(m_1 == SYM_NONRECURSIVE)
	{
		a_context.nonrecfunc2prodction.insert(
			pair<string, name_n_idx>(m_2, name_n_idx(a_context.production_name, a_context.production_idx)));
	}else
	{
		////recusive func def bkn
		bkn_func_place_holder * p_bkn_func_place_holder = new bkn_func_place_holder;
		p_bkn_func_place_holder->set(m_2, m_3);
		
		bkn_production_func * p_bkn_production_func = new bkn_production_func;
		p_bkn_production_func->set(dynamic_cast<bkn_rule_id *>(a_context.bkn_production_stack.back())->get_bkn_production(), p_bkn_func_place_holder);
		dynamic_cast<bkn_rule_id *>(a_context.bkn_production_stack.back())->m_3 = p_bkn_production_func;
		////end recusive func def bkn
	}
}
