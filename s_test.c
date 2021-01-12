#include "fun_stack.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() 
{
	time_t tt;
	int seed;
	seed = time(&tt);
	srand(seed);

	int x = 5;
	char* s = "Nazwa funkcji";
	
	while ( x <= 97 ) {
		x = (int)(rand()/ (RAND_MAX + 1.0) * 100.0);
		put_on_fun_stack( x , s );
		top_of_funstack();
		char *st = get_from_fun_stack();
		printf( "to bylo na stosie: %s\n", st );
	}
	
	get_from_fun_stack();
	return 0;
}
