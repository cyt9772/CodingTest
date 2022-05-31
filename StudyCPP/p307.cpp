//증가 연산자 추가하기

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
private:
    USHORT itsVal;
};

Counter::Counter():
itsVal(0)
{};

int main(){
    Counter i;
    cout<<"The Value of i is: "<<i.GetItsVal()<<endl;
    i.Increment();
    cout<<"The Value of i is: "<<i.GetItsVal()<<endl;
    return 0;
}