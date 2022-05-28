#include <iostream>
using namespace std;
typedef unsigned short int USHORT;

int main(){
    USHORT myAge=5, yourAge=10;
    USHORT *pAge=&myAge;
    
    cout<<"myAge:\t"<<myAge<<"\tyourAge:\t"<<yourAge<<endl;
    cout<<"&myAge:\t"<<&myAge<<"\t&yourAge:\t"<<&yourAge<<endl;

    cout<<"pAge:\t"<<pAge<<endl;
    cout<<"*pAge:\t"<<*pAge<<endl;

    pAge=&yourAge;

    cout<<"myAge:\t"<<myAge<<"\tyourAge:\t"<<yourAge<<endl;
    cout<<"&myAge:\t"<<&myAge<<"\t&yourAge:\t"<<&yourAge<<endl;

    cout<<"pAge:\t"<<pAge<<endl;
    cout<<"*pAge:\t"<<*pAge<<endl;

    cout<<"&pAge:\t"<<&pAge<<endl;
    
    return 0;
}