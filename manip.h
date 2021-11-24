#ifndef MANIP_H_
#define MANIP_H_
#include <iostream>
#include "Image.h"
using namespace std;
/*Daniel Yacu
dyacu
CPSC 1020 Fall 2021
PA2
prototypes for manip functions*/
void gray(Image& image);
void mirror(Image& image);
void green_screen(Image& image1, Image& image2);

#endif