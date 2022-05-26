#include<iostream>
using namespace std;

int main(){
    unsigned short shortVar=5;
    unsigned long longVar=65535;
    long sVar=-65535;

    cout<<"shorVar:\t"<<shortVar;
    cout<<" Address of shortVar:\t";
    cout<<&shortVar<<endl;

    cout<<"longVar:\t"<<longVar;
    cout<<" Address of longVar:\t";
    cout<<&longVar<<endl;

    cout<<"sVar:\t"<<sVar;
    cout<<" Address of sVar:\t";
    cout<<&sVar<<endl;

    return 0;

}