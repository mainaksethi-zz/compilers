%{
	#include	"def.h"
	int lineno=1;
	void func(void);
%}
digit [0-9]
letter	[a-zA-Z]
ws  [ \t\v\n\f]
alphanum	[a-zA-Z 0-9]
%%
"/*"[^"*/"]*"*/"	{printf("BlockComment	%s 	%d\n",yytext,blockcomment);func();}
"//".*	printf("SingleComment	%s 	%d\n",yytext,comment);
{digit}+{letter}{alphanum}*	printf("Invalid Identifier	%s at line %d\n",yytext,lineno);
"#include<"{letter}+".h>"	printf("Preprocessor	%s 	%d\n",yytext,preprocessor);
("long"{ws}*)?("void"|"int"|"char"|"double"|"float")	printf("Datatype	%s 	%d\n",yytext,datatype);
("auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"else if")	printf("Keyword	%s 	%d\n",yytext,keyword);
("+"|"-"|"*"|"/"|"++"|"--"|"+="|"-="|"<="|">="|"<"|">"|"*="|"/="|"=")	printf("Operator	%s 	%d\n",yytext,operator);
("("|"{"|")"|"}")	printf("Paranthesis %s %d\n",yytext,paranthesis);
";"	printf("Semi %s %d\n",yytext,semi);
{digit}+	printf("Number	%s 	%d\n",yytext,number);
{digit}+("."{digit}+)?	printf("Real	%s 	%d\n",yytext,real);
"'"{letter}"'"	printf("Character	%s 	%d\n",yytext,character);
"\""[.\n]*"\""	{printf("String	%s 	%d\n",yytext,string);func();}
{letter}({letter}|_|{digit})*	printf("Identifier	%s 	%d\n",yytext,identifier);
"\n"	lineno++;
{ws}	;
.	printf("unindentified	character %s at line %d\n",yytext,lineno);
%%
void func(void)
{
	int i;
	for(i=0;i<yyleng;i++)
	{
		if(*(yytext+i)=='\n')
		{
			lineno++;
		}
	}
	return ;
}