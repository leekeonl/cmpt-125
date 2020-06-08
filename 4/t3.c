#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "imgops.h"

void life( uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows );

uint8_t wrapup( uint8_t array[],
		unsigned int cols,
		unsigned int rows,
		unsigned int p,
		unsigned int q); 

void life( uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows ){

uint8_t* copies = copy( array, cols, rows );
	for(int i=0; i<cols; i++){
    		for(int j=0; j<rows; j++){
			{
				unsigned int final = wrapup( copies, cols, rows, i, j);
           	    
                if (get_pixel(array, cols, rows, i,j)>0){
                    if (final < 2){
					   set_pixel(array, cols, rows, i, j, 0);
				    }
				
				    if(final > 3){
                        set_pixel( array, cols, rows, i, j, 0);
                    }	
				
                    
                }
                else{
                    if(final == 3){
	  				     set_pixel( array, cols, rows, i, j, 255);
                    }
                }
				
		 
					
      }
}
}  
free(copies);}

uint8_t wrapup( uint8_t array[],
		unsigned int cols,
		unsigned int rows,
		unsigned int p,
		unsigned int q){
	
	unsigned int result = 0;
	for (int i = -1; i<=1; i++){
			for(int j = -1; j <=1; j++){
				if(! (i == 0 && j == 0) ){
					int x = (p+i+cols)%cols;
					int y = (q+j+rows)%rows;
                    if (get_pixel(array, cols, rows, x,y) > 0){
                        result++;
                    }
					
				}
		}
	}
	return result;
} 
