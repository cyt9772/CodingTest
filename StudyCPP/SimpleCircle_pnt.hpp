#include <iostream>
using namespace std;

class SimpleCircle
{
public:
    SimpleCircle();
    SimpleCircle(int val);
    ~SimpleCircle(){}
    int GetRadius() const { return *itsRadius;}
    void SetRadius(int val){*itsRadius=val;}
    const SimpleCircle operator++();
    const SimpleCircle operator++(int);
private:
    int *itsRadius;

};

SimpleCircle::SimpleCircle()
{
    itsRadius=new int(5);
}

SimpleCircle::SimpleCircle(int val)
{
    itsRadius=new int(val);
}

SimpleCircle const SimpleCircle::operator++(){
    ++(*itsRadius);
    return *this;
}

SimpleCircle const SimpleCircle::operator++(int val){
    (*itsRadius)++;
    return *this;
}