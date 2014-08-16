
//grammar
%type <> cfg
%type <> rule_list

%token <string> start
%token <string> symbol_name

%token <symbol_list> symbol_list
//end grammar

//rule
%type <> rule_def
%type <> productions_list
%type <> production
%type <> symbol
%type <> func_place_holder

%token <string> name
%token <int>	cfg_type
%token <long int> hash_code
//end rule

//function
%type <> func_body
%type <> func_list
%type <> func_def
%type <> func_decl

%token <string> return_value
%token <int>	func_type
%token <string> func_name
%token <int>	func_index
%token <string> func_parameter
%token <string> func_str
%token <int>	right_symbol
%token <int>	left_symbol
//%token <unsigned long int> func_hash_code //use as primary key for delayed assignment.Sensitive to func_name, return_value, func_index and func_parameter
//end function

//func
%function <recursive> visit_this
//
%%

//grammar
cfg:
	%visit_this.1 start symbol_list rule_list func_list %visit_this.2
	;
	
rule_list:
	rule_list rule_def
|
	;
//end grammar


//rule
rule_def:
	%visit_this.12 name productions_list %visit_this.13
	;

productions_list:
	%visit_this.9 productions_list %visit_this.10 production %visit_this.11
|
	;

production:
	production symbol
|	production func_place_holder
|
	;

symbol:
	name cfg_type %visit_this.14
	;

func_place_holder:
	func_type func_name func_index %visit_this.8
	;
//end rule

//function
func_list:
	func_list func_def
|	func_list func_decl
|
	;

func_decl:
	func_type return_value func_name func_parameter %visit_this.7
	;

func_def:
	func_type func_name func_index func_body %visit_this.6
	;

func_body:
	func_body func_str %visit_this.5
|	func_body right_symbol %visit_this.3
|	func_body left_symbol %visit_this.4	//not implemented
|
	;
//end function

%%

void visit_this(context & a_context);

visit_this.1
{
	a_context.p_symbol_list = & $2;
}

