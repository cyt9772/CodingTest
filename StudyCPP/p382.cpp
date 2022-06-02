#include <iostream>
#include "Dog.hpp"

using namespace std;

int main()
{
    Dog fido;
    fido.Speak();
    fido.WagTail();

    cout<<"Fido is "<<fido.GetAge() <<" years old\n";
    return 0;
}