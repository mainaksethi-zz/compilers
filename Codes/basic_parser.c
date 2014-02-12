/* Basic parser, shows the structure but there's no code generation */

#include <stdio.h>
#include "lex.h"

// opt_statements()
// {
//       opt_statements -> statement_list | Epsilon
    

//     statements_list();
// }

// statements_list()
// {
    
//         statement_list -> statements_list_prime | statement
    
//     statements();
//     statements_list_prime();
// }

// statements_list_prime()
// {
//     if(match( SEMI ))
//     {
//         advance();
//         statements();
//         statements_list_prime();
//     }
// }
statements()
{
    /*  statements -> expression SEMI
     *             |  expression SEMI statements
     */

    
    expression();

    if( match( SEMI ) )
	advance();
    else
        fprintf( stderr, "%d: Inserting missing semicolon\n", yylineno );

    if( !match(EOI) )
        statements();			/* Do another statement. */
    
}

expression()
{
    /* expression -> term expression' */

    term();
    expr_prime();
}

expr_prime()
{
    /* expression' -> PLUS term expression'
     *              | epsilon
     */

    if( match( PLUS ) )
    {
        advance();
        term();
        expr_prime();
    }
}

term()
{
    /* term -> factor term' */

    factor();
    term_prime();
}

term_prime()
{
    /* term' -> TIMES factor term'
     *       |   epsilon
     */

    if( match( TIMES ) )
    {
        advance();
        factor();
        term_prime();
    }
}

factor()
{
    /* factor   ->    NUM_OR_ID
     *          |     LP expression RP
     */

    if( match(NUM_OR_ID) )
        advance();

    else if( match(LP) )
    {
        advance();
        expression();
        if( match(RP) )
            advance();
        else
            fprintf( stderr, "%d: Mismatched parenthesis\n", yylineno);
    }
    else
	fprintf( stderr, "%d Number or identifier expected\n", yylineno );
}
