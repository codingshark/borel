%type <> A
%token <int> b

%function <recursive> visit
%function <nonrecursive> func
%function <nonrecersive> func_b
%%

/*
novel writer
*/

A:
	%visit.1 b b
	%func
	%func_b
	;
	
%%

int[7584798] int <double> * & visit();

visit.1
{
	return $1;
}

void * func()
{
	return NULL;
}

unsigned int func_b()
{
	return 0;
}
