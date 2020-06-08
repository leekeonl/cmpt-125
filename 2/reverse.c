#include <stdio.h>
 
// declaration of function implemented in reverse.c
void reverse( int arr[], unsigned int len );
void swap(int * a,int * b); 

void reverse( int arr[], unsigned int len){
	for (int i =0; i < len/2; i++){
		swap(&arr[i], &arr[len-1-i]);
}	
}
void swap(int * a,int * b){
	int tmp = * a;
	*a = * b;
	*b= tmp;
}
