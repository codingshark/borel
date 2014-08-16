#include "bkn_symbol.h"
#include "cfg_printer_defs.h"
BKN_SYMBOL_DERIVED_CPP_USR_DEF
bkn_symbol::bkn_symbol()
{
}
bkn_symbol::bkn_symbol(const bkn_symbol & a_bkn_symbol)
{
	m_1 = a_bkn_symbol.m_1;
	m_2 = a_bkn_symbol.m_2;
	m_3 = a_bkn_symbol.m_3;
}
bkn_symbol::~bkn_symbol()
{
}
bkn_symbol & bkn_symbol::operator = (const bkn_symbol & a_bkn_symbol)
{
	if(this == & a_bkn_symbol)
		return *this;
	m_1 = a_bkn_symbol.m_1;
	m_2 = a_bkn_symbol.m_2;
	m_3 = a_bkn_symbol.m_3;
	return *this;
}
void bkn_symbol::print_this(std::ostream & out)
{
	out<<m_1;
	out<<m_2;
	out<<m_3;
}
void bkn_symbol::set(const string &  a_m_1, const int &  a_m_2, const int &  a_m_3)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
}
bkn_symbol * bkn_symbol::duplicate()
{
	bkn_symbol * a_copy = new bkn_symbol;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	a_copy->m_3 = m_3;
	return a_copy;
}
void bkn_symbol::visit_this(recfunc_context & a_recfunc_context)
{

	data_member_inst * p_data_member_inst = new data_member_inst;
	p_data_member_inst->set(m_3);
	recursive_func_def_data * p_recursive_func_def_data = new recursive_func_def_data;
	p_recursive_func_def_data->set(
		dynamic_cast<recursive_func_def *>(a_recfunc_context.p_func_def),
		p_data_member_inst,
		p_data_member_inst->duplicate(),
		a_recfunc_context.func_name,
		a_recfunc_context.func_parameter
					);
	a_recfunc_context.p_func_def = p_recursive_func_def_data;
}
