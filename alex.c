#include "alex.h"

#include <ctype.h>
#include <string.h>


static int  ln= 0;
static char ident[256];
static FILE *ci= NULL;

void    alex_init4file( FILE *in ) {
   ln= 0;
   ci= in;
}

lexem_t alex_nextLexem( void ) {
	char keyword[18][10]={"assert.h" , "ctype.h" ,"errno.h" ,"float.h" ,"limits.h" ,"locale.h" ,"math.h" , "setjmp.h" ,"signal.h" ,"stdarg.h" ,"stddef.h" ,"stdio.h" ,"stdlib.h" ,"wchar.h" ,"wctype.h" ,"string.h" ,"time.h" ,"iso646.h"} ;
	
	int c,flag=0;
	while( (c= fgetc(ci)) != EOF ) {
    		if( isspace( c ) )
			continue;
		for(i = 0; i < 18; i++) {
     		 if(strcmp(c,keyword[i])==0) {
        		 flag=1;
			 break;
     		   }
  		 }
		if (flag==1)
			continue;
    		else if( c == '\n' )
                        ln++;
    		else if( c == '(' )
                        return OPEPAR;
    		else if( c == ')' )
      			return CLOPAR;
    		else if( c == '{' )
                        return OPEBRA;
    		else if( c == '}' )
                        return CLOBRA;
    		else if( isalpha( c ) ) {
      			int i= 1;
      			ident[0] = c;
      			while( isalnum( c= fgetc(ci) ) )
                                ident[i++] = c;
      			ident[i] = '\0';
      			return isKeyword(ident) ? OTHER : IDENT;
     		}
    		else if( c == '"' ) {
      		/* Uwaga: tu trzeba jeszcze poprawic obsluge nowej linii w trakcie napisu
        	 i w napisie 
     		 */
    			int cp = c;
      			while( (c= fgetc(ci)) != EOF && c != '"' && cp == '\\' ) {                             				cp = c;
      			}
      			return c==EOF ? EOFILE : OTHER; 
    		 } 
    		else if( c == '/' ) {
     		 /* moze byc komentarz */
               	}
    		else if( isdigit( c ) || c == '.' ) 
    		  /* liczba */
			return OTHER;

    		else 
			return OTHER;
                
	}       
  	return EOFILE;
}

char *  alex_ident( void ) {
   return ident;
}

int     alex_getLN() {
        return ln;
}

