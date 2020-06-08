#include <stdio.h>

int count = 0;
int frequent[26];
char character;
int main(){
	for(int i = 0; i<26; i++){
		frequent[i] =0;
	}

	while((character=getchar()) != EOF){
		if(character >= 'a' && character <= 'z'){
			frequent[ character-97]++;
			count++;
		}
		else if (character >= 'A' && character <= 'Z'){
			frequent[character-65]++;
			count++;
		}
		if(character == EOF){
			printf("");
			break;
		}	
	}
    for(int i = 0; i < 26; i++){
        if(frequent[i] != 0){
            printf("%c %.4f\n", (i+97), ((float)frequent[i]/count));
        }
    }

	return 0;
}
