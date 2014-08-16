

%type <> name_n_ptr

%token <int> ptr
%token <string> name

%%

name_n_ptr:
	name ptr
	;


