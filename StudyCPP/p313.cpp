//this 포인터 반환하기

#include <iostream>
using namespace std;
typedef unsigned short USHORT;
enum BOOL {FALSE, TRUE};

class Counter
{
public:
    Counter();
    ~Counter(){}
    USHORT GetItsVal() const {return itsVal;}
    void SetItsVal(USHORT x){itsVal=x;}
    void Increment(){++itsVal;}
    const Counter& operator++();
private:
    USHORT itsVal;
};

Counter::Counter():
itsVal(0)
{};

const Counter& Counter::operator++(){
    ++itsVal;
    return *this;
}

int main(){
    Counter i;
    cout<<"The Value of i is: "<<i.GetItsVal()<<endl;
    i.Increment();
    cout<<"The Value of i is: "<<i.GetItsVal()<<endl;
    ++i;
    cout<<"The Value of i is: "<<i.GetItsVal()<<endl;
    Counter a=++i;
    cout<<"The value of a: "<<a.GetItsVal();
    cout<<" and i: "<<i.GetItsVal()<<endl;


    return 0;
}