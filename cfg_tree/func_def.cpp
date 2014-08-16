#include "func_def.h"
#include "cfg_printer_defs.h"
FUNC_DEF_DERIVED_CPP_USR_DEF
func_def::func_def()
{
	m_4 = NULL;
}
func_def::func_def(const func_def & a_func_def)
{
	m_1 = a_func_def.m_1;
	m_2 = a_func_def.m_2;
	m_3 = a_func_def.m_3;
	if( m_4!= NULL )
	{
		delete m_4;
	}
	if(a_func_def.m_4 != NULL)
	{
		m_4 = a_func_def.m_4->duplicate();
	}else{
		m_4 = NULL;
	}
}
func_def::~func_def()
{
	if( m_4!= NULL )
	{
		delete m_4;
	}
}
func_def & func_def::operator = (const func_def & a_func_def)
{
	if(this == & a_func_def)
		return *this;
	m_1 = a_func_def.m_1;
	m_2 = a_func_def.m_2;
	m_3 = a_func_def.m_3;
	if( m_4!= NULL )
	{
		delete m_4;
	}
	if(a_func_def.m_4 != NULL)
	{
		m_4 = a_func_def.m_4->duplicate();
	}else{
		m_4 = NULL;
	}
	return *this;
}
void func_def::print_this(std::ostream & out)
{
	out<<m_1;
	out<<m_2;
	out<<m_3;
	if( m_4!= NULL )
	{
		m_4->print_this(out);
	}
}
void func_def::set(const int &  a_m_1, const string &  a_m_2, const int &  a_m_3, func_body *  a_m_4)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
	m_3 = a_m_3;
	m_4 = a_m_4;
}
func_def * func_def::duplicate()
{
	func_def * a_copy = new func_def;
	a_copy->m_1 = m_1;
	a_copy->m_2 = m_2;
	a_copy->m_3 = m_3;
	if( m_4!= NULL )
	{
		a_copy->m_4 = m_4->duplicate();
	}else{
		m_4 = NULL;
	}
	return a_copy;
}
void func_def::visit_this(context & a_context)
{
	if( m_4!= NULL )
	{
		m_4->visit_this(a_context);
	}

	std::map<string, symbol_base *>::iterator it;
	if(m_1 == SYM_NONRECURSIVE)
	{
		it = a_context.nonrec_func2func_body.find(m_2);
		if(it != a_context.nonrec_func2func_body.end())
		{
			cout<<"*** semantic error: Duplicated definition of nonrecursive function: "<<m_2<<endl;
			assert(0);
		}
		assert(a_context.ptr_stack.back().ptr_type == T_PRINTER_FUNC_DEF);
		a_context.nonrec_func2func_body.insert(pair<string, symbol_base *>
				(m_2, dynamic_cast<printer_func_def *>(a_context.ptr_stack.back().ptr)));
		a_context.ptr_stack.pop_back();
	}else
	{//recursive functions
		//find the pair with the given name
		std::map<string, std::map<int, symbol_base *> >::iterator jt = a_context.func_name_idx2def.find(m_2);
		pair<std::map<string, std::map<int, symbol_base *> >::iterator, bool> ret;
		if(jt == a_context.func_name_idx2def.end())
		{
			ret = a_context.func_name_idx2def.insert(
				pair<string, std::map<int, symbol_base *> >(m_2, std::map<int, symbol_base *>() ));
			assert(ret.second == true);
			jt = ret.first;
		}
		
		//find the pointer with the given index
		std::map<int, symbol_base *>::iterator kt = (jt->second).find(m_3);
		if(kt == (jt->second).end())
		{
			(jt->second).insert(pair<int, symbol_base *>
				(m_3, dynamic_cast<printer_func_def *>(a_context.ptr_stack.back().ptr)));
		}else
		{
			cout<<"*** semantic error: duplicated recursive function definition: "<<m_2<<"."<<m_3<<endl;
		}
		a_context.ptr_stack.pop_back();
	}
}
