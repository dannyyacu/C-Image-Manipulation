#ifndef IMAGE_H_
#define IMAGE_H_
#include "Pixel.h"
#include "Header.h"
#include <vector>
#include <iostream>
#include <fstream>

/*Daniel Yacu
dyacu
CPSC 1020 Fall 2021
PA2
prototypes for for reading and writing images*/
using namespace std;

class Image{
    private:
        vector<Pixel> PIX;
        Header HDR;
    
    public:
    //constructors and destructors
        Image(const Image& input);
        Image(ifstream& image);
        ~Image();

    //methods to build image
        vector<Pixel> read_pixels(const Header& header, ifstream& input);
        Header read_header(ifstream& input);

    //overloading operators
        Pixel& operator()(int x, int y);
        Image& operator=(const Image& image);
    
    //output file methods
        void write_header(ofstream& output) const;
        void write_to(ofstream& output) const;

    //getters
        const Header& header() const;
        const vector<Pixel>& pixels() const;
};


#endif