%{
#include <string>
#include <iostream>
#include <list>
#include <stdlib.h>
#include "borel.tab.h"

using std::string;
using std::list;
using std::cout;
using std::endl;

extern "C" int yywrap();

list<string> str_stack;
string usr_str;
int symbol_idx = 0;
int bracket_num = 0;
int is_non_printable_str = 0;
int section_counter = 0;
%}

%x COMMENT
%x CPP_COMMENT

%x USR_CODE
%x USR_STR
%x USR_TYPE

%x PARAMETER_STR

%%

<<EOF>>    {return 0;}
(" "|\t)+    //keep silent

":"	|
"|"	|
";"	|
"%"	|
"."	{return yytext[0];}

"%token"		{return TOKEN;}
"%type"			{return TYPE;}
"%function"		{return FUNCTION;}

"//"			{BEGIN COMMENT;}
<COMMENT>\n		{BEGIN INITIAL;}
<COMMENT>.*		//keep silent

"/*"			{BEGIN CPP_COMMENT;}
<CPP_COMMENT>"*/"	{BEGIN INITIAL;}
<CPP_COMMENT>'*'	//keep silence
<CPP_COMMENT>'/'	//keep silence
<CPP_COMMENT>[^'*'/]+	//keep silence

"<"			{	
				if(section_counter == 0)
				{
					BEGIN USR_TYPE; 
				}else if(section_counter == 2)
				{//c++ template in section_counter == 2 may use symbol "<", ">", etc.
					str_stack.push_back("<");
					return FUNC_ID;
				}else
				{
					cout<<"***lexical error:\t"<<usr_str<<endl;
				}
				usr_str = ""; 
				bracket_num = 1;
				is_non_printable_str = 1;
			}
			
<USR_TYPE>"<"		{	bracket_num++;
				is_non_printable_str = 0;
				usr_str += "<";
				if(bracket_num == 0)
				{	
					cout<<"***lexical error:\t"<<usr_str<<endl;
					BEGIN INITIAL;
				}
			}
<USR_TYPE>">"		{	bracket_num--;
				if(bracket_num != 0)
				{
					usr_str += ">";
					is_non_printable_str = 0;
				}else
				{
					if(is_non_printable_str == 1)
					{// the string is [\a\b\t\n\v\f\r]+
						str_stack.push_back("");
					}
					else
					{
						str_stack.push_back(usr_str);
					}
					BEGIN INITIAL;
					return USR_TYPE_Y;
				}
			}
<USR_TYPE>[\a\b\t\n\v\f\r ]+	{usr_str += yytext;}
<USR_TYPE>[^<>\a\b\t\n\v\f\r ]+	{usr_str += yytext; is_non_printable_str = 0;}

\"			{BEGIN USR_STR; usr_str = "";}
<USR_STR>\\\"		{usr_str += "\\\""; }
<USR_STR>\\		{usr_str += "\\"; }
<USR_STR>[^\"\\]+	{usr_str += yytext;}
<USR_STR>\"		{BEGIN INITIAL; str_stack.push_back(usr_str); return USR_STR_Y;}

"{"			{	BEGIN USR_CODE; 
				usr_str = ""; 
				bracket_num = 1;
				return yytext[0];
			}
			
<USR_CODE>"{"		{	bracket_num++;
				usr_str += "{";
				if(bracket_num == 0)
				{	
					cout<<"***lexical error:\t"<<usr_str<<endl;
					BEGIN INITIAL;
				}
			}
			
<USR_CODE>"}"		{	bracket_num--;
				if(bracket_num != 0)
				{
					usr_str += "}";
				}else
				{
					str_stack.push_back(usr_str);
					BEGIN INITIAL;
					return yytext[0];
				}
			}

<USR_CODE>"$"[0-9]+	{
				str_stack.push_back(usr_str);
				usr_str = yytext;
				str_stack.push_back(usr_str);
				usr_str = "";
				return RIGHT_SYMBOL;
			}
<USR_CODE>"$$"		{
				str_stack.push_back(usr_str);
				usr_str = "";
				return LEFT_SYMBOL;
			}
<USR_CODE>"$"		{usr_str += yytext;}
<USR_CODE>[^{}$]+	{usr_str += yytext;}

"("			{	BEGIN PARAMETER_STR; 
				usr_str = "("; 
				bracket_num = 1;
			}
			
<PARAMETER_STR>"("	{
				bracket_num++;
				usr_str += "(";
				if(bracket_num == 0)
				{	
					cout<<"***lexical error:\t"<<usr_str<<endl;
					BEGIN INITIAL;
				}
			}
<PARAMETER_STR>")"	{
				bracket_num--;
				usr_str += ")";
				if(bracket_num == 0)
				{
					str_stack.push_back(usr_str);
					BEGIN INITIAL;
					return FUNC_PARAMETER;
				}
			}
<PARAMETER_STR>[^()]+	{usr_str += yytext;}

[A-Za-z_][A-Za-z0-9_]*	{
				str_stack.push_back(yytext); 
				if(section_counter == 0 || section_counter == 1)
				{
					return IDENTIFIER;
				}else if(section_counter == 2)
				{
					return FUNC_ID;
				}else
				{
					cout<<"***lexical error:\t"<<usr_str<<endl;
				}
			}

">"		|
"*"		|
"["		|
"]"		|
"&"			{
				if(section_counter == 2)
				{//these are lexical elements used in C/C++ ex. "void * func()"
					str_stack.push_back(yytext);
					return FUNC_ID;
				}else
				{
					cout<<"***lexical error:\t"<<usr_str<<endl;
				}
			}

[0-9]+			{
				str_stack.push_back(yytext);
				return NUM;
			}

"%%"			{section_counter++;}

"\n"			
.			{cout<<"***lexical error:\t"<<yytext<<endl;}
%%

int yywrap()
{
    return 1;
}
