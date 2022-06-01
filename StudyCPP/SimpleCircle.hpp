#include <iostream>
using namespace std;

class SimpleCircle
{
public:
    SimpleCircle();
    SimpleCircle(int val);
    SimpleCircle(const SimpleCircle&);
    ~SimpleCircle(){}
    int GetRadius() const { return itsRadius;}
    void SetRadius(int val){itsRadius=val;}
    const SimpleCircle operator++();
    const SimpleCircle operator++(int);
    SimpleCircle& operator=(const SimpleCircle&);
private:
    int itsRadius;

};

SimpleCircle::SimpleCircle():
itsRadius(5)
{}

SimpleCircle::SimpleCircle(int val):
itsRadius(val)
{}

SimpleCircle::SimpleCircle(const SimpleCircle& rhs){
    itsRadius=rhs.GetRadius();
}

SimpleCircle const SimpleCircle::operator++(){
    ++itsRadius;
    return *this;
}

SimpleCircle const SimpleCircle::operator++(int val){
    itsRadius++;
    return *this;
}

SimpleCircle& SimpleCircle::operator=(const SimpleCircle &rhs){
    if(this==&rhs){
        return *this;
    }
    itsRadius=rhs.GetRadius();
}
