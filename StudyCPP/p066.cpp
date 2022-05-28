#include <iostream>
using namespace std;

typedef unsigned short int USHORT;

int main(){

    USHORT smallNumber=65535;
    cout<<"small number: "<<smallNumber<<endl;
    smallNumber++;
    cout<<"small number: "<<smallNumber<<endl;
    smallNumber++;
    cout<<"small number: "<<smallNumber<<endl;
    return 0;
}