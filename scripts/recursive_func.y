
%type <> bkn_rule_id
%type <> bkn_production
%type <> bkn_symbol
%type <> bkn_func_place_holder

%token <string>	name
%token <int>	cfg_type
%token <string>	func_name
%token <int>	func_index
%token <string>	rule_name
%token <int>	rule_idx
%token <int>	symb_idx

%function <nonrecursive>	get_rule_name
%function <nonrecursive>	get_rule_idx
%function <nonrecursive>	get_bkn_production

%function <recursive>		visit_this
%%

bkn_rule_id:
	%visit_this.1 rule_name rule_idx bkn_production
	%get_rule_name
	%get_rule_idx
	%get_bkn_production
	;

bkn_production:
	bkn_production bkn_symbol
|	bkn_production bkn_func_place_holder
|
	;

bkn_symbol:
	name cfg_type symb_idx %visit_this.2
	;

bkn_func_place_holder:
	func_name func_index %visit_this.3
	;
	
%%

string get_rule_name()
{
	return $1;
}

int get_rule_idx()
{
	return $2;
}

bkn_production* get_bkn_production()
{
	return $3;
}

void visit_this(recfunc_context & a_recfunc_context);

visit_this.1
{
	a_recfunc_context.p_func_def = NULL;
}

visit_this.2
{
	data_member_inst * p_data_member_inst = new data_member_inst;
	p_data_member_inst->set($3);
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

visit_this.3
{
	if(a_recfunc_context.func_name.compare($1) == 0)
	{
		std::map<string, std::map<int, symbol_base *> >::iterator it = 
			a_recfunc_context.func_name_idx2def.find($1);
		if(it == a_recfunc_context.func_name_idx2def.end())
		{
			cout<<"*** semantic error: there is no definition for"<<$1<<endl;
			assert(0);
		}else
		{
			std::map<int, symbol_base *>::iterator jt = (it->second).find($2);
			if(jt == (it->second).end())
			{
				cout<<"*** semantic error: there is no definition for"<<$1<<"."<<$2<<endl;
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


