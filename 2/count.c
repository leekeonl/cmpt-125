#include <ctype.h>
#include <stdio.h>
int ischar(char characters);
int main(){
	unsigned long charcount = 0;
	unsigned long wordcount = 0;
	unsigned long linecount = 0;
	int characters;
	int c;
	while( (characters = getchar()) != EOF){
		charcount++;
		if(ischar(characters)!=1 && ischar(c)==1){
			wordcount++;
		}
		if(characters == '\n') {
			linecount++;
		}
		c = characters;	
}
	printf("%lu %lu %lu\n", charcount, wordcount, linecount);
	return 0;
}


int ischar(char characters)
{
	int isUpper = ('A' <= characters && characters <= 'Z') ? 1 : 0;
	int isLower = ('a' <= characters && characters <= 'z') ? 1 : 0;
	int isApost = (characters == 39) ? 1 : 0;
	if(isUpper!=1 && isLower!=1 && isApost!=1){
		return 1;
	}else{
		return 0;
	}

}
