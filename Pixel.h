#ifndef PIXEL_H_
#define PIXEL_H_
#include <iostream>
using namespace std;
/*Daniel Yacu
dyacu
CPSC 1020 Fall 2021
PA2
prototypes for storing pixel data*/
class Pixel{
    private:
        unsigned char R,G,B;
    
    public:
    //constructors and destructors
        Pixel();
        Pixel(const Pixel& pixel);
        Pixel(unsigned char red, unsigned char green, unsigned char blue);
        ~Pixel();

    //overloading operators
        friend ostream& operator<<(ostream& out, const Pixel& pixel);
        Pixel& operator=(const Pixel& pixel);


    //non const reference getters
        unsigned char& r();
        unsigned char& g();
        unsigned char& b();

    //getters
        unsigned char r() const;
        unsigned char g() const;
        unsigned char b() const;

};

#endif