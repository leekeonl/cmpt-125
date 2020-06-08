/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows ){
	
    memset(array, 0, (rows*cols*sizeof(uint8_t)));
	return; 
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{

	uint8_t * copyArray = malloc(rows*cols*sizeof(uint8_t));
	for (int i = 0; i < rows*cols; i++){
		copyArray[i] = array[i];
}
	return copyArray;
  // your code here
  return NULL;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  uint8_t minimum = array[0];
    for(int i = 0; i < rows*cols; i++){
        if(array[i] < minimum){
            minimum = array[i];
        }
    }
  return minimum;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  uint8_t maximum = array[0];
    for(int i = 0; i < rows*cols; i++){
        if(array[i] > maximum){
            maximum = array[i];
        }
    }
  return maximum;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  for(int i = 0; i < rows*cols; i++){
      
      if(array[i] == pre_color){
          array[i] = post_color;
      }
  }
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
   	unsigned int i = 0;	
	unsigned int j = cols - 1;
	for (int k = 0; k < rows; k++){
		while (i != j && j>i){
			int first = k*cols + j;
			int second = k*cols +i;
			int temp = array[first];
			array[first] = array[second];
			array[second] = temp;
			i++;
			j--;
			}
	
	i = 0;
	j = cols - 1;	
} 
}


// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
	int height = rows;
	int width = cols;
	for (int i = 0; i < cols; i++){
		for (int j =0; j < rows/2; j++){
			int temp = array[i+j*width];
			array[i+j*width] = array[i+(height - j - 1) *width];
			array[i+(height - j - 1) *width] = temp;
		}
	} 
        }
//    memset(array, 0, rows*cols*sizeof(uint8_t));
//    array = copy( newcopy, 
//           cols, rows );
    

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    for (int i =0; i < rows; i++) {
      for (int j =0; j<cols; j++) {
        if ((get_pixel(array, cols, rows, j, i)) == color) {
          *x = j;
          *y = i;
          return 1;
          }
        }
      }
	
	return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    uint8_t reverse;
    for (int i = 0; i<cols; i++) {
    	for (int j = 0; j<rows; j++) {
        	reverse = get_pixel(array, cols, rows, i, j);
        	set_pixel(array, cols, rows, i, j, 255 - reverse);
      	}
    }
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
	int arrays = cols*rows;
  	for (int i=0; i<arrays; i++) {
    	float j = round(scale_factor*array[i]);
    	if (j >= 255){
      		array[i] = 255;
    	}
    	else {
      		array[i] = j;
      		}
  	}	
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{

	uint8_t maxValue = 0;
	uint8_t minValue = 255;
    	uint8_t numbers;
	int arrays = cols*rows;
    	for(int i=0; i<arrays;i++){
     		if(array[i]>maxValue){
        		maxValue = array[i];
      		}
      
		if (array[i]<minValue) {
        		minValue = array[i];
      		}
}

    uint8_t differ = maxValue - minValue;

    for(int i=0; i<arrays ;i++){
    	numbers = round((array[i]-minValue)*(255.0/differ));
     	array[i] = numbers;
    }

}
/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  if (cols % 2 != 0) {
    	cols = cols - 1;
	}
  if (rows % 2 != 0) {
    	rows = rows - 1;
	}
	unsigned int new_col = cols / 2;
	unsigned int new_row = rows / 2; 
	uint8_t *newmatrix = malloc(new_row * new_col * sizeof(uint8_t));
	if (newmatrix != 0) {
		for (int i = 0; i < new_col; i += 1) {
			for (int j = 0; j < new_row; j += 1) {
                    
        			uint8_t color = round((get_pixel(array, cols, rows, 2*i, 2*j)+ get_pixel(array, cols, rows, (2*i)+1, (2*j)) + get_pixel(array, cols, rows, (2*i) + 1, (2*j) + 1) + get_pixel(array, cols, rows, (2*i), (2*j) + 1))/4.00);
                    
        			set_pixel(newmatrix, new_col, new_row, i, j, color);
	}
	}
            
			return newmatrix;
	}
	else { 
        
        
        return NULL;}
		
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
	if ((top != bottom) && (right != left)) {
		for (int i = left; i<right; i++) {
			for (int j = top; j<bottom; j++) {
				set_pixel(array, cols, rows, i, j, color);
		}
		}
}   
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{ uint64_t sum = 0;
	if ((top != bottom) && (right != left)) {
		for (int i = left; i<right; i++) {
			for (int j = top; j<bottom; j++) {
          			sum = sum + get_pixel(array, cols, rows, i, j);
			}
		}
		return sum;
	}
	return 0;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
	int length = right - left;
	int width = bottom - top;
	uint8_t *newmatrix = malloc((length) * (width) * sizeof(uint8_t));
	if ((top != bottom) && (right != left)) {
		for (int i = left; i<right; i++) {
			for (int j = top; j<bottom; j++) {
				int8_t color = get_pixel(array, cols, rows, i, j);
				set_pixel(newmatrix, length, width, i - left, j - top, color);
			}
		}
		return newmatrix;
	}
	return NULL;
}


