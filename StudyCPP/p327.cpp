//USHORT를 Counter 객체에 대입
//원래는 compile이 되지 말아야하는데 g++에서는 compile됨
//(생성자에 이미 포함)


#include <iostream>
#include "Counter.hpp"

using namespace std;
typedef unsigned short USHORT;
enum BOOL {FALSE, TRUE};


int main(){
    Counter ctr(5);
    USHORT theShort=ctr;
    cout<<"theShort: "<<theShort<<endl;
    return 0;
}