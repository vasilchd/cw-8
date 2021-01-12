#include "fun_stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FUN_NAME_MAX 100

static int stack_size = 10;
static int next_free = 0;
static stack_t *stack;
char temp[FUN_NAME_MAX];
static int stack_exist = 0;

void put_on_fun_stack( int par_level, char *funame)
{
	if( stack_exist == 0 ) {
		stack_exist = 1;
		stack = malloc( stack_size * sizeof(stack_t) );
	}
	else if( next_free + 1 == stack_size) {
		stack_size *= 2;
		stack = realloc( stack, stack_size * sizeof(stack_t) );	
	}
	stack[next_free].par_level = par_level;
	int len = strlen( funame );

	stack[next_free].funame = malloc( (len + 1) * sizeof(char) );

	if( stack[next_free].funame == NULL ) 
		printf( "ERROR, nie mozna zaalokowac pamieci" );
		

	for( int i = 0; i < len; i++ ) 
		stack[next_free].funame[i] = funame[i];

	next_free++;
}

int top_of_funstack()
{
	if( stack_exist == 0 ) 
		return 1;
	else if( next_free == 0 ) {
		printf( "Stos pusty" );
		return 2;
	}
	printf( "Zageszczenie nawiasowe: %d\n ", stack[next_free - 1].par_level );
}

char *get_from_fun_stack()
{
	if( stack_exist == 0 ) {
		printf( "ERROR, stos nie istnieje" );
		return "ERROR"; 
	}
	else if( next_free == 0 ) {
		printf( "ERROR, STOS JEST PUSTY" );
		return "STOS JEST PUSTY";
	}
	next_free-= 1;
	return stack[next_free].funame;
}


