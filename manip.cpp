#include "manip.h"
/*Daniel Yacu
dyacu
CPSC 1020 Fall 2021
PA2
implementations for manip functions*/

void gray(Image& image){
    Header header = image.header();
    for (int row = 0; row < header.height(); row++) {
            for (int col = 0; col < header.width(); col++) {
                int avg = ( image(row,col).r() +
			                image(row,col).g() +
					        image(row,col).b() ) / 3;     
                image(row,col).r() = avg;
                image(row,col).g() = avg;
                image(row,col).b() = avg;
        }
    }
}

void mirror(Image& image){
    Header header = image.header();
    for (int row = 0; row < header.height(); row++) {
            for (int col = 0; col < header.width()/2; col++) {
                Pixel temp = image(row,col);
                image(row,col) = image(row,header.width() - col - 1);
                image(row, header.width() - col - 1) = temp;
            }
      }
}

void green_screen(Image& image1, Image& image2){
    Header header = image1.header();
    for(int row = 0; row < header.height(); row++){
        for(int col = 0; col < header.width(); col++){
            if(image1(row,col).g() == 255){
                image1(row,col) = image2(row,col);
            }    
        }
    }
}

