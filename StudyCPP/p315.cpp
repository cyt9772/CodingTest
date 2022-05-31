//전치연산자와 후치연산자

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
    const Counter& operator++(); //전치연산
    const Counter& operator++(int); //후치연산
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
const Counter& Counter::operator++(int x){
    itsVal++;
    return *this;
}


int main(){
    Counter i;
    cout<<"The Value of i is: "<<i.GetItsVal()<<endl;
    ++i;
    cout<<"The Value of i is: "<<i.GetItsVal()<<endl;
    i++;
    cout<<"The Value of i is: "<<i.GetItsVal()<<endl;
    
    Counter a=++i;
    cout<<"The value of a: "<<a.GetItsVal();
    cout<<" and i: "<<i.GetItsVal()<<endl;

    a=i++;
    cout<<"The value of a: "<<a.GetItsVal();
    cout<<" and i: "<<i.GetItsVal()<<endl;

    return 0;
}