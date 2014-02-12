#define EOI		0	/* End of input			*/
#define SEMI	1	/* ; 				*/
#define PLUS 	2	/* + 				*/
#define MINUS	
#define TIMES	3	/* * 				*/
#define DIVIDE	4	/* / 				*/
#define ASSIGN	5	/* = 				*/
#define	COLON_EQUAL	6	/* := 				*/
#define GREATER	7	/* > 				*/
#define LESS	8	/* < 				*/
#define LP		9	/* (				*/
#define RP		10	/* )				*/
#define NUM_OR_ID	11	/* Decimal Number or Identifier */
#define IF 12	/* if 				*/
#define THEN 13	/* then 				*/
#define WHILE 14	/* while 				*/
#define DO 15	/* do 				*/
#define	BEGIN 16	/* begin 				*/
#define END 17	/* end 				*/
extern char *yytext;		/* in lex.c			*/
extern int yyleng;
extern yylineno;
