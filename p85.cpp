#include <iostream>
using namespace std;


int main(){
    int myAge=39;
    int yourAge=39;

    cout<<"myage: "<<myAge<<endl;
    cout<<"Your age: "<<yourAge<<endl;

    myAge++;
    ++yourAge;

    cout<<"myage +1: "<<myAge<<endl;
    cout<<"Your age +1: "<<yourAge<<endl;

    cout<<"myage+ another+1: "<<myAge++<<endl;
    cout<<"Your age another +1: "<<++yourAge<<endl;

    cout<<"Last myage: "<<myAge<<endl;
    cout<<"Last Your age: "<<yourAge<<endl;    
    
    return 0;
}