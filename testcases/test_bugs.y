%type <> A1
%type <> A2
%type <> A3
%type <> A4
%type <> A5
%type <> A6
%type <> A7
%type <> A8
%type <> A9
%type <> A10
%type <> A11
%type <> A12//defined, but not used bug

%token <int> B1
%token <int> B2

%%

A4: B1 | ;
/*A1: B1 | B1; //these two rules are the same
//A2:;//illed production, eliminable
//A3: "hello" | "hello" | B1 | B1 | B2;//duplicated rules*/

A5: "/*comment in string*/";

