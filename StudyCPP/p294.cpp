#include <iostream>
using namespace std;
typedef unsigned short USHORT;
enum BOOL {FALSE, TRUE};

class Rectangle
{
public:
    Rectangle(USHORT width, USHORT height);
    ~Rectangle(){}

    void DrawShape(USHORT aWidth, USHORT aHeight, BOOL userCurrentVals=FALSE) const;
private:
    USHORT itsWidth;
    USHORT itsHeight;
};

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
    Rectangle theRect(30,5);
    cout<<"DrawShape(0,0,TRUE): \n";
    theRect.DrawShape(0,0,TRUE);
    cout<<"\nDrawShape(40,2): \n";
    theRect.DrawShape(40,2);

    return 0;
}