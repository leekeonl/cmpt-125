#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv){
	char max[1906];
	char change[] = "CENSORED";
	unsigned long len = strlen(argv[1]);
	
	while(fgets(max, sizeof(max), stdin) != 0)
	{
		char  * word;
		char  * initiate = max;
		for(int i = 1; i<argc; i++){
			unsigned long len = strlen(argv[i]);
			while(( word = strstr(initiate, argv[i])) != 0){
			printf("%.*s%s", (int)(word - initiate), initiate, change);
			initiate = word + len;
	}
	}
	printf("%s", initiate);
}
return 0;
}
