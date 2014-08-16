#include "productions_list1.h"
#include "cfg_printer_defs.h"
#include <algorithm>
PRODUCTIONS_LIST1_DERIVED_CPP_USR_DEF
productions_list1::productions_list1()
{
	m_1 = NULL;
	m_2 = NULL;
}
productions_list1::productions_list1(const productions_list1 & a_productions_list1)
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_productions_list1.m_1 != NULL)
	{
		m_1 = a_productions_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_productions_list1.m_2 != NULL)
	{
		m_2 = a_productions_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
}
productions_list1::~productions_list1()
{
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
}
productions_list1 & productions_list1::operator = (const productions_list1 & a_productions_list1)
{
	if(this == & a_productions_list1)
		return *this;
	if( m_1!= NULL )
	{
		delete m_1;
	}
	if(a_productions_list1.m_1 != NULL)
	{
		m_1 = a_productions_list1.m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		delete m_2;
	}
	if(a_productions_list1.m_2 != NULL)
	{
		m_2 = a_productions_list1.m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return *this;
}
void productions_list1::print_this(std::ostream & out)
{
	if( m_1!= NULL )
	{
		m_1->print_this(out);
	}
	if( m_2!= NULL )
	{
		m_2->print_this(out);
	}
}
void productions_list1::set(productions_list *  a_m_1, production *  a_m_2)
{
	m_1 = a_m_1;
	m_2 = a_m_2;
}
productions_list1 * productions_list1::duplicate()
{
	productions_list1 * a_copy = new productions_list1;
	if( m_1!= NULL )
	{
		a_copy->m_1 = m_1->duplicate();
	}else{
		m_1 = NULL;
	}
	if( m_2!= NULL )
	{
		a_copy->m_2 = m_2->duplicate();
	}else{
		m_2 = NULL;
	}
	return a_copy;
}
void productions_list1::visit_this(context & a_context)
{

	a_context.production_counter++;
	if( m_1!= NULL )
	{
		m_1->visit_this(a_context);
	}

	a_context.symbol_idx = 0;
	for (unsigned int i = 0; i < CONTEXT_P_LAST_SIZE; i += 1)
	{
		a_context.p_last[i] = NULL;
	}
	a_context.production_idx++;
	
	////recusive func def bkn
	bkn_rule_id * p_bkn_rule_id = new bkn_rule_id;
	p_bkn_rule_id->set(a_context.production_name, a_context.production_idx, NULL);
	a_context.bkn_production_stack.push_back(p_bkn_rule_id);
	////end recusive func def bkn
	if( m_2!= NULL )
	{
		m_2->visit_this(a_context);
	}

	if( m_2 != NULL)
	{
		std::string class_name = a_context.production_name;
		std::stringstream ss;
		
		include_file_list_usr * p_include_file_list_usr = NULL;
		
		string base_class_of_derived = BASE_CLASS;//the default base class
		if(a_context.production_counter != 1)//at least 2 productions
		{//if only one production, so the index is not necessary
			ss<<a_context.production_idx;
			class_name += ss.str();
			
			//the derived class need to include base class
			base_class_of_derived = a_context.production_name;
			p_include_file_list_usr	= new include_file_list_usr;
			p_include_file_list_usr->set(dynamic_cast<include_file_list *>(a_context.p_last[INCLUDE_FILE_LIST_IDX]), base_class_of_derived);
			a_context.p_last[INCLUDE_FILE_LIST_IDX] = p_include_file_list_usr;
		}

		std::string name_upper = class_name;
		transform(name_upper.begin(), name_upper.end(), name_upper.begin(), ::toupper);
		
		print_derived_h * p_print_derived_h	= new print_derived_h;
		print_derived_cpp * p_print_derived_cpp	= new print_derived_cpp;
		
		ss.str("");
		ss<<GLOBAL_DEF_H "_"<<&a_context;
		p_print_derived_h->set(
					name_upper,
					name_upper,
					ss.str(),
					BASE_CLASS,
					dynamic_cast<include_file_list *>(a_context.p_last[INCLUDE_FILE_LIST_IDX]),//include_file_list
					name_upper,
					class_name,
					base_class_of_derived,
					name_upper,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					dynamic_cast<set_method_arg_list *>(a_context.p_last[SET_METHOD_ARG_LIST_IDX]),//set_method_arg_list
					class_name,
					NULL,//recursive_func_decl_list
					NULL,//nonrecursive_func_decl_list
					dynamic_cast<data_member_list *>(a_context.p_last[DATA_MEMBER_LIST_IDX]),//data_member_list
					name_upper
					);
		
		copy_list * p_copy_list = dynamic_cast<copy_list *>(a_context.p_last[COPY_LIST_IDX]);//copy_list
		set_method_arg_list * p_set_method_arg_list = dynamic_cast<set_method_arg_list *>(a_context.p_last[SET_METHOD_ARG_LIST_IDX]);//set_method_arg_list
		
		
		p_print_derived_cpp->set(
					class_name,
					name_upper,
					class_name,
					class_name,
					dynamic_cast<construction_list *>(a_context.p_last[CONSTRUCTION_LIST_IDX]),//construction_list
					class_name,
					class_name,
					class_name,
					class_name,
					dynamic_cast<copy_list *>(a_context.p_last[COPY_LIST_IDX]),//copy_list
					class_name,
					class_name,
					dynamic_cast<deconstruction_list *>(a_context.p_last[DECONSTRUCTION_LIST_IDX]),//deconstruction_list
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					(p_copy_list == NULL) ? NULL : p_copy_list->duplicate(),
					class_name,
					dynamic_cast<print_list *>(a_context.p_last[PRINT_LIST_IDX]),//print_list
					class_name,
					(p_set_method_arg_list == NULL) ? NULL : p_set_method_arg_list->duplicate(), 
					dynamic_cast<set_list *>(a_context.p_last[SET_LIST_IDX]),//set_list
//					class_name,
//					dynamic_cast<visit_list *>(a_context.p_last[VISIT_LIST_IDX]),//visit_list
					class_name,
					class_name,
					class_name,
					class_name,
					dynamic_cast<duplicate_list *>(a_context.p_last[DUPLICATE_LIST_IDX]),//duplicate_list
					NULL//func_list_cpp
					);
/*		p_print_derived_h->print_this(cout);
		p_print_derived_cpp->print_this(cout);
		delete p_print_derived_h;
		delete p_print_derived_cpp;*/
		a_context.for_print.push_back(name_n_ptr(class_name+".h",p_print_derived_h));
		a_context.for_print.push_back(name_n_ptr(class_name+".cpp",p_print_derived_cpp));
		a_context.incomplete_rec_func_decl_list_derived.push_back(p_print_derived_h);

		//insert incomplete object pointer into container, these objects will be processed later
		std::map<long int, symbol_base *>::iterator it = a_context.incomplete_nonrec_func_decl_list.find(name_n_idx::hash_code(a_context.production_name, a_context.production_idx));
		if(it != a_context.incomplete_nonrec_func_decl_list.end())
		{
			cout<<"*** internal error: hashcode confliction"<<endl;
			assert(0);
		}else
		{
			a_context.incomplete_nonrec_func_decl_list.insert(
				pair<long int, symbol_base *>
					(name_n_idx::hash_code(a_context.production_name, a_context.production_idx), p_print_derived_h));
		}
		
		it = a_context.incomplete_func_list_cpp.find(name_n_idx::hash_code(a_context.production_name, a_context.production_idx));
		if(it != a_context.incomplete_func_list_cpp.end())
		{
			cout<<"*** internal error: hashcode confliction"<<endl;
			assert(0);
		}else
		{
			a_context.incomplete_func_list_cpp.insert(
				pair<long int, symbol_base *>
					(name_n_idx::hash_code(a_context.production_name, a_context.production_idx), p_print_derived_cpp));
		}
		
		////def file
		a_context.name_list.push_back(name_n_idx(class_name, DEF_DERIVED));
		////end def file
	}
}
