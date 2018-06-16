%{
	#include "calculator.tab.h"
	using namespace std;
%}

%%

[ \t]          	;
\!				{ return NOT; }
\+             	{ return AND; }
\|             	{ return OR; }
\^             	{ return XOR; }
\=>             { return IMPL; }
\<=>            { return IFOIF; }
\(             	{ return LPAREN; }
\)             	{ return RPAREN; }
[A-Z]   		{ yylval.sval = strdup(yytext); return FACT; }
"#".*			{ }
\n             	{ return ENDL; }

%%