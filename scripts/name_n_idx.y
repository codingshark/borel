

%type <> name_n_idx
%token <string> name
%token <int> idx

%%

name_n_idx:
	name idx
	;