visit_this.2
{
	for (std::list<name_n_ptr>::iterator it = a_context.func_declarations.begin(); 
		it != a_context.func_declarations.end(); it ++)
	{
		if($2.get_symbol_type(it->name).cfg_type == SYM_RECURSIVE)
		{
			//recursive function declarations
			for (std::list<symbol_base *>::iterator jt = a_context.incomplete_rec_func_decl_list_base.begin()
					; jt != a_context.incomplete_rec_func_decl_list_base.end(); jt ++)
			{
				recursive_func_decl_list_base_c * p_recursive_func_decl_list_base = 
								new recursive_func_decl_list_base_c;
				p_recursive_func_decl_list_base->set(
					dynamic_cast<print_base_h *>(*jt)->obj_rfunc_decl_list_base, 
					dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->duplicate() );
				dynamic_cast<print_base_h *>(*jt)->obj_rfunc_decl_list_base = p_recursive_func_decl_list_base;
			}
			for (std::list<symbol_base *>::iterator jt = a_context.incomplete_rec_func_decl_list_derived.begin()
					; jt != a_context.incomplete_rec_func_decl_list_derived.end(); jt ++)
			{
				recursive_func_decl_list_derived_c * p_recursive_func_decl_list_derived = 
									new recursive_func_decl_list_derived_c;
									
				p_recursive_func_decl_list_derived->set(
					dynamic_cast<print_derived_h *>(*jt)->obj_rfunc_decl_list_derived, 
					dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->duplicate() );
				dynamic_cast<print_derived_h *>(*jt)->obj_rfunc_decl_list_derived = p_recursive_func_decl_list_derived;
			}
			//
			
			///recursive function definition
			string	production_name;
			int	production_idx;
			string	func_class_name;
			string	func_return_value = dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->get_return_value();
			string	func_parameter = dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->get_func_parameter();

			bkn_production * production_ptr;
			recfunc_context a_recfunc_context(a_context.func_name_idx2def);
			
			a_recfunc_context.func_name = it->name;
			for (std::list<symbol_base *>::iterator pt = a_context.bkn_production_stack.begin(); 
					pt != a_context.bkn_production_stack.end(); pt ++)
			{
				production_name	= dynamic_cast<bkn_rule_id *>(*pt)->get_rule_name();
				production_idx	= dynamic_cast<bkn_rule_id *>(*pt)->get_rule_idx();
				production_ptr	= dynamic_cast<bkn_rule_id *>(*pt)->get_bkn_production();
				std::map<long int, symbol_base *>::iterator mt = a_context.incomplete_func_list_cpp.
					find(name_n_idx::hash_code(production_name, production_idx) );
				if(mt != a_context.incomplete_func_list_cpp.end())
				{
					dynamic_cast<bkn_rule_id *>(*pt)->visit_this(a_recfunc_context);
					
					func_class_name = dynamic_cast<print_derived_cpp *>(mt->second)->get_class_name();//class name
					
					func_list_cpp_rec * p_func_list_cpp_rec = new func_list_cpp_rec;
					p_func_list_cpp_rec->set(
						dynamic_cast<print_derived_cpp *>(mt->second)->obj_func_list,
						func_return_value,
						func_class_name,
						it->name,
						func_parameter,
						dynamic_cast<recursive_func_def *>(a_recfunc_context.p_func_def)
								);
					//install data
					dynamic_cast<print_derived_cpp *>(mt->second)->obj_func_list = p_func_list_cpp_rec;
				}//else
				//{
					//bug: cout<<"*** internal error: production(name, idx) to pointer mapping failed"<<endl;
					//bug: assert(0);
					//this might be caused by empty production
					//ex.
					// A: b | ;
				//}
			}
			///end recursive function definition
		}else if($2.get_symbol_type(it->name).cfg_type == SYM_NONRECURSIVE)
		{
			std::map<string, name_n_idx>::iterator kt = a_context.nonrecfunc2prodction.find(it->name);
			//given a nonrecursive function and find the corresponding production
			if(kt != a_context.nonrecfunc2prodction.end()) 
			{
				///func declararion for class head file
				std::map<long int, symbol_base *>::iterator mt = a_context.incomplete_nonrec_func_decl_list.
					find(name_n_idx::hash_code((kt->second).name, (kt->second).idx) );
				//find the pointer to incomplete print_derived_h
				if(mt != a_context.incomplete_nonrec_func_decl_list.end())
				{
					
					nonrecursive_func_decl_list_c * p_nonrecursive_func_decl_list_c = new nonrecursive_func_decl_list_c;
					p_nonrecursive_func_decl_list_c->set(
						dynamic_cast<print_derived_h *>(mt->second)->obj_nonrfunc_decl_list,
						dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->duplicate() );
					dynamic_cast<print_derived_h *>(mt->second)->obj_nonrfunc_decl_list = p_nonrecursive_func_decl_list_c;
					
				}else
				{
					cout<<"*** internal error: production to pointer mapping failed"<<endl;
					assert(0);
				}
				///end decl
				
				///func_list for print_derived_cpp
				mt = a_context.incomplete_func_list_cpp.
					find(name_n_idx::hash_code((kt->second).name, (kt->second).idx) );
				if(mt != a_context.incomplete_func_list_cpp.end())
				{
					
					std::map<string, symbol_base *>::iterator it_func_body = a_context.nonrec_func2func_body.find(it->name);
					if(it_func_body == a_context.nonrec_func2func_body.end())
					{
						cout<<"*** semantic error: function "<<it->name<<" has not been defined"<<endl;
						assert(0);
					}
					
					func_list_cpp_nonrec * p_func_list_cpp_nonrec = new func_list_cpp_nonrec;
					p_func_list_cpp_nonrec->set(
						dynamic_cast<print_derived_cpp *>(mt->second)->obj_func_list,
						dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->get_return_value(),//return value
						dynamic_cast<print_derived_cpp *>(mt->second)->get_class_name(),//class name
						dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->get_func_name(),//func name
						dynamic_cast<printer_func_decl *>(it->ptr_symbol_base)->get_func_parameter(),//func parameter
						dynamic_cast<printer_func_def *>(it_func_body->second)//->duplicate()///printer_func_def
									);
					dynamic_cast<print_derived_cpp *>(mt->second)->obj_func_list = p_func_list_cpp_nonrec;
					
				}else
				{
					cout<<"*** internal error: production to pointer mapping failed"<<endl;
					assert(0);
				}
				///end func_list
			}else
			{
				cout<<"*** internal error: noncrecursive function to production mapping failed"<<endl;
				assert(0);
			}
		}
	}
}

