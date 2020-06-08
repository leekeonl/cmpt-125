#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

/* LAB 6 TASK 2 */

/*
 Save the entire array ia into a file called 'filename' in a JSON
 text file array file format that can be loaded by
 intarr_load_json(). Returns zero on success, or a non-zero error
 code on failure. Arrays of length 0 should produce an output file
 containing an empty array.
 
 The JSON output should be human-readable.
 
 Examples:
 
 The following line is a valid JSON array:
 [ 100, 200, 300 ]
 
 The following lines are a valid JSON array:
 [
 100,
 200,
 300
 ]
 */
int intarr_save_json( intarr_t* ia, const char* filename );

/*
 Load a new array from the file called 'filename', that was
 previously saved using intarr_save(). The file may contain an array
 of length 0. Returns a pointer to a newly-allocated intarr_t on
 success (even if that array has length 0), or NULL on failure.
 */
intarr_t* intarr_load_json( const char* filename );

int intarr_save_json( intarr_t* ia, const char* filename ){
    if (ia == NULL){
        return 1;
    }
    if(filename==NULL){
        return 1;
    }
    int *arr = ia->data;
    int length = ia->len;
    FILE *f;
    f = fopen(filename, "w");
    if(f != NULL){
        fprintf(f,"[\n");
        for(int i = 0; i < length; i++){
            if(i != length-1)
            {
                fprintf(f, "%d,\n", arr[i]);
            }
            else{
                fprintf(f, "%d\n", arr[i]);
            }
        }
        fprintf(f, "]");
        fclose(f);
        return 0;
    }
    return 1;
}

intarr_t* intarr_load_json( const char* filename ){
    
    FILE* f = fopen(filename, "r");
    
    if (f == NULL){return NULL;}
    if(filename==NULL){
        return NULL;
    }
    int value;
    
    intarr_t* load = intarr_create(0);
    

    
    char lines[10000];
    
    while ( fgets(lines, 10000, f) )
    {
        if(lines[0] == '['){
            continue;
        }
        if ( sscanf(lines, "%d", &value) != 1 ){
                break;
        }
    
        if (lines[0] == ']' ){
                break;
        }   

        intarr_push(load, value);
    }
    fclose(f);
    return load;
}

//int main(){
//    
//    intarr_t * ia = intarr_load_json( 'test.txt' );
//    if (ia == NULL){
//        printf("Null");
//    }
//    int *arr = ia->data;
//    int length = ia->len;
//        printf("[\n");
//        for(int i = 0; i < length; i++){
//            if(i != length-1)
//            {
//                printf("%d,\n", arr[i]);
//            }
//            else{
//                printf("%d\n", arr[i]);
//            }
//        }
//        printf("]");
//
//    
//    return 0;
//}