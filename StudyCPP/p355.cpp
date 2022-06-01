//배열채우기

#include <iostream>
//#include "CAT.hpp"
using namespace std;


int main(){
    char buf[80];
    cout<<"Enter the string: ";
    cin.get(buf, 79);
    cout<<"Here's buffer: "<<buf<<endl;
    return 0;
}