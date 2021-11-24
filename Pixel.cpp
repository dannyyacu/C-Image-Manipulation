#include "Pixel.h"
/*Daniel Yacu
dyacu
CPSC 1020 Fall 2021
PA2
implementations for pixel.h*/

//constructors and destructors
Pixel::Pixel(){
    R = 0;
    G = 0;
    B = 0;
}
Pixel::Pixel(const Pixel& pixel){
    R = pixel.R;
    G = pixel.G;
    B = pixel.B;
}
Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue){
    R = red;
    G = green;
    B = blue;
}
Pixel::~Pixel(){}


//overloading operators
ostream& operator<<(ostream& out, const Pixel& pixel){
    out << pixel.R << pixel.G << pixel.B;
    return out;
}
Pixel& Pixel::operator=(const Pixel& pixel){
    R = pixel.R;
    G = pixel.G;
    B = pixel.B;
    return *this;
}


//non const reference getters
unsigned char& Pixel::r(){
    return R;
}
unsigned char& Pixel::g(){
    return G;
}
unsigned char& Pixel::b(){
    return B;
}


//getters
unsigned char Pixel::r() const{
    return R;
}
unsigned char Pixel::g() const{
    return G;
}
unsigned char Pixel::b() const{
    return B;
}