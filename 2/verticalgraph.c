#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>



int main(){
	int array[81];
	int j = 0;
	int input;

	while(input != EOF){
		input = scanf("%d", &array[j]);
		j++;
	}
	
	int max = 0;
	for (int i =0; i<j-1; i++){
		if((array[i])>max){
		max = (array[i]);
	}
}

	for (int k = max; 0<k; k--){
		for (int l = 0; l <j-1; l++){
		if(k < array[l]+1){
			printf("#");}
		else
	{
			printf(" ");
	}
}
printf("\n");}
return 0;}
