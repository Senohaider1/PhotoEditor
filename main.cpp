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
void mergeimage ();
void darkenandlightenimage ();
void blurImage();


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
            loadImage();
            mergeimage ();
            saveImage();
            continue;
        }
        if(choice=='4')
        {

        }
        if (choice=='5')
        {

        }
        if (choice=='6')
        {
            loadImage();
            darkenandlightenimage ();
            saveImage();
            continue;
        }
        if (choice=='7')
        {

        }
        if(choice=='8')
        {

        }
        if(choice=='9')
        {
            loadImage();
            shrinkimage ();
            saveImage();
            continue;
        }
        if(choice=='a')
        {

        }
        if(choice=='b')
        {

        }
        if(choice=='c')
        {
            loadImage();
            blurImage();
            saveImage();
            continue;
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
void mergeimage (){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image2[i][j] = image[i][j];
        }
    }
    cout <<"Enter the file name of the second photo :";
    loadImage();
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j] = (image2[i][j]+image[i][j])/2;
        }
    }
}
void darkenandlightenimage (){
    char choose6;
    cout<<"Do you want to (d)arken or (l)ighten :";
    cin>>choose6;
    if(choose6=='d'){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j< SIZE; j++){
                image[i][j]=image[i][j]/2;
            }
        }
    }
    else if(choose6=='l'){
        int num=0;
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j< SIZE; j++){
                num=image[i][j]+image[i][j]*0.5;
                if (num>255)    num=255;
                image[i][j]=num;
            }
        }
    }
    else cout<<"ERROR INVALID CHOOSE";
}
void shrinkimage (){
    float choose9;
    cout<<"1-Shrink to (1/2)\n2-Shrink to (1/3) \n3-Shrink to (1/4) \nchoose :";
    cin>>choose9;
    if (choose9==1){
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i/2][j/2]=image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++){
            for (int j =SIZE/2 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
        for (int i = SIZE/2; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
    }
    if (choose9==2){
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i/3][j/3]=image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++){
            for (int j =SIZE/3 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
        for (int i = SIZE/3; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
    }
    if (choose9==3){
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i/4][j/4]=image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++){
            for (int j =SIZE/4 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
        for (int i = SIZE/4; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
                image[i][j]=255;
            }
        }
    }
}
void blurImage() {
    char choosec;
        for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
               image[i][j]= (image[i][j-1]+image[i-1][j]+image[i-1][j-1]+image[i+1][j-1]
              +image[i+1][j]+image[i+1][j+1]+image[i][j+1]+image[i-1][j+1])/8;
            }
        }
                for (int i = 0; i < SIZE; i++){
            for (int j =0 ; j <SIZE; j++){
               image[i][j]= (image[i][j-1]+image[i-1][j]+image[i-1][j-1]+image[i+1][j-1]
              +image[i+1][j]+image[i+1][j+1]+image[i][j+1]+image[i-1][j+1])/8;
            }
        }
}