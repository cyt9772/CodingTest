#include<iostream>
using namespace std;

enum BOOL {FALSE, TRUE};
enum CHOICE {DrawRect=1, GetArea, GetPerim, ChangeDimensions, Quit};

typedef unsigned short int USHORT;
typedef unsigned long int ULONG;

class Rectangle{
public:
    Rectangle(USHORT width, USHORT height);
    ~Rectangle();
    USHORT GetHeight() const {return itsHeight;}
    USHORT GetWidth() const {return itsWidth;}
    ULONG GetArea() const { return itsHeight*itsWidth;}
    ULONG GetPerim() const {return 2*itsHeight+2*itsWidth;}
    void SetSize(USHORT newWidth, USHORT newHeight);

    void DrawShape() const;
private:
    USHORT itsWidth;
    USHORT itsHeight;
};

Rectangle::Rectangle(USHORT width, USHORT height){
    itsWidth=width;
    itsHeight=height;
}
Rectangle::~Rectangle() {}

void Rectangle::SetSize(USHORT newWidth, USHORT newHeight){
    itsWidth=newWidth;
    itsHeight=newHeight;
}


USHORT DoMenu();
void DoDrawRect(Rectangle theRect){
    USHORT height=theRect.GetHeight();
    USHORT width=theRect.GetWidth();

    for(USHORT i=0;i<height;i++){
        for(USHORT j=0;j<width;j++){
            cout<<"*";
        }
        cout<<endl;
    }
};
void DoGetArea(Rectangle theRect){
    cout<<"Area: "<<theRect.GetArea()<<endl;
};
void DoGetPerim(Rectangle theRect){
    cout<<"Perimeter: "<<theRect.GetPerim()<<endl;
};


int main(){
    Rectangle theRect(30,5);
    USHORT choice = DrawRect;
    USHORT fQuit = FALSE;

    while(!fQuit){
        choice=DoMenu();
        if(choice < DrawRect||choice >Quit){
            cout<<"\nInvalid Choice, please try again"<<endl;
            continue;
        }
        switch(choice){
            case DrawRect:
                DoDrawRect(theRect);
                break;
            case GetArea:
                DoGetArea(theRect);
                break;
            case GetPerim:
                DoGetPerim(theRect);
                break;
            case ChangeDimensions:
                USHORT newLength, newWidth;
                cout<<"\nNew width: ";
                cin>>newWidth;
                cout<<"\nNew Height: ";
                cin>>newLength;
                theRect.SetSize(newWidth, newLength);
                DoDrawRect(theRect);
                break;
            case Quit:
                fQuit=TRUE;
                cout<<"Exiting...."<<endl;
                break;
            default:
                cout<<"Error in choice!"<<endl;
                fQuit=TRUE;
                break;
        }
    }    
    return 0;
}

USHORT DoMenu(){
    USHORT choice;

    cout<<"*** Menu ***"<<endl;
    cout<<"(1) Draw Rectangle"<<endl;
    cout<<"(2) Area"<<endl;
    cout<<"(3) Perimeter"<<endl;
    cout<<"(4) Resize"<<endl;
    cout<<"(5) Quit"<<endl;
    cout<<":";
    cin>>choice;
    return choice;
}

void DoTaskOne(){
    cout<<"Task One!!"<<endl;
}

void DoTaskMany(USHORT which){
    if (which ==2){
        cout<<"Task Two!"<<endl;
    }else{
        cout<<"Task Three!"<<endl;
    }
}