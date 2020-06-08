#include <stdio.h>
// declaration of function implemented in scrambled.c
int scrambled( unsigned int a[], unsigned int b[], unsigned int len );

int scrambled (unsigned int a[], unsigned int b[], unsigned int len ){
	
int sameFound = 0;
if (len == 0) {return 1;}
	for (int i = 0; i < len; i++) {
		sameFound = 0;
        	for (int j = i; j <len; j++) {
            		if(a[i] == b[j]){
            			b[j] = b[i];
				sameFound = 1;
                		break;
		}
        }

        if(sameFound==0) {
            return sameFound;
        }}
    
    return sameFound;}
