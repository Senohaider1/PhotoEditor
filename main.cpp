//FCAI-Programmming 1-2022-Assignment3-BONUS
//Program Name : ColoredPhotoshop.cpp
//Last Modification Date : 6/4/2022
//Author 1 and ID and Group : Kamal eldein tharwat kamal mohamed - 20210302 - group B
//Author 2 and ID and Group : Maryam mohamed yousri mohamed - 20210385 - Group B
//Author 3 and ID and Group : Yassin hassan badr hassan - 20210449 - Group B
//Teaching Assistant : Nesma mohamed
//Purbose : Making edits to photoes .
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
void invertImage();
void mergeimage ();
void flipImage();
void darkenandlightenimage ();
void rotateImage();
void DetectEdgesImage();
void enlargeImage();
void shrinkimage ();
void MirrorImage();
void shuffleImage();
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
            loadImage();
            invertImage();
            saveImage();
            continue;
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
            loadImage();
            flipImage();
            saveImage();
            continue;

        }
        if (choice=='5')
        {
            loadImage();
            darkenandlightenimage ();
            saveImage();
            continue;
        }
        if (choice=='6')
        {
            loadImage();
            rotateImage();
            saveImage();
            continue;
        }
        if (choice=='7')
        {
            loadImage();
        DetectEdgesImage()
            saveImage();
            continue;
        }
        if(choice=='8')
        {
            loadImage();
            enlargeImage();
            saveImage();
            continue;
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
            loadImage();
            MirrorImage();
            saveImage();
        }
        if(choice=='b')
        {
            loadImage();
            shuffleImage();
            saveImage();
            continue;
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
void invertImage()
{

    for (int i = 0; i < SIZE; i++)
    {
        for (int j =0; j <SIZE; j++)
        {
            image[i][j]=255-image[i][j];
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
void flipImage()
{
 int choice ;
 cout<<"1- vertically \n2- horizontally\n ";
 cin>>choice;
if(choice==1){
 for(int i=0 ; i<SIZE/2 ; i++){
    for(int j=0 ; j<SIZE ; j++){
            for(int k = 0 ; k<RGB ; k++){
      swap(image[i][j] , image[255-i][j]);
    }
  }
 }
}
if(choice==2){
 for(int i=0 ; i<SIZE ; i++){
    for(int j=0 ; j<SIZE/2 ; j++){
            for(int k = 0 ; k<RGB ; k++){
       swap(image[i][j] , image[i][255-j]);
    }
  }
 }
}
else cout<<"wrong choice ";
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
void rotateImage()
{
    int degree;
    cout<<"Rotate(90), (180), or (270) degrees\n";
    cin>>degree;
    if (degree==90)
    {   for(int i=0;i<SIZE/2;i++)
        {
            for(int j=i;j<SIZE-i-1;j++)
            {

                int temp=image[i][j];
                image[i][j]=image[j][SIZE-i-1];
                image[j][SIZE-i-1]=image[SIZE-i-1][SIZE-j-1];
                image[SIZE-i-1][SIZE-j-1]=image[SIZE-j-1][i];
                image[SIZE-j-1][i]=temp;
            }
        }
    }
    if (degree==180)
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j =0; j <SIZE; j++)
            {
                swap (image[i][j],image[255-i][255-j]);

            }
        }

    }
    if (degree==270)
    {
        for (int i=0;i<SIZE/2;i++)
        {
            for (int j=i;j<SIZE-i-1;j++)
            {

                int temp=image[i][j];
                image[i][j]=image[SIZE-1-j][i];
                image[SIZE-1-j][i]=image[SIZE-1-i][SIZE-1-j];
                image[SIZE-1-i][SIZE-1-j]=image[j][SIZE-1-i];
                image[j][SIZE-1-i]=temp;
            }
        }
    }
}
void DetectEdgesImage()
{
  for (int i= 0 ; i< SIZE ; i++){
    for(int j = 0; j<SIZE ; j++){
            for(int k = 0 ; k<RGB ; k++){
        if(image[i][j][k]-image[i][j+1][k]>10 || image[i][j][k]-image[i+1][j][k]>10){
           image[i][j][k]=0;
        }
        else
        {
          image[i][j][k]=255;
        }
    }
    }
}
void enlargeImage ()
{
    int choose8;

    cout<<"Which quarter to enlarge 1, 2, 3 or 4 : ";
    cin>>choose8;
    if(choose8==1)
    {
        for (int i = 0; i < (SIZE/2); i++){
            for (int j =0 ; j <(SIZE/2); j++){
                image2[(i*2)][(j*2)]=image[i][j];
                image2[(i*2)+1][(j*2)]=image[i][j];
                image2[(i*2)][(j*2)+1]=image[i][j];
                image2[(i*2)+1][(j*2)+1]=image[i][j];
            }
        }
        for (int i = 0; i < (SIZE); i++){
            for (int j =0 ; j <(SIZE); j++){
                image[i][j]=image2[i][j];
            }
        }
    }
    else if(choose8==2)
    {
        for (int i = 0; i < (SIZE/2); i++){
            for (int j =0 ; j <(SIZE/2); j++){
                image2[i*2][j*2]=image[i][j+128];
                image2[(i*2)+1][(j*2)]=image[i][j+128];
                image2[(i*2)][(j*2)+1]=image[i][j+128];
                image2[(i*2)+1][(j*2)+1]=image[i][j+128];
            }
        }
        for (int i = 0; i < (SIZE); i++){
            for (int j =0 ; j <(SIZE); j++){
                image[i][j]=image2[i][j];
            }
        }
    }
    else if(choose8==3)
    {
        for (int i = 0; i < (SIZE/2); i++){
            for (int j =0 ; j <(SIZE/2); j++){
                image2[i*2][j*2]=image[i+128][j];
                image2[(i*2)+1][(j*2)]=image[i+128][j];
                image2[(i*2)][(j*2)+1]=image[i+128][j];
                image2[(i*2)+1][(j*2)+1]=image[i+128][j];
            }
        }
        for (int i = 0; i < (SIZE); i++){
            for (int j =0 ; j <(SIZE); j++){
                image[i][j]=image2[i][j];
            }
        }
    }
    else if(choose8==4)
    {
        for (int i = 0; i < (SIZE/2); i++){
            for (int j =0 ; j <(SIZE/2); j++){
                image2[i*2][j*2]=image[i+128][j+128];
                image2[(i*2)+1][(j*2)]=image[i+128][j+128];
                image2[(i*2)][(j*2)+1]=image[i+128][j+128];
                image2[(i*2)+1][(j*2)+1]=image[i+128][j+128];
            }
        }
        for (int i = 0; i < (SIZE); i++){
            for (int j =0 ; j <(SIZE); j++){
                image[i][j]=image2[i][j];
            }
        }
    }
    else cout<<"Invaild choice";
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
void MirrorImage(){
int choice;
cout<<" 1- right \n 2- left \n 3- upper \n 4- lower"<<endl;
cin>>choice;
if(choice==1)
{
  for(int i=0 ; i<SIZE ; i++){
    for(int j=0 ; j<SIZE/2 ; j++){
            for(int k=0 ; k<RGB ; k++){
        image[i][j][k] = image[i][255-j][k];
    }
    }
  }
}
if(choice==2)
{
  for(int i=0 ; i<SIZE ; i++){
    for(int j=0 ; j<SIZE/2 ; j++){
            for(int k=0 ; k<RGB ; k++){
        image[i][255-j][k] = image[i][j][k];
}
}
}
}
if(choice==3)
{
      for(int i=0 ; i<SIZE/2 ; i++){
    for(int j=0 ; j<SIZE ; j++){
            for(int k = 0 ; k<RGB ; k++){
        image[255-i][j][k] = image[i][j][k];
}
}
}
}
if(choice==4)
{
 for(int i=0 ; i<SIZE/2 ; i++){
    for(int j=0 ; j<SIZE ; j++){
            for(int k = 0 ; k<RGB ; k++){
        image[i][j][k] = image[255-i][j][k];
}
}
}
}
}
void shuffleImage ()
{
    int row, col;
    string order;
    cout<< "Enter the order without spaces: ";
    cin.clear();
    cin.sync();

    getline(cin,order);
    for (int k = 0; k<4; k++)
    {
        int r,c;
        r= k<2 ? 0 : SIZE /2;
        row = order[k] < '3' ? 0 : SIZE / 2;
        for (int i=row; i< row + SIZE / 2;i++,r++)
        {
            col = (order[k]-'0')% 2 == 1 ? 0 : SIZE / 2;
            c= k%2 == 0 ? 0 :SIZE /2;
            for (int j = col; j < col + SIZE /2; j++, c++)
                image2[r][c] = image[i][j];
        }

    }
    char imageFileName[100];
    cout<<"Enter the target image file name: ";
    cin>> imageFileName;
    strcat (imageFileName,".bmp");
    writeGSBMP(imageFileName, image2);
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