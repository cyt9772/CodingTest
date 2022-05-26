#include <iostream>
using namespace std;

class Cat
{
public:
    int itsAge;
    int itsWeight;
};

int main(){
    Cat frisky;
    frisky.itsAge=5;
    cout<<"Frisky is a cat who is ";
    cout<<frisky.itsAge<< " years old."<<endl;
    return 0;
}



