#include <iostream>
using namespace std;

int& RefReturn1(int &ref){
    ref++;
    return ref;
}

int RefReturn2(int &ref){
    ref++;
    return ref;
}

int main(){
    int num1_1=10;
    int& num1_2=RefReturn1(num1_1); //참조형 반환, call by reference

    num1_1++;
    num1_2++;

    cout<<"num1: "<<num1_1<<endl;
    cout<<"num2: "<<num1_2<<endl;

    int num2_1=10;
    int num2_2=RefReturn1(num2_1);//상수 ,call by value

    num2_1++;
    num2_2+=10;

    cout<<"num1: "<<num2_1<<endl;
    cout<<"num2: "<<num2_2<<endl;

    int num3_1=10;
    int num3_2=RefReturn2(num3_1); //return이 상수는 상수에 대입

    num3_1++;
    num3_2+=10;

    cout<<"num1: "<<num3_1<<endl;
    cout<<"num2: "<<num3_2<<endl;

}