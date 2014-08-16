
%type <> A
%type <> B
%type <> C
%type <> D

%type <> E
%type <> F
%type <> G
%type <> H

%token <int> K

%%

E:
	A B C D | "hello" | K
	;

F:
	| K
	;

G:	E C | K "world"
	;

H:	
	"yes"
	;

M:	G H|H;

A:;

B:A|;

C:||;

D:|C|;


