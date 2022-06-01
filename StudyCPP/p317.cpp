//add 함수

#include <iostream>
using namespace std;
typedef unsigned short USHORT;
enum BOOL {FALSE, TRUE};

class Counter
{
public:
    Counter();
    Counter(USHORT initialValue);
    ~Counter(){}
    USHORT GetItsVal() const {return itsVal;}
    void SetItsVal(USHORT x){itsVal=x;}
    void Increment(){++itsVal;}
    const Counter& operator++(); //전치연산
    const Counter& operator++(int); //후치연산
    Counter Add(const Counter&);
private:
    USHORT itsVal;
};

Counter::Counter():
itsVal(0)
{};

Counter::Counter(USHORT initalValue):
itsVal(initalValue)
{};

Counter Counter::Add(const Counter& rhs){
    return Counter(itsVal+rhs.GetItsVal());
}

const Counter& Counter::operator++(){
    ++itsVal;
    return *this;
}
const Counter& Counter::operator++(int x){
    itsVal++;
    return *this;
}


int main(){
    Counter varOne(2), varTwo(4), varThree;
    varThree=varOne.Add(varTwo);
    cout<<"VarOne: "<<varOne.GetItsVal()<<endl;
    cout<<"VarTwo: "<<varTwo.GetItsVal()<<endl;
    cout<<"VarThree: "<<varThree.GetItsVal()<<endl;

    return 0;
}