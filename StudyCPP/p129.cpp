#include <iostream>
using namespace std;

int Double(int);
long Double(long);
float Double(float);
double Double(double);

int main(){
    int myInt=6500;
    long myLong = 65000;
    float myFloat = 6.5;
    double myDouble = 6.5e20;

    int doubledInt;
    long doubledLong;
    float doubledFloat;
    double doubledDouble;

    cout<<"myInt: " <<myInt<<endl;
    cout<<"myLong: " <<myLong<<endl;
    cout<<"myFloat: " <<myFloat<<endl;
    cout<<"myDouble: " <<myDouble<<endl;

    doubledInt=Double(myInt);
    doubledLong=Double(myLong);
    doubledFloat=Double(myFloat);
    doubledDouble=Double(myDouble);

    cout<<"DoubledInt: " <<doubledInt<<endl;
    cout<<"DoubledLong: " <<doubledLong<<endl;
    cout<<"DoubledFloat: " <<doubledFloat<<endl;
    cout<<"DoubledDouble: " <<doubledDouble<<endl;

    return 0;
}

int Double(int original){
    cout<<"In Double(int)"<<endl;
    return 2*original;
}
long Double(long original){
    cout<<"In Double(long)"<<endl;
    return 2*original;
}

float Double(float original){
    cout<<"In Double(float)"<<endl;
    return 2*original;
}
double Double(double original){
    cout<<"In Double(double)"<<endl;
    return 2*original;
}

