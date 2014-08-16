%{

#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
#include "parser.h"
#include "backend.h"

using std::string;
using std::list;
using std::cout;
using std::endl;

#ifdef YYLEX_PARAM
int yylex (YYLEX_PARAM);
#else
int yylex ();
#endif

//#define DEBUG_PARSER

#ifdef DEBUG_PARSER
#define PRINT(str)	cout<<str<<endl
#else
#define PRINT(str)
#endif

extern "C" int yyerror(const string & s);

extern FILE * yyin;

extern list<string> str_stack;

parser	a_parser(str_stack);
	
%}

%union
{
	int stub;
}

%token <stub> USR_STR_Y
%token <stub> USR_TYPE_Y
%token <stub> IDENTIFIER
%token <stub> TOKEN
%token <stub> TYPE
%token <stub> FUNCTION
%token <stub> FUNC_PARAMETER
%token <stub> FUNC_ID
%token <stub> NUM

%token <stub> LEFT_SYMBOL
%token <stub> RIGHT_SYMBOL

%type <stub> cfg_n_func
%type <stub> grammar
%type <stub> type_list
%type <stub> type

%type <stub> rule_list
%type <stub> rule
%type <stub> branches
%type <stub> rules
%type <stub> func_def
%type <stub> func_body
%type <stub> func_decl
%type <stub> func_id_list
%type <stub> func_list

%left '|'

%%

cfg_n_func:
	grammar func_list	{PRINT("GRAMMAR: FUNC"); a_parser.on_cfg_n_func();}
|	grammar			{PRINT("GRAMMAR"); a_parser.on_cfg_n_func();}
	;

grammar:
	type_list rule_list	{PRINT("GRAMMAR:RULE_LIST TYPE_LIST"); a_parser.on_grammar();}
|	rule_list type_list	{PRINT("SYNTAX ERROR"); a_parser.on_grammar_reversed();}
|	type_list		{PRINT("SYNTAX ERROR"); a_parser.on_grammar_missing_rules();}
|	rule_list		{PRINT("SYNTAX ERROR"); a_parser.on_grammar_missing_types();}
	;

type_list:
	type_list type		{PRINT("TYPE_LIST:TYPE_LIST TYPE"); a_parser.on_type_list();}
|	type			{PRINT("TYPE_LIST:TYPE"); a_parser.on_type_list();}
	;

type	:
	TOKEN USR_TYPE_Y IDENTIFIER	{PRINT("TYPE:TOCKEN"); a_parser.on_token();}
|	TYPE USR_TYPE_Y IDENTIFIER	{PRINT("TYPE:TYPE"); a_parser.on_type();}
|	FUNCTION USR_TYPE_Y IDENTIFIER	{PRINT("TYPE:FUNCTION");a_parser.on_function();}
	;

rule_list:
	rule_list rule		{PRINT("RULE_LIST:LIST RULE"); a_parser.on_rule_list();}
|	rule			{PRINT("RULE_LIST:RULE"); a_parser.on_rule_list();}
	;

rule	:
	IDENTIFIER ':' branches ';'		{PRINT("RULE"); a_parser.on_rule();}
/*|	';' branches ';'			{PRINT("SYNTAX ERROR");a_parser.on_rule_missing_colon();}//missing ':'
|	IDENTIFIER ':' branches ':'		{PRINT("SYNTAX ERROR");a_parser.on_rule_missing_semicolon();}//missing ';' */
	;

branches:
	branches '|' branches	{PRINT("BRANCHES:BRANCHES BRANCHES");}
|	rules			{PRINT("BRANCHES:RULES"); a_parser.on_branches();}
|				{PRINT("BRANCHES:EMPTY"); a_parser.on_branches_empty();}
	;

rules	:
	rules IDENTIFIER	{PRINT("RULES:RULES ID_OR_FUNC"); a_parser.on_rules_id();}
