//참조자에 의한 객체 전달

#include <iostream>
using namespace std;
typedef unsigned short USHORT;

class SimpleCat
{
public:
    SimpleCat();
    SimpleCat(SimpleCat&);
    ~SimpleCat();
};

SimpleCat::SimpleCat(){
    cout<<"Simple Cat Constructor...\n";
}

SimpleCat::SimpleCat(SimpleCat&){
    cout<<"Simple Cat copy Constructor...\n";
}

SimpleCat::~SimpleCat(){
    cout<<"SimpleCat destructor...\n";
}

SimpleCat FunctionOne(SimpleCat theCat);
SimpleCat *FunctionTwo(SimpleCat *theCat);

int main(){
    cout<<"Making a cat...\n";
    SimpleCat Frisky;
    cout<<"Calling Function One...\n";
    FunctionOne(Frisky);
    cout<<"Calling Function two...\n";
    FunctionTwo(&Frisky);

    return 0;
}

SimpleCat FunctionOne(SimpleCat theCat){
    cout<<"Function One. Returning ...\n";
    return theCat;
}

SimpleCat *FunctionTwo(SimpleCat *theCat){
    cout<<"Function two. Returning ...\n";
    return theCat;
}
