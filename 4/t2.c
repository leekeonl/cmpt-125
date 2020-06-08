#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "imgops.h"

void draw_rectangle( 	  uint8_t array[], 
		          unsigned int cols, 
		          unsigned int rows, 
		          int x,
		          int y,
		          int rect_width,
		          int rect_height,
		          uint8_t color );


void draw_rectangle( 	  uint8_t array[], 
		          unsigned int cols, 
		          unsigned int rows, 
		          int x,
		          int y,
		          int rect_width,
		          int rect_height,
		          uint8_t color ){
	
	int col;
	int row;	

	if (0 < rect_width && 0 < rect_height){
		for(col = x; col<x+rect_width; col++){
			for(row = y; row<y+rect_height; row++){
				if(col<cols && row<rows){
					if(col == x || col == x+rect_width-1){
						set_pixel(array, cols, rows, col, row, color);
			}
					if(row == y || row == y+rect_height-1){
						set_pixel(array, cols, rows, col, row, color);
			}
		}
	}
}}	
	if (0 > rect_width && 0 > rect_height){
		for(col = x; col>x+rect_width; col--){
			for(row = y; row>y+rect_height; row--){
				if(col<cols && row<rows){
					if(col == x || col == x+rect_width+1){
						set_pixel(array, cols, rows, col, row, color);
			}
					if(row == y || row == y+rect_height+1){
						set_pixel(array, cols, rows, col, row, color);
			}
		}
	}
}}
	if (0 > rect_width && 0 < rect_height){
		for(col = x; col>x+rect_width; col--){
			for(row = y; row<y+rect_height; row++){
				if(col<cols && row<rows){
					if(col == x || col == x+rect_width+1){
						set_pixel(array, cols, rows, col, row, color);
			}
					if(row == y || row == y+rect_height-1){
						set_pixel(array, cols, rows, col, row, color);
			}
		}
	}
}}
	
	if (0 < rect_width && 0 > rect_height){
		for(col = x; col<x+rect_width; col++){
			for(row = y; row>y+rect_height; row--){
				if(col<cols && row<rows){
					if(col == x || col == x+rect_width-1){
						set_pixel(array, cols, rows, col, row, color);
			}
					if(row == y || row == y+rect_height+1){
						set_pixel(array, cols, rows, col, row, color);
			}
		}
	}
}}
return;
}
