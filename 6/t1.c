#include <stdio.h>
#include <stdlib.h>

#include "intarr.h"

/* -------------------------------------------------------------- */

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename );

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename );


int intarr_save_binary( intarr_t* ia, const char* filename ){
    if ( ia == NULL ){
        return 1;
    }
    if(filename==NULL){
        return 1;
    }
    int *arr=ia->data;
    int length=ia->len;
    FILE *f;
    f=fopen(filename,"wb");
    
    if(f != NULL){
        for(int i=0;i<length;i++){
            fwrite(&arr[i],sizeof(int), 1, f);
        }
        fclose(f);
        return 0;
    }
    return 1;
}


intarr_t* intarr_load_binary( const char* filename ){
    FILE *f;
    f = fopen(filename, "rb");
    intarr_t *c;
    
    if (filename == NULL){
        return NULL;
    }
    
    if (f != NULL){
        int initiate = (int) ftell(f);
        fseek(f, sizeof(int), SEEK_END);
        int init = (int)ftell(f);
        int cnt = (init-initiate-1)/sizeof(int);
        int s;
        int count = 0;
        c = intarr_create(cnt);
        rewind(f);
        while(0 < fread(&s, sizeof(s), 1, f)){
            c->data[count++] = s;
        }
    }
    else{
        return NULL;
    }
    return c;
}
