#include <stdlib.h>
#include <stdio.h>
#include "store.h"
#include <string.h>
int init_store( int size )
{
	store = malloc( sizeof( fun_data_t ) );
	store->fu_name = "0";
	store->next = NULL;
	if( store == NULL )
		return EXIT_FAILURE;
	return 0;
}

void store_add_def( char* fu_name, int line_num, char* file_name )
{
	fun_data_t *itr = store;
	
	while( strcmp( itr->fu_name, fu_name ) != 0 && itr->next != NULL ) 
		itr = itr->next;
	if( itr->next == NULL ) {
		itr->next = malloc( sizeof( fun_data_t ) );
		itr = itr->next;
		itr->next = NULL;
	}

	itr->fu_name = malloc( strlen(fu_name) *sizeof( char ) );
        strcpy( itr->fu_name, fu_name );
        printf( "To jest funkcja: %s\n", itr->fu_name );

	
}

