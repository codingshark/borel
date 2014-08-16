

%type <> name_n_ptr
%token <symbol_base> ptr
%token <string> name

%%

name_n_ptr:
	name ptr
	;
