#ifndef _STORE_H_IS_INCLUDED_
#define _STORE_H_IS_INCLUDED_

typedef struct coordinates {
	char *file_name;
	int from;
	int to;
} coordinates_t;

typedef struct call {
	char *call_f_name;
	int times;
} call_t;

typedef struct fun_data {
	char *fu_name;
	coordinates_t *prototype;
	coordinates_t *definition;
	coordinates_t *use;
	call_t *calls;
	struct fun_data *next;
} fun_data_t;

fun_data_t *store;

void store_add_def( char*, int, char* );
void store_add_proto( char*, int, char* );
void store_add_call( char*, int, char* );
int init_store( int );


#endif