|	rules USR_STR_Y		{PRINT("RULES:RULES STR"); a_parser.on_rules_str();}
|	rules '%' IDENTIFIER '.' NUM	{PRINT("RULES:RULES REC FUNC");a_parser.on_rules_rec_func();}
|	rules '%' IDENTIFIER	{PRINT("RULES:RULES NONREC FUNC");a_parser.on_rules_nonrec_func();}
|	IDENTIFIER		{PRINT("RULES:ID_OR_FUNC"); a_parser.on_rules_id();}
|	USR_STR_Y		{PRINT("RULES:STR"); a_parser.on_rules_str();}
|	'%' IDENTIFIER '.' NUM	{PRINT("RULES:REC FUNC");a_parser.on_rules_rec_func();}
|	'%' IDENTIFIER		{PRINT("RULES:NONREC FUNC");a_parser.on_rules_nonrec_func();}
	;

func_list:
	func_list func_decl	{PRINT("FUNC_LIST:FUNC_LIST FUNC_DEL");a_parser.on_func_list();}
|	func_list func_def	{PRINT("FUNC_LIST:FUNC_LIST FUNC_DEF");a_parser.on_func_list();}
|	func_decl		{PRINT("FUNC_LIST:FUNC_DEL");a_parser.on_func_list();}
|	func_def		{PRINT("FUNC_LIST:FUNC_DEF");a_parser.on_func_list();}
	;

func_decl:
	func_id_list FUNC_PARAMETER ';'			{PRINT("FUNC_DEL:");a_parser.on_func_decl();}
	//func_declaration and func_definition can be together for non-recursive functions
|	func_id_list FUNC_PARAMETER '{' func_body '}'	{PRINT("FUNC_DEL: BODY");a_parser.on_func_decl_nonrec(0);}
|	func_id_list FUNC_PARAMETER '{' '}'		{PRINT("FUNC_DEL: EMPTY BODY");a_parser.on_func_decl_nonrec(1);}
	;

func_id_list:
	func_id_list FUNC_ID	{PRINT("FUNC_ID_LIST:FUNC_ID_LIST FUNC_ID");a_parser.on_func_id_list(0);}
|	func_id_list NUM	{PRINT("FUNC_ID_LIST:FUNC_ID_LIST NUM");a_parser.on_func_id_list(0);}
|	FUNC_ID			{PRINT("FUNC_ID_LIST:FUNC_ID");a_parser.on_func_id_list(1);}
|	NUM			{PRINT("FUNC_ID_LIST:NUM");a_parser.on_func_id_list(1);}
	;

func_def:
	FUNC_ID '.' NUM  '{' func_body '}'	{PRINT("FUNC_DEF:RECURSIVE");a_parser.on_func_def_rec(0);}
|	FUNC_ID '{' func_body '}'		{PRINT("FUNC_DEF:NON-RECURSIVE");a_parser.on_func_def_nonrec(0);}
|	FUNC_ID '.' NUM  '{' '}'		{PRINT("FUNC_DEF:RECURSIVE EMPTY");a_parser.on_func_def_rec(1);}
|	FUNC_ID '{' '}'				{PRINT("FUNC_DEF:NON-RECURSIVE EMPTY");a_parser.on_func_def_nonrec(1);}
	;

func_body:
	func_body LEFT_SYMBOL	{PRINT("FUNC_BODY:FUNC LEFT_SYMBOL"); a_parser.on_func_body_lsymbol();}
|	func_body RIGHT_SYMBOL	{PRINT("FUNC_BODY:FUNC RIGHT_SYMBOL"); a_parser.on_func_body_rsymbol();}
|	LEFT_SYMBOL		{PRINT("FUNC_BODY:LEFT_SYMBOL"); a_parser.on_func_body_lsymbol();}
|	RIGHT_SYMBOL		{PRINT("FUNC_BODY:RIGHT_SYMBOL"); a_parser.on_func_body_rsymbol();}
	;



%%

int yyerror(const string & s)
{
    cout<<"*** "<<s<<" near \""<<str_stack.back()<<"\""<<endl;
    assert(0);//must terminate the program, in case of memory leak
    return 1;
}

main(int argc, char ** argv)
{
	if(argc != 2)
	{
		cout<<"Usage: "<<argv[0]<<" grammar file"<<endl;
		return 0;
	}

	FILE *f = fopen(argv[1], "r");
	if(!f) {
		cout<<"\t*** error:cannot open grammar file!"<<endl;
		return 0;
	}
	yyin = f;
	yyparse();

	cout<<"finish parsing"<<endl;
	fclose(f);

	backend	bknd(a_parser.get_tree());
	bknd.generate_output();

	cout<<"finish generating"<<endl;
	return 0;

}
