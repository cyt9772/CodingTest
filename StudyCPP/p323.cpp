//add 함수 => +연산자

#include <iostream>
#include "CAT.hpp"

using namespace std;
typedef unsigned short USHORT;
enum BOOL {FALSE, TRUE};


int main(){
    CAT frisky;
    cout<<"frisky's age: "<<frisky.GetAge()<<endl;
    cout<<"Setting frisky to 6...\n";
    frisky.SetAge(6);

    CAT whiskers;
    cout<<"whiskers' age: "<<whiskers.GetAge()<<endl;
    cout<<"copying frisky to whiskers...\n";
    whiskers=frisky;
    cout<<"whiskers' age: "<<whiskers.GetAge()<<endl;
    return 0;
}