#include<iostream>
using namespace std;

enum BOOL {FALSE, TRUE};
typedef unsigned short int USHORT;

USHORT menu();
void DoTaskOne();
void DoTaskMany(USHORT);

int main(){
    BOOL exit=FALSE;
    for(;;){
        USHORT choice=menu();
        switch(choice){
            case (1):
                DoTaskOne();
                break;
            case (2):
                DoTaskMany(2);
                break;
            case (3):
                DoTaskMany(3);
                break;
            case (4):
                continue;
                break;
            case (5):
                exit=TRUE;
                break;
            default:
                cout<<"Please select again!!"<<endl;
                break;
        }
        if(exit)
            break;
    }
    return 0;
}

USHORT menu(){
    USHORT choice;

    cout<<"*** Menu ***"<<endl;
    cout<<"(1) Choice One"<<endl;
    cout<<"(2) Choice tow"<<endl;
    cout<<"(3) Choice three"<<endl;
    cout<<"(4) Redisplay menu"<<endl;
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