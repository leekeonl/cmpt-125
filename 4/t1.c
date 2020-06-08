#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "imgops.h"
void draw_circle( uint8_t img[], 
                  unsigned int cols,
                  unsigned int rows,
		  int x,
		  int y,
		  int r,
		  uint8_t color );


void draw_circle( uint8_t img[], 
                  unsigned int cols,
                  unsigned int rows,
		  int x,
		  int y,
		  int r,
		  uint8_t color ){

		double xtoi, ytoj, distance;

		for (int i = 0; i < cols; i++){
			for (int j = 0; j < rows; j++){
				if(0 < r){
					xtoi = i-x+0.5;
					ytoj = j-y+0.5;
					distance = sqrt(pow(xtoi, 2) + pow(ytoj,2));
					if (distance < r){
						set_pixel(img, cols, rows, i, j, color);
	}

					xtoi = i-x-0.5;
					ytoj = j-y-0.5;
					distance = sqrt(pow(xtoi, 2) + pow(ytoj,2));
					if (distance < r){
						set_pixel(img, cols, rows, i, j, color);
}

					xtoi = i-x+0.5;
					ytoj = j-y-0.5;
					distance = sqrt(pow(xtoi, 2) + pow(ytoj,2));
					if (distance < r){
						set_pixel(img, cols, rows, i, j, color);
}
						
					xtoi = i-x-0.5;
					ytoj = j-y+0.5;
					distance = sqrt(pow(xtoi, 2) + pow(ytoj,2));
					if (distance < r){
						set_pixel(img, cols, rows, i, j, color);

}
		
}		
}}}
