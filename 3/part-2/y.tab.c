#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20121003

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
	#include <stdio.h>
	#include <stdlib.h>
	int yylex(void);
	void yyerror (char const *s) 
	{
   		/*fprintf (stderr, "%s\n", s);*/
 	}
 	extern int lineNo;
#line 28 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ADD_ASSIGN 257
#define SUB_ASSIGN 258
#define MUL_ASSIGN 259
#define DIV_ASSIGN 260
#define MOD_ASSIGN 261
#define AND_ASSIGN 262
#define XOR_ASSIGN 263
#define OR_ASSIGN 264
#define RIGHT_OP 265
#define LEFT_OP 266
#define INC_OP 267
#define DEC_OP 268
#define PTR_OP 269
#define AND_OP 270
#define OR_OP 271
#define LE_OP 272
#define GE_OP 273
#define EQ_OP 274
#define NE_OP 275
#define ID 276
#define DATA_TYPE 277
#define IF 278
#define ELSE 279
#define WHILE 280
#define FOR 281
#define DO 282
#define CONTINUE 283
#define BREAK 284
#define RETURN 285
#define FLOATING_POINT 286
#define INTEGER 287
#define CHAR_LIT 288
#define STRING 289
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    1,    3,    3,    3,   11,   11,    2,
   13,   13,   13,   17,   17,   17,   15,   15,   20,   20,
   21,   21,   21,   21,   21,   21,   22,   22,   23,   23,
   23,   24,   24,   24,   24,    7,    7,    7,    7,    7,
   26,   26,   26,   26,   26,   27,   27,   27,   27,   27,
   27,   27,   27,   27,   28,   28,   28,   28,   29,   29,
   29,   30,   30,   30,   30,   30,    6,    6,    4,    4,
    5,    5,    9,    9,   25,   25,   25,   12,   12,   14,
   14,   18,   18,   19,   19,    8,    8,   10,   10,   16,
   16,
};
static const short yylen[] = {                            2,
    0,    2,    1,    1,    3,    5,    6,    1,    2,    6,
    0,    2,    4,    0,    1,    3,    2,    3,    0,    2,
    1,    1,    1,    1,    1,    2,    5,    7,    5,    7,
    9,    2,    2,    2,    3,    1,    1,    3,    3,    4,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,
};
static const short yydefred[] = {                         0,
   70,   69,    0,    0,    3,    4,    0,    2,   72,   71,
    0,    0,    0,   67,   78,   86,    5,    0,    0,   72,
   76,   75,    0,    0,    0,   74,   73,    0,    0,    0,
    0,   50,   51,   47,   48,   49,   52,   53,   54,   60,
   61,   57,   58,   46,   55,   56,   59,   62,   63,   64,
   65,   66,    0,    0,   41,   42,   43,   44,   68,    6,
   45,    0,   89,   88,    0,    0,   81,   80,    0,    0,
    0,   39,   38,    7,   91,   90,    0,   83,   82,   10,
    0,    0,   40,   13,    0,    0,    0,    0,    0,    0,
    0,    0,   84,    0,    0,    0,   21,   22,   17,    0,
    0,   23,   24,   25,   16,   79,    0,    0,    0,    0,
    0,   32,   33,    0,   34,    0,    9,    0,   26,   85,
   18,   20,    0,    0,    0,    0,   35,   68,    0,    0,
    0,    0,    0,   29,    0,    0,    0,    0,    0,   28,
    0,   30,    0,   31,
};
static const short yydgoto[] = {                          3,
    4,    5,   94,   95,   23,   17,   96,   18,   28,   65,
   97,   19,   30,   69,   98,   77,   71,   81,   99,  100,
  101,  102,  103,  104,   25,   54,   55,   56,   57,   58,
};
static const short yysindex[] = {                      -242,
    0,    0,    0, -242,    0,    0, -239,    0,    0,    0,
  -36,    0, -198,    0,    0,    0,    0, -228, -242,    0,
    0,    0,  100,  -53,  121,    0,    0,  -72, -239,  -38,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -239, -198,    0,    0,    0,    0,    0,    0,
    0, -198,    0,    0,  -53,  -34,    0,    0, -115,  -34,
  -38,    0,    0,    0,    0,    0, -242,    0,    0,    0,
 -107, -239,    0,    0,    0,  -35,  -35,  -35,  131,  -53,
  -53,  -57,    0, -242, -239,  -53,    0,    0,    0, -112,
  131,    0,    0,    0,    0,    0, -198, -198, -198,    0,
 -265,    0,    0,    0,    0,  -53,    0,  -52,    0,    0,
    0,    0,  -38,  -38,  -53,  -35,    0,    0,  131,  131,
 -198, -198, -250,    0,  -53,  -38,  131, -198,  -53,    0,
  -38,    0,  131,    0,
};
static const short yyrindex[] = {                        32,
    0,    0,    0,   32,    0,    0,    0,    0,    0,    0,
    0,   12,    0,    0,    0,    0,    0,    0,   -5,    0,
    0,    0,  -19,    0,  -17,    0,    0,    0,    0,    0,
  -41,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    6,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    8,    0,    0,    0,    9,
    0,    0,    0,    0,    0,    0,   -5,    0,    0,    0,
    0,    6,    0,    0,    1,    0,    0,    0,    0,    0,
    0,    0,    0,  144,    0,    0,    0,    0,    0,    0,
  -74,    0,    0,    0,    0,    0,    0,    0,    0,   68,
    0,    0,    0,   34,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  119,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const short yygindex[] = {                        48,
    0,    0,   27,   26,    4,  345,  385,    0,    0,    0,
  -40,   -4,  -21,  -51,   -1,   -6,  -13,    0,  -30,  -26,
  -23,    0,    0,    0,    0,   40,    0,    0,    0,    0,
};
#define YYTABLESIZE 523
static const short yytable[] = {                         79,
   85,   14,   68,   15,   15,   14,   14,   79,   13,   76,
   11,   68,   93,    1,  126,   79,    9,   93,   53,   83,
   64,   37,   14,   36,   13,    7,    6,   26,  137,    7,
    6,    1,   66,   72,    2,   11,   10,   72,   16,   37,
   72,   36,   72,   72,   29,   72,   14,   72,   12,   15,
   19,    8,   79,  117,   16,   84,   70,   20,   27,   72,
   72,   72,   72,   82,   62,  111,   72,   80,  105,  121,
   72,  129,  130,   72,  122,   72,   72,   10,   72,    0,
   72,  107,  108,  109,  139,   70,    0,   21,   22,  143,
    0,    0,   72,   72,   72,   72,    0,    0,  118,    0,
   72,    0,   29,    0,   72,  133,  134,   72,    0,   72,
   72,    0,   72,  140,   72,    0,    0,    0,    0,  144,
    0,  132,    0,   83,    0,   83,   72,   72,   72,   72,
    0,    0,   47,    0,    0,    0,   52,    0,    0,   15,
   78,   50,   48,  120,   49,    0,   51,    0,   85,    0,
    0,    0,    0,   47,    0,    0,   68,   52,   68,   45,
   44,   46,   50,   48,    0,   49,    0,   51,   10,    2,
   86,    0,   87,   88,   89,   90,   91,   92,   21,   22,
   45,   44,   46,   63,    0,    0,    0,    0,    0,    0,
   83,    0,   83,    0,    0,    0,    0,    0,  114,    0,
    0,    0,   59,  128,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   45,    0,    0,   67,   10,   12,
  106,   75,    0,    0,    0,    0,    0,    0,   21,   22,
    0,    0,    0,    0,   45,    0,    0,    0,    0,    0,
    0,   27,    0,   27,   45,   45,    0,    0,    0,    0,
    0,    0,    0,   79,    0,    0,   70,   72,   72,   72,
   72,   72,   72,   72,   72,    0,    8,   68,    8,    0,
   72,   72,   72,   72,    0,    0,   70,   83,   83,   85,
   83,   83,   83,   83,   83,   83,   83,   83,   68,   68,
   72,   72,   72,   72,   72,   72,   72,   72,   87,    0,
    0,    0,    0,   72,   72,   72,   72,    0,    0,   68,
   68,   68,   68,   68,   68,   68,   68,   68,   68,   68,
   68,    0,    0,   70,   72,   72,   72,   72,   72,   72,
   72,   72,    0,    0,    0,    0,    0,   72,   72,   72,
   72,    0,    0,   70,   83,   83,    0,   83,   83,   83,
   83,   83,   83,   83,   83,   31,   32,   33,   34,   35,
   36,   37,   38,   39,    0,    0,    0,    0,   60,   40,
   41,   42,   43,    0,   27,    0,   61,   32,   33,   34,
   35,   36,   37,   38,   39,    0,  110,    0,    0,    0,
   40,   41,   42,   43,   27,   27,   27,   24,   27,   27,
   27,   27,   27,   27,   27,   27,   10,    2,   86,   74,
   87,   88,   89,   90,   91,   92,   21,   22,    0,    8,
    0,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    0,    0,    0,  112,  113,  115,    0,   72,    0,
  119,    0,    0,    0,    0,    0,   73,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  127,    0,    0,    0,    0,    0,    0,    0,    0,  131,
    0,    0,    0,    0,    0,    0,  116,    0,    0,  138,
    0,    0,    0,  142,    0,    0,    0,    0,    0,    0,
    0,  123,  124,  125,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  135,  136,    0,    0,    0,
    0,    0,  141,
};
static const short yycheck[] = {                         41,
    0,   59,   41,   40,   40,   59,   59,  123,   61,   44,
    7,    0,  125,  256,  280,  123,  256,  125,   23,   71,
   93,   41,   59,   41,   61,    0,    0,  256,  279,    4,
    4,    0,   29,   33,  277,   41,  276,   37,   91,   59,
   40,   59,   42,   43,   19,   45,   41,   47,   41,   41,
  125,    4,   41,   94,   91,   77,   53,  256,  287,   59,
   60,   61,   62,   70,   25,   89,   33,   69,   82,  100,
   37,  123,  124,   40,  101,   42,   43,  276,   45,   -1,
   47,   86,   87,   88,  136,   82,   -1,  286,  287,  141,
   -1,   -1,   59,   60,   61,   62,   -1,   -1,   95,   -1,
   33,   -1,   77,   -1,   37,  129,  130,   40,   -1,   42,
   43,   -1,   45,  137,   47,   -1,   -1,   -1,   -1,  143,
   -1,  126,   -1,  123,   -1,  125,   59,   60,   61,   62,
   -1,   -1,   33,   -1,   -1,   -1,   37,   -1,   -1,   40,
  256,   42,   43,  256,   45,   -1,   47,   -1,  256,   -1,
   -1,   -1,   -1,   33,   -1,   -1,  123,   37,  125,   60,
   61,   62,   42,   43,   -1,   45,   -1,   47,  276,  277,
  278,   -1,  280,  281,  282,  283,  284,  285,  286,  287,
   60,   61,   62,  256,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,  256,   -1,
   -1,   -1,  256,  256,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  256,   -1,   -1,  256,  276,  256,
  256,  256,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,
   -1,   -1,   -1,   -1,  276,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,  286,  287,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  123,   -1,   -1,  256,  257,  258,  259,
  260,  261,  262,  263,  264,   -1,  123,  256,  125,   -1,
  270,  271,  272,  273,   -1,   -1,  276,  277,  278,  279,
  280,  281,  282,  283,  284,  285,  286,  287,  277,  256,
  257,  258,  259,  260,  261,  262,  263,  264,  287,   -1,
   -1,   -1,   -1,  270,  271,  272,  273,   -1,   -1,  276,
  277,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  287,   -1,   -1,  256,  257,  258,  259,  260,  261,  262,
  263,  264,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,
  273,   -1,   -1,  276,  277,  278,   -1,  280,  281,  282,
  283,  284,  285,  286,  287,  256,  257,  258,  259,  260,
  261,  262,  263,  264,   -1,   -1,   -1,   -1,   24,  270,
  271,  272,  273,   -1,  256,   -1,  256,  257,  258,  259,
  260,  261,  262,  263,  264,   -1,  256,   -1,   -1,   -1,
  270,  271,  272,  273,  276,  277,  278,   13,  280,  281,
  282,  283,  284,  285,  286,  287,  276,  277,  278,   65,
  280,  281,  282,  283,  284,  285,  286,  287,   -1,  276,
   -1,  278,  279,  280,  281,  282,  283,  284,  285,  286,
  287,   -1,   -1,   -1,   90,   91,   92,   -1,   54,   -1,
   96,   -1,   -1,   -1,   -1,   -1,   62,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  116,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  125,
   -1,   -1,   -1,   -1,   -1,   -1,   92,   -1,   -1,  135,
   -1,   -1,   -1,  139,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  107,  108,  109,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  131,  132,   -1,   -1,   -1,
   -1,   -1,  138,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 289
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ADD_ASSIGN","SUB_ASSIGN","MUL_ASSIGN",
"DIV_ASSIGN","MOD_ASSIGN","AND_ASSIGN","XOR_ASSIGN","OR_ASSIGN","RIGHT_OP",
"LEFT_OP","INC_OP","DEC_OP","PTR_OP","AND_OP","OR_OP","LE_OP","GE_OP","EQ_OP",
"NE_OP","ID","DATA_TYPE","IF","ELSE","WHILE","FOR","DO","CONTINUE","BREAK",
"RETURN","FLOATING_POINT","INTEGER","CHAR_LIT","STRING",
};
static const char *yyrule[] = {
"$accept : strt",
"strt :",
"strt : external_declaration strt",
"external_declaration : function_definition",
"external_declaration : declaration",
"declaration : data_type id semi",
"declaration : data_type id '=' expr semi",
"declaration : data_type id left_bracket integer right_bracket semi",
"declaration_list : declaration",
"declaration_list : declaration declaration_list",
"function_definition : data_type id left_parenthesis arg_list right_parenthesis compound_stmts",
"arg_list :",
"arg_list : data_type id",
"arg_list : data_type id comma arg_list",
"param_list :",
"param_list : id",
"param_list : id comma param_list",
"compound_stmts : left_brace right_brace",
"compound_stmts : left_brace stmt_list right_brace",
"stmt_list :",
"stmt_list : stmt stmt_list",
"stmt : declaration_list",
"stmt : compound_stmts",
"stmt : conditional_stmt",
"stmt : iteration_stmt",
"stmt : jump_stmt",
"stmt : expr semi",
"conditional_stmt : IF left_parenthesis expr right_parenthesis stmt",
"conditional_stmt : IF left_parenthesis expr right_parenthesis stmt ELSE stmt",
"iteration_stmt : WHILE left_parenthesis expr right_parenthesis stmt",
"iteration_stmt : DO stmt WHILE left_parenthesis expr right_parenthesis semi",
"iteration_stmt : FOR left_parenthesis expr semi expr semi expr right_parenthesis stmt",
"jump_stmt : CONTINUE semi",
"jump_stmt : BREAK semi",
"jump_stmt : RETURN semi",
"jump_stmt : RETURN expr semi",
"expr : number",
"expr : id",
"expr : number operator expr",
"expr : id operator expr",
"expr : id left_parenthesis param_list right_parenthesis",
"operator : assignment_op",
"operator : relational_op",
"operator : logical_op",
"operator : binary_op",
"operator : error",
"assignment_op : '='",
"assignment_op : MUL_ASSIGN",
"assignment_op : DIV_ASSIGN",
"assignment_op : MOD_ASSIGN",
"assignment_op : ADD_ASSIGN",
"assignment_op : SUB_ASSIGN",
"assignment_op : AND_ASSIGN",
"assignment_op : XOR_ASSIGN",
"assignment_op : OR_ASSIGN",
"relational_op : '<'",
"relational_op : '>'",
"relational_op : LE_OP",
"relational_op : GE_OP",
"logical_op : '!'",
"logical_op : AND_OP",
"logical_op : OR_OP",
"binary_op : '+'",
"binary_op : '-'",
"binary_op : '*'",
"binary_op : '/'",
"binary_op : '%'",
"semi : ';'",
"semi : error",
"data_type : DATA_TYPE",
"data_type : error",
"id : ID",
"id : error",
"integer : INTEGER",
"integer : error",
"number : INTEGER",
"number : FLOATING_POINT",
"number : error",
"left_parenthesis : '('",
"left_parenthesis : error",
"right_parenthesis : ')'",
"right_parenthesis : error",
"left_brace : '{'",
"left_brace : error",
"right_brace : '}'",
"right_brace : error",
"left_bracket : '['",
"left_bracket : error",
"right_bracket : ']'",
"right_bracket : error",
"comma : ','",
"comma : error",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 175 "parser.y"

int main()
{

	yyparse();
	return 0 ;
}

#line 455 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 45:
#line 95 "parser.y"
	{printf("Missing operator at line no. %d\n",lineNo);}
break;
case 68:
#line 127 "parser.y"
	{printf("Missing semicolon at line no. %d\n",lineNo);}
break;
case 70:
#line 131 "parser.y"
	{printf("Missing data type at line no. %d\n",lineNo);}
break;
case 72:
#line 135 "parser.y"
	{printf("Missing identifier at line no. %d\n",lineNo);}
break;
case 74:
#line 139 "parser.y"
	{printf("Missing integer at line no. %d\n",lineNo);}
break;
case 77:
#line 144 "parser.y"
	{printf("Missing number at line no. %d\n",lineNo);}
break;
case 79:
#line 148 "parser.y"
	{printf("Missing ( at line no. %d\n",lineNo);}
break;
case 81:
#line 152 "parser.y"
	{printf("Missing ) at line no. %d\n",lineNo);}
break;
case 83:
#line 156 "parser.y"
	{printf("Missing { at line no. %d\n",lineNo);}
break;
case 85:
#line 160 "parser.y"
	{printf("Missing } at line no. %d\n",lineNo);}
break;
case 87:
#line 164 "parser.y"
	{printf("Missing [ at line no. %d\n",lineNo);}
break;
case 89:
#line 168 "parser.y"
	{printf("Missing ] at line no. %d\n",lineNo);}
break;
case 91:
#line 172 "parser.y"
	{printf("Missing , at line no. %d\n",lineNo);}
break;
#line 713 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