visit_this.3
{
	data_member_inst * p_data_member_inst = new data_member_inst;
	p_data_member_inst->set($2);
	
	printer_func_def_data * p_printer_func_def_data = new printer_func_def_data;
	
	if(a_context.ptr_stack.back().ptr_type != T_PRINTER_FUNC_DEF)
	{
		p_printer_func_def_data->set(NULL, p_data_member_inst);
		a_context.ptr_stack.push_back(context::ptr_pair(p_printer_func_def_data, T_PRINTER_FUNC_DEF));
	}else
	{
		p_printer_func_def_data->set(dynamic_cast<printer_func_def *>(a_context.ptr_stack.back().ptr), p_data_member_inst);
		a_context.ptr_stack.back() = context::ptr_pair(p_printer_func_def_data, T_PRINTER_FUNC_DEF);
	}
}

visit_this.4
{
	cout<<"***warning: left symbol is not supported in this version"<<endl;
}

visit_this.5
{
	printer_func_def_str * p_printer_func_def_str = new printer_func_def_str;
	
	if(a_context.ptr_stack.back().ptr_type != T_PRINTER_FUNC_DEF)
	{
		p_printer_func_def_str->set(NULL, $2);
		a_context.ptr_stack.push_back(context::ptr_pair(p_printer_func_def_str, T_PRINTER_FUNC_DEF));
	}else
	{
		p_printer_func_def_str->set(dynamic_cast<printer_func_def *>(a_context.ptr_stack.back().ptr), $2);
		a_context.ptr_stack.back() = context::ptr_pair(p_printer_func_def_str, T_PRINTER_FUNC_DEF);
	}
}

visit_this.6
{
	std::map<string, symbol_base *>::iterator it;
	if($1 == SYM_NONRECURSIVE)
	{
		it = a_context.nonrec_func2func_body.find($2);
		if(it != a_context.nonrec_func2func_body.end())
		{
			cout<<"*** semantic error: Duplicated definition of nonrecursive function: "<<$2<<endl;
			assert(0);
		}
		assert(a_context.ptr_stack.back().ptr_type == T_PRINTER_FUNC_DEF);
		a_context.nonrec_func2func_body.insert(pair<string, symbol_base *>
				($2, dynamic_cast<printer_func_def *>(a_context.ptr_stack.back().ptr)));
		a_context.ptr_stack.pop_back();
	}else
	{//recursive functions
		//find the pair with the given name
		std::map<string, std::map<int, symbol_base *> >::iterator jt = a_context.func_name_idx2def.find($2);
		pair<std::map<string, std::map<int, symbol_base *> >::iterator, bool> ret;
		if(jt == a_context.func_name_idx2def.end())
		{
			ret = a_context.func_name_idx2def.insert(
				pair<string, std::map<int, symbol_base *> >($2, std::map<int, symbol_base *>() ));
			assert(ret.second == true);
			jt = ret.first;
		}
		
		//find the pointer with the given index
		std::map<int, symbol_base *>::iterator kt = (jt->second).find($3);
		if(kt == (jt->second).end())
		{
			(jt->second).insert(pair<int, symbol_base *>
				($3, dynamic_cast<printer_func_def *>(a_context.ptr_stack.back().ptr)));
		}else
		{
			cout<<"*** semantic error: duplicated recursive function definition: "<<$2<<"."<<$3<<endl;
		}
		a_context.ptr_stack.pop_back();
	}
}

visit_this.7
{
	printer_func_decl * p_printer_func_decl = new printer_func_decl;
	p_printer_func_decl->set($2, $3, $4);
	a_context.func_declarations.push_back(name_n_ptr($3, p_printer_func_decl));
}

visit_this.8
{
	if($1 == SYM_NONRECURSIVE)
	{
		a_context.nonrecfunc2prodction.insert(
			pair<string, name_n_idx>($2, name_n_idx(a_context.production_name, a_context.production_idx)));
	}else
	{
		////recusive func def bkn
		bkn_func_place_holder * p_bkn_func_place_holder = new bkn_func_place_holder;
		p_bkn_func_place_holder->set($2, $3);
		
		bkn_production_func * p_bkn_production_func = new bkn_production_func;
		p_bkn_production_func->set(dynamic_cast<bkn_rule_id *>(a_context.bkn_production_stack.back())->get_bkn_production(), p_bkn_func_place_holder);
		dynamic_cast<bkn_rule_id *>(a_context.bkn_production_stack.back())->m_3 = p_bkn_production_func;
		////end recusive func def bkn
	}
}

