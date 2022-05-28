#include <iostream>
using namespace std;

class Rectangle
{
public:
    Rectangle();
    ~Rectangle();
    
    void SetLength(int length){itsLength=length;}
    int GetLength(){ return itsLength;}

    void SetWidth(int width){itsWidth=width;}
    int GetWidth(){ return itsWidth;}

private:
    int itsLength;
    int itsWidth;
};

Rectangle::Rectangle():
    itsWidth(5),
    itsLength(10)
{}

Rectangle::~Rectangle()
{}

int main(){
    Rectangle *pRect=new Rectangle;
    const Rectangle *pConstRect=new Rectangle;
    Rectangle * const pConstPtr=new Rectangle;

    cout<<"pRect width: "<< pRect->GetWidth() <<" feet\n";
 //   cout<<"pConstRect width"<< pConstRect->GetWidth()<<" feet\n";
    cout<<"pRectPtr width"<< pConstPtr->GetWidth()<<" feet\n";

    pRect->SetWidth(10);
//    pConstRect->SetWidth(10);
    pConstPtr->SetWidth(10);

    cout<<"pRect width: "<< pRect->GetWidth() <<" feet\n";
 //   cout<<"pConstRect width"<< pConstRect->GetWidth()<<" feet\n";
    cout<<"pRectPtr width"<< pConstPtr->GetWidth()<<" feet\n";

    
    return 0;
}
