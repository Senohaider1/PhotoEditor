#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

void loadImage();
void saveImage();
void BlackAndWhite();

int main()
{

    while (true)
    {
        char choice;
        cout<<"Ahlan ya user ya habibi.\n";
        cout<<"Please select a filter to apply or 0 to exit:\n1- Black & White Filter\n2- Invert Filter\n3- Merge Filter";
        cout<<"\n4- flib Image \n5- Darken and Lighten Image \n6- Rotate Image\n7- Detect edges of Image\n8- Enlarge Image";
        cout<<"\n9- Shrink Image \na- Mirror 1/2 Image \nb- Shuffle Image \nc- Blur Image \ns- save Image \n0- Exit\n";
        cin>>choice;

        if(choice=='1')
        {
            loadImage();
            BlackAndWhite();
            saveImage();
            continue;
        }
        if (choice=='2')
        {

        }
        if (choice=='3')
        {

        }
        if(choice=='4')
        {

        }
        if (choice=='5')
        {

        }
        if (choice=='6')
        {

        }
        if (choice=='7')
        {

        }
        if(choice=='8')
        {

        }
        if(choice=='9')
        {

        }
        if(choice=='a')
        {

        }
        if(choice=='b')
        {

        }
        if(choice=='c')
        {

        }
        if(choice=='s')
        {

        }
        if(choice =='0')
        {

        }

        else
        {

        }

    }
}
void loadImage()
{
    char imageFileName[100];
    cout<<"Please enter file name of the image to process: ";
    cin>> imageFileName;
    strcat (imageFileName,".bmp");
    readGSBMP(imageFileName, image);
}

void saveImage()
{
    char imageFileName[100];
    cout<<"Enter the target image file name: ";
    cin>> imageFileName;
    strcat (imageFileName,".bmp");
    writeGSBMP(imageFileName, image);
}

void BlackAndWhite()
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j< SIZE; j++)
    {
        if (image[i][j] > 127)
            image[i][j] = 255;
        else
            image[i][j] = 0;
    }
  }
}
