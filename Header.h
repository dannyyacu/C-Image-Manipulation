#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
using namespace std;
/*Daniel Yacu
dyacu
CPSC 1020 Fall 2021
PA2
Prototypes for storing header info*/

class Header{
    private:
        int w, h, max;
	    string imageType;    
    public:
    //constructors and destructors
        Header();
        Header(const Header& Header);
        Header(string ppm, int width, int height, int maxColor);
        ~Header();

    //overloading operators
        friend ostream& operator<<(ostream& out, const Header& header);
        Header& operator=(const Header& header);

    //non const reference getters
        int& width();
        int& height();
        int& max_color();
        string& ppmType();
    //getters
        int width() const;
        int height() const;
        int max_color() const;
        string ppmType() const;

};

#endif
