#define EOI		0	/* End of input			*/
#define SEMI		1	/* ; 				*/
#define PLUS 		2	/* + 				*/
#define TIMES		3	/* * 				*/
#define LP		4	/* (				*/
#define RP		5	/* )				*/
#define NUM_OR_ID	6	/* Decimal Number or Identifier */
#define MINUS 7		/* - */
#define DIV 	8	/* / */
#define IF 9
#define THEN 10
#define WHILE 11
#define DO 12
#define BEGIN 13
#define END 14
#define EQUALS 15
#define GREATER 16
#define LESS 17
extern char *yytext;		/* in lex.c			*/
extern int yyleng;
extern yylineno;
