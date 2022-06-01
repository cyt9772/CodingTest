//문자열 클래스 사용하기

#include <iostream>
#include <string.h>
#include "string.hpp"
using namespace std;


int main(){
    String s1("inital test");
    cout<<"S1: \t"<<s1.GetString()<<endl;

    
    s1="hello world";
    cout<<"S1: \t"<<s1.GetString()<<endl;

    char tempTwo[20];
    strcpy(tempTwo, ";nice to be here!");

    s1 +=tempTwo;
    cout<<"TempTwo:\t"<<tempTwo<<endl;
    cout<<"S1:\t"<<s1.GetString()<<endl;

    cout<<"s1[4]:\t"<<s1[4]<<endl;
    s1[4]='x';
    cout<<"s1:\t"<<s1.GetString()<<endl;

    cout<<"s1[999]:\t"<<s1[999]<<endl;

    String s2("Another string");
    String s3;
    s3=s1+s2;
    cout<<"s3:\t"<<s3.GetString()<<endl;

    String s4;
    s4="Why does this work?";
    cout<<"s4:\t"<<s4.GetString()<<endl;

    return 0;

}