//참조자에 의한 객체 전달
//상수형포인터 전달.

#include <iostream>
using namespace std;
typedef unsigned short USHORT;

class SimpleCat
{
public:
    SimpleCat();
    SimpleCat(SimpleCat&);
    ~SimpleCat();

    int GetAge() const {return itsAge;}
    void SetAge(int age){itsAge=age;}

private:
    int itsAge;
};

SimpleCat::SimpleCat(){
    cout<<"Simple Cat Constructor...\n";
    itsAge=1;
}

SimpleCat::SimpleCat(SimpleCat&){
    cout<<"Simple Cat copy Constructor...\n";
}

SimpleCat::~SimpleCat(){
    cout<<"SimpleCat destructor...\n";
}

const SimpleCat & FunctionTwo(const SimpleCat &theCat);

int main(){
    cout<<"Making a cat...\n";
    SimpleCat Frisky;
    cout<<"Frisky is  ";
    cout<<Frisky.GetAge();
    cout<<" years old\n";
    int age=5;
    Frisky.SetAge(age);

    cout<<"Frisky is  ";
    cout<<Frisky.GetAge();
    cout<<" years old\n";

    cout<<"Calling Function two...\n";
    FunctionTwo(Frisky);
    cout<<"Frisky is  ";
    cout<<Frisky.GetAge();
    cout<<" years old\n";

    return 0;
}


const SimpleCat & FunctionTwo(const SimpleCat &theCat){
    cout<<"Function two. Returning ...\n";
    cout<<"Frisk is now "<<theCat.GetAge();
    cout<<" years old\n";
    
    return theCat;
}
