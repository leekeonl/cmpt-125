#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int test = 0;
	int same = 1;
    
    char *str1 = argv[1];
    char *str2 = argv[2];

		
	if(argc == 3){
		if(strlen(str2) > strlen(str1)){
			printf("false\n");
			return 0;
		}
		for(int i=0; i<strlen(str1)-strlen(str2)+1; i++){
			if(str2[0] == str1[i]){
			for(int j=0; str2[j] != NULL; j++){
				if(str2[j] != str1[i+j]){
					same = 0;
					break;
					}
				}
				if(same != 0){
					test = 1;
				}
			}
		}
	if(test != 0){
			printf("true\n");
		}
	else{
			printf("false\n");}
		
}

	else	
	{
		printf("Two arguments.\n");
		return 0;
	}
	return 0;
}
