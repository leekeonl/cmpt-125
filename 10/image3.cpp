#include <stdlib.h>
#include "image3.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Image::Image(){
    cols=0;
    rows=0;
    pixels=NULL;
}

Image::~Image(){
    cols=0;
    rows=0;
    delete pixels;
}

/* Changes the size of an image, allocating memory as necessary, and
 setting all pixels to fillcolor. Returns 0 on success, or a
 non-zero error code.*/
int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
    cols=width;
    rows=height;
    pixels = (uint8_t**)malloc(sizeof(uint8_t*) * rows);
    int i = 0;
    for(i = 0; i < rows; i++){
        pixels[i] = (uint8_t*)malloc(sizeof(uint8_t) * cols);
    }
    for (i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            pixels[i][j] = fillcolor;
        }
    }
    return 0;
}

/* Sets the color of the pixel at (x,y) to color. Returns 0 on
 success, else a non-zero error code. If (x,y) is not a valid
 pixel, the call fails and the image does not change.*/
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ){
    if(y>=rows || x>=cols) {
        return -2;
    }
    else {
        pixels[y][x]=color;
        return 0;
    }
}

/* Gets the color of the pixel at (x,y) and stores at the address
 pointed to by colorp. Returns 0 on success, else a non-zero error
 code. */
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
    if(x>=cols || y>=rows) {
        return -2;
    }
    else {
        if (colorp != NULL){
            *colorp=pixels[y][x];
            return 0;
        }
        else return -1;
    }
}

/* Saves the image in the file filename. In a format that can be
 loaded by load().  Returns 0 on success, else a non-zero error
 code. */
int Image::save( const char* filename ){
    
    ofstream OutputFile(filename);
    if(OutputFile.is_open()) {
        OutputFile<<cols<<"\n"<<rows<<"\n";
        for(int i=0; i<rows; i++) {
            for (int j = 0; j < cols; j++){
                cout << pixels[i][j] << endl;
                if(i==cols-1 && j == rows-1) {
                    OutputFile<<unsigned(pixels[i][j]);
                }
                else {
                    OutputFile<<unsigned(pixels[i][j])<<"\n";
                }
                
            }
            
        }
        OutputFile.close();
        return 0;
    }
    else {
        return 1996;
    }
}

/* Load the an image from the file filename, replacing the current
 image size and data. The file is in a format that was saved by
 save().  Returns 0 success, else a non-zero error code . */
int Image::load( const char* filename ){
    
    ifstream InputFile(filename);
    if(InputFile.is_open()) {
        unsigned int input;
        rows=cols=0;
        bool PixelsDeclaration=false, ColsAssignment=false, RowsAssignment=false;
        int i=0;
        int j = 0;
        
        
        if(!ColsAssignment){
            InputFile>>input;
            
            cols=(int)input;
            ColsAssignment = true;
        }
        if(!RowsAssignment){
            InputFile>>input;
            rows=(int)input;
            RowsAssignment = true;
        }
        if(!PixelsDeclaration) {
                
                resize(cols, rows, 10);
                
                for (i = 0; i < rows; i++){
                    for (j = 0; j < cols; j++){
                        InputFile>>input;
                        input = (int)input;
                        pixels[i][j] = input;
                    }
                }
                PixelsDeclaration=true;
            }
        InputFile.close();

        return 0;
        }
        
        
    else {
        return 1996;
    }
}


//int main(){
//
//    Image img;
//    img.load("array.txt");
////    Image img1;
////    img1.load("Hello.txt");
//
//    return 0;
//}