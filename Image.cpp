#include "Image.h"
/*Daniel Yacu
dyacu
CPSC 1020 Fall 2021
PA2
Implementations for image.h*/

//constructors and destructors
Image::Image(const Image& input){
    PIX = input.PIX;
    HDR = input.HDR;
}
Image::Image(ifstream& input){
    HDR = read_header(input);
    PIX = read_pixels(HDR, input);
}
Image::~Image(){}

//methods to build image
vector<Pixel> Image::read_pixels(const Header& header, ifstream& input){
        vector<Pixel> temp(header.height()*header.width());
        unsigned char r,g,b;
        for(Pixel& x : temp){
                r = input.get();
                g = input.get();
                b = input.get();
                Pixel pixel(r,g,b);
                x = pixel;
            }
    return temp;
}
Header Image::read_header(ifstream& input){
    Header header;
    input >> header.ppmType();
    input >> header.width() >> header.height() >> header.max_color();
    input.ignore(256, '\n');
    return header; 
}

//overloading operators
Pixel& Image::operator()(int x, int y){
    x = x * HDR.width() + y;
    return PIX[x];
}

Image& Image::operator=(const Image& image){
    PIX = image.PIX;
    HDR = image.HDR;
    return *this;
}

//output file methods
void Image::write_header(ofstream& output) const{
    output << HDR.ppmType() << endl;
    output << HDR.width() << " " << HDR.height() <<  endl;
    output << HDR.max_color() << endl;
}
void Image::write_to(ofstream& output) const{
    write_header(output);
    for(Pixel x : PIX){
        output << x;
    }
}                                    

//non const reference getters
const Header& Image::header() const{
    return HDR;
}
const vector<Pixel>& Image::pixels() const{
    return PIX;
}

