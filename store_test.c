#include "store.h"

int main() 
{
	char s[] = "main";
	char s1[] = "funk";
	int x = 2;
	init_store( x );
	store_add_def( s, x, s1 );
	store_add_def( s1, x, s );
}

