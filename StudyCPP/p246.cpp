#include <iostream>
using namespace std;
typedef unsigned short int USHORT;

int main(){
    USHORT *pInt=new USHORT;
    *pInt=10;

    cout<<"*pInt= "<<*pInt<<endl;
    delete pInt;
    pInt=0;

    long *plong=new long;
    *plong = 90000;
    cout<<"*plong = "<< *plong<<endl;
    *pInt=20;

    cout<<"*pInt = " <<*pInt<<endl;
    cout<<"*plong = "<<*plong<<endl;

    return 0;
}