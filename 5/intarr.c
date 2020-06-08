#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len );

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia );

intarr_t* intarr_create( unsigned int len ){
	intarr_t *new = malloc(sizeof(intarr_t));
	
	if (new == NULL) return NULL;

	else {
		new->data = malloc(len *sizeof(int));
		new->len = len;
	}
	return new;
}

void intarr_destroy( intarr_t* ia ){
	if (ia != NULL && ia->data != NULL){
			free(ia->data);
		}	
}


/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, 
			    unsigned int index, 
			    int val );

// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index,
			    int* i );


intarr_result_t intarr_set( intarr_t* ia, 
			    unsigned int index, 
			    int val ){
	if (ia == NULL){
		return INTARR_BADARRAY;
	}
	if (index < (ia-> len) && (index > 0 || index == 0)){
		ia->data[index] = val;
		return INTARR_OK;
	}
	return INTARR_BADINDEX;
				
}

intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index,
			    int* i ){
	if (ia == NULL){
		return INTARR_BADARRAY;
	}
	if(i != NULL && index < (ia->len) && (index>0 || index == 0)){
		*i = ia->data[index];
		return INTARR_OK;	
	}
	return INTARR_BADINDEX;
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia );

intarr_t* intarr_copy( const intarr_t* ia ){
    intarr_t * deep_copy = intarr_create( ia ->len);
    deep_copy->data = malloc(ia->len * sizeof(int));
    deep_copy->len = ia-> len;
    memcpy(deep_copy->data, ia->data,ia->len *sizeof(int));
    return deep_copy;
}

/* LAB 5 TASK 4 */

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia );

intarr_result_t intarr_sort( intarr_t* ia ){
    if (ia != NULL){
        for (int i = 0; i < ia->len -1;i++){
            for(int j = 0; j < ia->len - i -1;j++){
                if(ia->data[j+1] < ia->data[j]){
                    int tmp = ia->data[j+1];
                    ia->data[j+1] = ia->data[j];
                    ia->data[j] = tmp;
                }
            }
        }
    return INTARR_OK;
}
    else{
        return INTARR_BADARRAY;
    }
}

/* LAB 5 TASK 5 */

// Find the first occurance of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i );

intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
    if (ia != NULL){
        for (int j = 0; j < ia->len; j++){
            if(ia->data[j] == target){
                *i = j;
                return INTARR_OK;
            }
        }
    }
    else{
        return INTARR_BADARRAY;
    }
    return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val );

// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i );

intarr_result_t intarr_push( intarr_t* ia, int val ){
    if (ia != NULL){
        ia->len++;
        ia->data = realloc(ia->data, ia->len * sizeof(int));
        ia->data[(ia->len)-1] = val;
        return INTARR_OK;
    }
    else{
        return INTARR_BADARRAY;
    }
    return INTARR_BADALLOC;
}

intarr_result_t intarr_pop( intarr_t* ia, int* i ){
    if(ia == NULL){
		return INTARR_BADARRAY;
	}
    else if((ia->len) == 0){
		return INTARR_BADINDEX;
	}
    else{
		*i = ia->data[(ia->len)-1];
		ia->len--;
		return INTARR_OK;
	}
}

/* LAB 5 TASK 7 */

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen );

intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
	if(ia == NULL){
		return INTARR_BADARRAY;
	}
	else{
		ia->data = realloc(ia->data, (sizeof(int)*newlen));
		if(ia->data != NULL){
			if (newlen < (ia->len)){
				ia->len = newlen;
			}
				if(newlen > (ia->len)){
                			for (int i = ia->len; i<newlen; i++){
						ia->data[i] = 0;
				}
				ia->len = newlen;
			}
			return INTARR_OK;
		}
	}
	return INTARR_BADALLOC;
}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last );

intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last ){
    if(ia == NULL || first < 0 || last < 0 || first >= ia->len || last >= ia->len || last < first) {
        return NULL;
    }
intarr_t *deepcopy = intarr_create(last - first + 1);
if(deepcopy != NULL) {
    int j = 0;
    for(int i = first; i < last+1; i++) {
        deepcopy->data[j++] = ia->data[i];
        }
    deepcopy->len = last - first + 1;
    }
return deepcopy;
}


/* -------------------------------------------------------------- */
