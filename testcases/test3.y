
%function <recursive>	rec
%function <nonrecursive> nonrec
%type	<>		A
%token	< int	>	bb
%token	<double>	cc
%type	<>		D

%%

A:
	%rec.1 bb "and" %rec.2 cc | %rec.3 D %nonrec
	;

D:
	"end"
	;

%%

void rec (const context & a_context);

rec.1
{
	$$ = aaaa;
	$1 = bbbb;
	cccccccccccccccccccc
	dddddddddddddddddddd
}

rec.2
{
	$$ = $1
}

rec.3
{
	$1 = ggggggggggggggggg;
}

void nonrec (unsigned long long int a_int)
{
	eeeeeeeeeeeeeeeeeee
}

