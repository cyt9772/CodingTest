#include <iostream>
using namespace std;
typedef unsigned short USHORT;
enum BOOL {FALSE, TRUE};

class Rectangle
{
public:
    Rectangle(USHORT width, USHORT height);
    ~Rectangle(){}

    //overload
    void DrawShape() const;
    void DrawShape(USHORT aWidth, USHORT aHeight) const;
private:
    USHORT itsWidth;
    USHORT itsHeight;
};

Rectangle::Rectangle(USHORT width, USHORT height){
    itsWidth=width;
    itsHeight=height;
}

void Rectangle::DrawShape() const {
    DrawShape(itsWidth, itsHeight);
}

void Rectangle::DrawShape(USHORT width, USHORT height) const{
    for(USHORT i=0;i<height;i++)
    {
        for(USHORT j=0;j<width;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    Rectangle theRect(30,5);
    cout<<"DrawShape(): \n";
    theRect.DrawShape();
    cout<<"\nDrawShape(40,2): \n";
    theRect.DrawShape(40,2);

    return 0;
}