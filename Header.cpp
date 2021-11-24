#include "Header.h"
/*Daniel Yacu
dyacu
CPSC 1020 Fall 2021
PA2
Implementations for header.h*/

//constructors and destructors
Header::Header(){
    w = 0;
    h = 0;
    max = 0;
    imageType = '\0';
}

Header::Header(const Header& header){
    w = header.w;
    h = header.h;
    max = header.max;
    imageType = header.imageType;
}

Header::Header(string ppm, int width, int height, int maxVal){
    w = width;
    h = height;
    max = maxVal;
    imageType = ppm;
}

Header::~Header(){}

//operators
 ostream& operator<<(ostream& out, const Header& header){
    out << header.w << header.h << header.max << header.imageType;
    return out;
}
Header& Header::operator=(const Header& header){
    w = header.w;
    h = header.h;
    max = header.max;
    imageType = header.imageType;
    return *this;
}

//non const reference getters    
int& Header::width(){
    return w;
}
int& Header::height(){
    return h;
}
int& Header::max_color(){
    return max;
}
string& Header::ppmType(){
	return imageType;
}

//getters
int Header::width() const{
    return w;
}
int Header::height() const{
    return h;
}
int Header::max_color() const{
    return max;
}
string Header::ppmType() const{
    return imageType;
}
