#include "Pixel.h"
#include "manip.h"
#include "Image.h"
#include "Header.h"
using namespace std;
/*Daniel Yacu
dyacu
CPSC 1020 Fall 2021
PA2
main driver to prompt user for choices*/

int main(int argc, char* argv[]){
   if(argc != 3) {
      cout << "USAGE: <executable> <image1> <image2>" << endl;
      return -1;
   }
    ifstream ClemsonPaw(argv[1]);
    ifstream Disney(argv[2]);

    Image image1(ClemsonPaw);
    Image image2(Disney);

    int manipChoice = 0;
    int imageChoice = 0;
    int imageCount = 1;
    do{
        cout << "PA2 Image Manipulation" << endl;
        cout << "1. gray scale" << endl;
        cout << "2. mirror" << endl;
        cout << "3. green screen" << endl;
        cout << "Press 0 to exit program" << endl;
        cin >> manipChoice;
        if(manipChoice != 0&& manipChoice!=1&& manipChoice!=2 &&manipChoice!=3){
            cout << "Not a valid choice" << endl;
            return -1;
        }
        if(manipChoice == 1){
            cout << "Image Choices:" << endl;
            cout << "1. ClemsonPaw.ppm" << endl;
            cout << "2. Disney.ppm" << endl;
            cin >> imageChoice;

            if(imageChoice != 1 && imageChoice != 2){
                cout << "Not a valid image choice" << endl;
                return -1;
            }
            else if(imageChoice == 1){
                string count = to_string(imageCount);
                string outImage = "out_"+count+".ppm";
                ofstream grayedImage(outImage);
                Image image(image1);
                gray(image);
                image.write_to(grayedImage);
                grayedImage.close();
                imageCount++;
            }
            else if(imageChoice == 2){
                string count = to_string(imageCount);
                string outImage = "out_"+count+".ppm";
                ofstream grayedImage(outImage);
                Image image(image2);
                gray(image);
                image.write_to(grayedImage);
                grayedImage.close();
                imageCount++;
            }
        }
        if(manipChoice == 2){
            cout << "Image Choices:" << endl;
            cout << "1. ClemsonPaw.ppm" << endl;
            cout << "2. Disney.ppm" << endl;
            cin >> imageChoice;

            if(imageChoice != 1 && imageChoice != 2){
                cout << "Not a valid image choice" << endl;
                return -1;
            }
            else if(imageChoice == 1){
                string count = to_string(imageCount);
                string outImage = "out_"+count+".ppm";
                ofstream mirroredImage(outImage);
                Image image(image1);
                mirror(image);
                image.write_to(mirroredImage);
                mirroredImage.close();
                imageCount++;
            }
            else if(imageChoice == 2){
                string count = to_string(imageCount);
                string outImage = "out_"+count+".ppm";
                ofstream mirroredImage(outImage);
                Image image(image2);
                mirror(image);
                image.write_to(mirroredImage);
                mirroredImage.close();
                imageCount++;
            }
        }
        if (manipChoice == 3){
            cout << "The Clemson Paw will be copied on the Disney Image";
            cout << endl;
            string count = to_string(imageCount);
            string outImage = "out_"+count+".ppm";
            ofstream greenScreenImage(outImage);
            Image Clemson(image1);
            Image Disney(image2);
            green_screen(Clemson, Disney);
            Clemson.write_to(greenScreenImage);
            greenScreenImage.close();
            imageCount++;
        }

        if (manipChoice == 0){
            cout << "Exiting Program" << endl;
        }

    }while (manipChoice != 0);
    
    ClemsonPaw.close();
    Disney.close();

return 0;
}