visit_this.9
{
	a_context.production_counter++;
}

visit_this.10
{
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
}

visit_this.11
{
	if( $2 != NULL)
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

visit_this.12
{
	a_context.production_name = $1;
	a_context.production_idx = 0;
	a_context.production_counter = 0;
}

visit_this.13
{
	if(a_context.production_counter == 0 || a_context.production_counter > 1)
	{//a base class is necessary
		std::string class_name = $1;
		std::string name_upper = class_name;
		stringstream ss;
		ss<<GLOBAL_DEF_H "_"<<&a_context;
		transform(name_upper.begin(), name_upper.end(), name_upper.begin(), ::toupper);
		
		print_base_h * p_print_base_h = new print_base_h;
		p_print_base_h->set(
					name_upper,
					name_upper,
					ss.str(),
					BASE_CLASS,
					name_upper,
					class_name,
					BASE_CLASS,
					name_upper,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					class_name,
					NULL,//recursive_func_del_list
					name_upper
					);
		a_context.for_print.push_back(name_n_ptr(class_name+".h", p_print_base_h));
		a_context.incomplete_rec_func_decl_list_base.push_back(p_print_base_h);
		
		////def file
		a_context.name_list.push_back(name_n_idx(class_name, DEF_BASE));
		////end def file
	}
}

visit_this.14
{
	assert(a_context.p_symbol_list != NULL);
	
	std::string class_name = a_context.production_name;
	std::stringstream ss;
	if(a_context.production_counter != 1)//at least 2 productions
	{//if only one production, so the index is not necessary
		ss<<a_context.production_idx;
		class_name += ss.str();
	}
	
	if($2 == SYM_TYPE || $2 == SYM_TOKEN)
	{
		a_context.symbol_idx++;
	}
	unsigned int idx = a_context.symbol_idx;
	
	data_member_inst * p_data_member_inst;
	arg_type_type * p_arg_type_type;
	arg_type_token * p_arg_type_token;
	
	
//	visit_list * p_last_visit_list		= dynamic_cast<visit_list *>(a_context.p_last[VISIT_LIST_IDX]);
	duplicate_list * p_last_duplicate_list	= dynamic_cast<duplicate_list *>(a_context.p_last[DUPLICATE_LIST_IDX]);
	copy_list * p_last_copy_list		= dynamic_cast<copy_list *>(a_context.p_last[COPY_LIST_IDX]);
	deconstruction_list_c * p_last_deconstruction_list_c	= dynamic_cast<deconstruction_list_c *>(a_context.p_last[DECONSTRUCTION_LIST_IDX]);
	construction_list_c * p_last_construction_list_c	= dynamic_cast<construction_list_c *>(a_context.p_last[CONSTRUCTION_LIST_IDX]);
	print_list * p_last_print_list		= dynamic_cast<print_list *>(a_context.p_last[PRINT_LIST_IDX]);
	set_list_c * p_last_set_list_c				= dynamic_cast<set_list_c *>(a_context.p_last[SET_LIST_IDX]);
	include_file_list * p_last_include_file_list	= dynamic_cast<include_file_list *>(a_context.p_last[INCLUDE_FILE_LIST_IDX]);
	set_method_arg_list * p_last_set_method_arg_list	= dynamic_cast<set_method_arg_list *>(a_context.p_last[SET_METHOD_ARG_LIST_IDX]);
	data_member_list * p_last_data_member_list		= dynamic_cast<data_member_list *>(a_context.p_last[DATA_MEMBER_LIST_IDX]);
	
//	visit_list_type * p_visit_list_type		;
	duplicate_list_type * p_duplicate_list_type	;
	copy_list_type * p_copy_list_type		;
	deconstruction_list_c * p_deconstruction_list_c	;
	construction_list_c * p_construction_list_c	;
	print_list_type * p_print_list_type		;
	set_list_c * p_set_list_c			;
	data_member_list_type * p_data_member_list_type	;
	
	set_method_arg_list_first * p_set_method_arg_list_first	;
	set_method_arg_list_other * p_set_method_arg_list_other	;
	
	include_file_list_usr * p_include_file_list_usr	;
	include_file_list_std * p_include_file_list_std	;

	duplicate_list_token * p_duplicate_list_token	;
	copy_list_token * p_copy_list_token		;
//	deconstruction_list_c * p_deconstruction_list_c	;
//	construction_list_c * p_construction_list_c	;
	print_list_token * p_print_list_token		;
//	set_list_c * p_set_list_c			;
//	include_file_list_c * p_include_file_list_c	;
//	set_method_arg_list_c * p_set_method_arg_list_c	;
	data_member_list_token * p_data_member_list_token;
	
	print_list_str * p_print_list_str		;
			
	switch($2)
	{
		case SYM_TYPE:
			p_data_member_inst 	= new data_member_inst;
			p_data_member_inst	->set(idx);
			p_arg_type_type		= new arg_type_type;
			p_arg_type_type		->set($1);
			
//			p_visit_list_type	= new visit_list_type;
			p_duplicate_list_type	= new duplicate_list_type;
			p_copy_list_type	= new copy_list_type;
			p_deconstruction_list_c	= new deconstruction_list_c;
			p_construction_list_c	= new construction_list_c;
			p_print_list_type	= new print_list_type;
			p_set_list_c		= new set_list_c;
			p_include_file_list_usr	= new include_file_list_usr;
			p_data_member_list_type	= new data_member_list_type;
			
			if(idx == 1)
			{
				p_set_method_arg_list_first = new set_method_arg_list_first;
				p_set_method_arg_list_first->set(p_last_set_method_arg_list, p_arg_type_type, p_data_member_inst->duplicate());
				a_context.p_last[SET_METHOD_ARG_LIST_IDX] =p_set_method_arg_list_first;
			}else
			{
				p_set_method_arg_list_other = new set_method_arg_list_other;
				p_set_method_arg_list_other->set(p_last_set_method_arg_list, p_arg_type_type, p_data_member_inst->duplicate());
				a_context.p_last[SET_METHOD_ARG_LIST_IDX] =p_set_method_arg_list_other;
			}
			
//			p_visit_list_type	->set(p_last_visit_list, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_duplicate_list_type	->set(p_last_duplicate_list, p_data_member_inst->duplicate(), p_data_member_inst->duplicate(), p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_copy_list_type	->set(p_last_copy_list, p_data_member_inst->duplicate(), p_data_member_inst->duplicate(), class_name, p_data_member_inst->duplicate(), p_data_member_inst->duplicate(), class_name, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_deconstruction_list_c	->set(p_last_deconstruction_list_c, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_construction_list_c	->set(p_last_construction_list_c, p_data_member_inst->duplicate());
			p_print_list_type	->set(p_last_print_list, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_set_list_c		->set(p_last_set_list_c, NULL, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_include_file_list_usr	->set(p_last_include_file_list, $1);
			p_data_member_list_type	->set(p_last_data_member_list, /*(a_context.p_symbol_list->get_symbol_type(name0)).usr_type*/$1, p_data_member_inst/*->duplicate()*/, $1);
			
//			a_context.p_last[VISIT_LIST_IDX] =	p_visit_list_type	;
			a_context.p_last[DUPLICATE_LIST_IDX] =	p_duplicate_list_type	;
			a_context.p_last[COPY_LIST_IDX] =	p_copy_list_type	;
			a_context.p_last[DECONSTRUCTION_LIST_IDX] =p_deconstruction_list_c;
			a_context.p_last[CONSTRUCTION_LIST_IDX] =p_construction_list_c	;
			a_context.p_last[PRINT_LIST_IDX] =	p_print_list_type	;
			a_context.p_last[SET_LIST_IDX] =	p_set_list_c		;
			a_context.p_last[INCLUDE_FILE_LIST_IDX] =p_include_file_list_usr;
			a_context.p_last[DATA_MEMBER_LIST_IDX] =p_data_member_list_type	;
		break;
		
		case SYM_TOKEN:
			p_data_member_inst 	= new data_member_inst;
			p_data_member_inst->set(idx);
			p_arg_type_token	= new arg_type_token;
			p_arg_type_token	->set((a_context.p_symbol_list->get_symbol_type($1)).usr_type);

			if(!a_context.is_build_in((a_context.p_symbol_list->get_symbol_type($1)).usr_type))
			{// not a build in type, need to include a head file
				string a_type = a_context.p_symbol_list->get_symbol_type($1).usr_type;
				if(a_context.is_std_type(a_type) != 0)
				{
					p_include_file_list_std	= new include_file_list_std;
					p_include_file_list_std	->set(p_last_include_file_list, a_type);
					a_context.p_last[INCLUDE_FILE_LIST_IDX] =p_include_file_list_std;
				}//else{ user will decide what to include }
			}

			p_duplicate_list_token	= new duplicate_list_token;
			p_copy_list_token	= new copy_list_token;
//			p_deconstruction_list_c	= p_last_deconstruction_list_c;//not used
//			p_construction_list_c	= p_last_construction_list_c;//not used
			p_print_list_token	= new print_list_token;
			p_set_list_c		= new set_list_c;
//			p_set_method_arg_list_c	= new set_method_arg_list_c;
			p_data_member_list_token= new data_member_list_token;
			
			if(idx == 1)
			{
				p_set_method_arg_list_first = new set_method_arg_list_first;
				p_set_method_arg_list_first->set(p_last_set_method_arg_list, p_arg_type_token, p_data_member_inst->duplicate());
				a_context.p_last[SET_METHOD_ARG_LIST_IDX] =p_set_method_arg_list_first;
			}else
			{
				p_set_method_arg_list_other = new set_method_arg_list_other;
				p_set_method_arg_list_other->set(p_last_set_method_arg_list, p_arg_type_token, p_data_member_inst->duplicate());
				a_context.p_last[SET_METHOD_ARG_LIST_IDX] =p_set_method_arg_list_other;
			}
			
			p_duplicate_list_token	->set(p_last_duplicate_list, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
			p_copy_list_token	->set(p_last_copy_list, p_data_member_inst->duplicate(), class_name, p_data_member_inst->duplicate());
//			p_deconstruction_list_c	->set(p_last_deconstruction_c);
//			p_construction_list_c	->set(p_last_construction_c);
			p_print_list_token	->set(p_last_print_list, p_data_member_inst->duplicate());
			p_set_list_c		->set(p_last_set_list_c, NULL, p_data_member_inst->duplicate(), p_data_member_inst->duplicate());
//			p_set_method_arg_list_c	->set(p_last_set_method_arg_list, p_arg_type_token, p_data_member_inst->duplicate());
			p_data_member_list_token->set(p_last_data_member_list, (a_context.p_symbol_list->get_symbol_type($1)).usr_type, p_data_member_inst/*->duplicate()*/, $1);
			
			a_context.p_last[DUPLICATE_LIST_IDX] =	p_duplicate_list_token;
			a_context.p_last[COPY_LIST_IDX] =	p_copy_list_token;
//			a_context.p_last[DECONSTRUCTION_LIST_IDX] =p_deconstruction_list_c;
//			a_context.p_last[CONSTRUCTION_LIST_IDX] =p_construction_list_c;
			a_context.p_last[PRINT_LIST_IDX] =	p_print_list_token;
			a_context.p_last[SET_LIST_IDX] =	p_set_list_c;
//			a_context.p_last[INCLUDE_FILE_LIST_IDX] =p_include_file_list_std;//modified
//			a_context.p_last[SET_METHOD_ARG_LIST_IDX] =p_set_method_arg_list_c;
			a_context.p_last[DATA_MEMBER_LIST_IDX] =p_data_member_list_token;
		break;
		
		case SYM_STR:
			p_print_list_str	= new print_list_str;
			p_print_list_str	->set(p_last_print_list, "\""+$1+"\"");
			a_context.p_last[PRINT_LIST_IDX] = p_print_list_str;
		break;
		
		default://SYM_UNKNOWN
			cout<<"*** internal error: unknown symbol type"<<endl;
			assert(0);
		break;
	}
	
	
	////recusive func def bkn
	if($2 == SYM_TYPE)
	{
		bkn_symbol * p_bkn_symbol = new bkn_symbol;
		p_bkn_symbol->set($1, $2, idx);
		
		bkn_production_symb * p_bkn_production_symb = new bkn_production_symb;
		p_bkn_production_symb->set(dynamic_cast<bkn_rule_id *>(a_context.bkn_production_stack.back())->get_bkn_production(), p_bkn_symbol);
		dynamic_cast<bkn_rule_id *>(a_context.bkn_production_stack.back())->m_3 = p_bkn_production_symb;
	}
	////end recusive func def bkn
}
