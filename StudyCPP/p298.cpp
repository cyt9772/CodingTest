#include <iostream>
using namespace std;
typedef unsigned short USHORT;
enum BOOL {FALSE, TRUE};

class Rectangle
{
public:
    Rectangle();
    Rectangle(USHORT width, USHORT height);
    ~Rectangle(){}

    void DrawShape(USHORT aWidth, USHORT aHeight, BOOL userCurrentVals=FALSE) const;
    int GetWidth() const {return itsWidth;}
    int GetHeight() const {return itsHeight;}
private:
    USHORT itsWidth;
    USHORT itsHeight;
};

Rectangle::Rectangle(){
    itsWidth=5;
    itsHeight=10;
}

Rectangle::Rectangle(USHORT width, USHORT height){
    itsWidth=width;
    itsHeight=height;
}

void Rectangle::DrawShape(USHORT width, USHORT height, BOOL userCurrentVals) const{
    int printWidth;
    int printHeight;
    
    if(userCurrentVals==TRUE)
    {
        printWidth=itsWidth;
        printHeight=itsHeight;
    }else{
        printWidth=width;
        printHeight=height;
    }
    for(USHORT i=0;i<printHeight;i++)
    {
        for(USHORT j=0;j<printWidth;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    Rectangle Rect1;
    cout<<"Rect1 Width: "<<Rect1.GetWidth()<<endl;
    cout<<"Rect1 Height: "<<Rect1.GetHeight()<<endl;

    int aWidth, aHeight;
    cout<<"Enter Width: ";
    cin>>aWidth;
    cout<<"Enter Height:";
    cin>>aHeight;

    Rectangle Rect2(aWidth, aHeight);
    cout<<"Rect1 Width: "<<Rect2.GetWidth()<<endl;
    cout<<"Rect1 Height: "<<Rect2.GetHeight()<<endl;

    return 0;
}