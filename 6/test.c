#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char line[1000] = "[ 100, 200, 300]";
    char** tokens;
    tokens = str_split(line, ',');
    for (int i = 0; *(tokens+i); i++){
        
        printf("%s\n", *(tokens+i));
    }
//    printf("%d %d\n",sizeof(line), strlen(line));
//    int val1, val2, val3;
//    sscanf(line, "[ %d, %d, %d]", &val1, &val2, &val3);
//    printf("%i\n %i\n %i\n",val1, val2, val3);

    return 0;
}