#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "point_array.h"

/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS
   NULL */

/* TASK 1 */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa );

/* TASK 2 */

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa );

/* TASK 3 */

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p );

/* TASK 4 */

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i );

void point_array_init( point_array_t* pa ){
    assert(pa != NULL);
    pa->points = NULL;
    pa->len = 0;
}

void point_array_reset( point_array_t* pa ){
    assert(pa != NULL);
    pa->points = NULL;
    pa->len = 0;
    free(pa->points);
}

int point_array_append( point_array_t* pa, point_t* p ){
    if(pa==NULL ||p==NULL)
		return 1;
	else{
		pa->points =realloc (pa->points,sizeof(point_t)* (pa->len + 1));
		pa->points[pa->len] = *p;
		pa->len++;
		if(pa->points==NULL)
			return 1;
		return 0;
	}
}

int point_array_remove( point_array_t* pa, unsigned int i ){
   if(pa == NULL || i>= pa->len){
    return 1;
}
    else{
pa->points[i] = pa->points[pa->len-1];
pa->points = realloc(pa->points, sizeof(point_t)*(pa->len-1));

    if(pa->points != NULL || pa->len > 0){
        pa->len--;
        return 0;
    }
}
return 1;
}

//assert(pa != NULL);
//pa->points = (point_t*) realloc (pa->points, (pa->len+1) * sizeof(point_t));
//pa->points[pa->len++] = *p;
//return 0;