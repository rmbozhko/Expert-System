%{
	#include "parser.tab.hpp"
	unsigned 	linenum = 0;
%}

%%

[ \t]+          
"!"				{ yylval.oper = strdup(yytext); return NOT; }
"+"            	{ yylval.oper = strdup(yytext); return AND; }
"|"             { yylval.oper = strdup(yytext); return OR; }
"^"             { yylval.oper = strdup(yytext); return XOR; }
"=>"            { yylval.oper = strdup(yytext); return IMPL; }
"<=>"           { yylval.oper = strdup(yytext); return IFOIF; }
"("             { yylval.oper = strdup(yytext); return LPAREN; }
")"             { yylval.oper = strdup(yytext); return RPAREN; }
[A-Z]+	  		{ yylval.fact = strdup(yytext); return FACT; }
[\n]	        { linenum++; return ENDL; }
"="				{ yylval.fact = strdup(yytext); return T_INIT_FACTS; }
"?"				{ yylval.fact = strdup(yytext); return T_QUERY_LIST; }
#.* 			
%%