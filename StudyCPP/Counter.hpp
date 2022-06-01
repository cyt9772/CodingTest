
using namespace std;
typedef unsigned short USHORT;

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
    Counter operator+(const Counter&);
    operator unsigned short();
private:
    USHORT itsVal;
};

Counter::Counter():
itsVal(0)
{};

Counter::Counter(USHORT initalValue):
itsVal(initalValue)
{};

Counter::operator unsigned short(){
    return ((USHORT)itsVal);
}
Counter Counter::operator+(const Counter& rhs){
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
