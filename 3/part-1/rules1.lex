%{
	#include "defines.h"
	int lineNo=0;
	void countNewLine();
	
%}

%s HASH

preDir			("#include"[ \t]+.*)|("#define"[ \t]+.*)

lineComment		"//".*
blockComment	"/*"((("*"[^/])?)|[^*])*"*/"
string			\"([^\"]|\\.)*\"
charLit			\'([^\']|\\.)?\'

letter 	[a-zA-Z]
digit [0-9]
ws [ \t\v\f]
digits {digit}+
number {digits}("."{digits})?(E("+"|"-")?{digits})?

illegal {`~@#$_\':?}

dt ("auto"|"char"|"const"|"double"|"float"|"int"|"long"|"short"|"signed"|"static"|"unsigned")

id {letter}({letter}|{digit})*

%%
			
"+"										{printf("@@@@ PLUS \n");return PLUS; }
","										{printf("@@@@ COMMA \n");return COMMA; }
"*"										{printf("@@@@ MUL \n");return MUL; }
"="										{printf("@@@@ EQ \n");return EQ; }
"-"										{printf("@@@@ SUB \n");return SUB;}
"/"										{printf("@@@@ DIV \n");return DIV;}
"("										{printf("@@@@ LP \n");return LP; }
")"										{printf("@@@@ RP \n");return RP; }
"if"									{printf("@@@@ IF \n");return IF;}
"for"									{printf("@@@@ FOR \n");return FOR;}
"do"									{printf("@@@@ DO \n");return DO;}
"while"									{printf("@@@@ WHILE \n");return WHILE;}
"{"										{printf("@@@@ LB \n");return LB;}
"}"										{printf("@@@@ RB \n");return RB;}
";"										{printf("@@@@ SEMI \n");return SEMI;}
"return"								{printf("@@@@ RETURN \n");return RETURN;}
"break"									{printf("@@@@ BREAK \n");return BREAK;}
"continue"								{printf("@@@@ CONTINUE \n");return CONTINUE;}
{dt}									{printf("@@@@ DATA_TYPE \n");return DATA_TYPE;}
{number}								{printf("@@@@ NUM \n");return NUM;}
{id}									{printf("@@@@ ID \n");return ID;}
"\n"									{printf("@@@@ newline \n");}
.										{printf("UNKnown \n"); ECHO;}





%%

