#include "skorowidz.h"

/*tworzy struktore do przechowywania wystpien slow w poszczegolnych liniach
 * wiersze to slowa
 * wartosci w kolumnach odpowiadaja wsytepowania poszczegolnych slow w liniach */
int **init_words_in_lines(int n) 
{
	num_of_rows = n;
	int **lines;
       	lines = malloc(num_of_rows * sizeof(int*));	
	for(int i = 0; i < num_of_rows; i++) {
		lines[i] = malloc(num_of_columns * sizeof(int*));
		lines[i][0] = 0;
	}
	return lines;
}

/*sprawdza czy slowo wystepuje w lini i zapisuje je do struktury*/

void words_in_lines(FILE *in, int num_words, int **lines, char **words) 
{
	int i;
	char buf[BUFSIZE];
	int  num_lines = 0;
        while( fgets( buf, BUFSIZE, in ) != NULL ) {
                num_lines++;
                for( i= 0; i < num_words; i++ )
                        if( str_str( buf, words[i] ) != NULL ) {
                                lines[i][0]++;
                                if(lines[i][0] == num_of_columns) {
                                        num_of_columns *= 2;
                                        for(int i = 0; i < (num_of_rows); i++)
                                                lines[i] = realloc(lines[i], num_of_columns * sizeof(int*));
                                }
                                lines[i][lines[i][0]]= num_lines;
                        }
        }
}

void print_words_in_lines(int num_of_words, int **lines, char **words) 
{
	int i, j;
	for( i= 0; i < num_of_words; i++ ) {
		if( lines[i][0] > 0 ) {
                        printf( "słowo \"%s\" wystąpiło w liniach:", words[i] );
                        for( j= 1; j <= lines[i][0]; j++ )
                                printf( " %d", lines[i][j] );
                        printf( "\n" );
                } else {
                  printf( "nie napotkano słowa \"%s\"\n", words[i] );
                }
        }
}
