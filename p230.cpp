#include <iostream>
using namespace std;
typedef unsigned short int USHORT;

int main(){
    USHORT myAge;
    USHORT *pAge;
    myAge=5;
    cout<<"myAge: " <<myAge<<endl;

    pAge=&myAge;
    cout<<"*pAge: "<<*pAge<<endl;

    *pAge=7;
    cout<<"set *pAge=7"<<endl;
    cout<<"*pAge: " <<*pAge<<endl;
    cout<<"myAge: "<<myAge<<endl;

    myAge=9;
    cout<<"set myAge=9"<<endl;
    cout<<"*pAge: " <<*pAge<<endl;
    cout<<"myAge: "<<myAge<<endl;

    return 0;
}