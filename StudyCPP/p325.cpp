//USHORT를 Counter 객체에 대입
//원래는 compile이 되지 말아야하는데 g++에서는 compile됨


#include <iostream>
#include "Counter.hpp"

using namespace std;
typedef unsigned short USHORT;
enum BOOL {FALSE, TRUE};


int main(){
    USHORT theShort=5;
    Counter theCtr=theShort;
    cout<<"theCtr: "<<theCtr.GetItsVal()<<endl;

    return 0;
}