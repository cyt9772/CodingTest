#include <iostream>
#include "Dog.hpp"

using namespace std;

int main()
{
    Dog fido;
    Dog rover(5);
    Dog buster(6,8);
    Dog yorkie(3,YORKIE);
    Dog dobbie(4,20,DOBEMAN);

    fido.Speak();
    rover.WagTail();
    cout<<"Yorkie is " << yorkie.GetAge() <<" years old\n";
    cout<<"Dobbie weights "<<dobbie.GetWeight()<<" pounds\n";
    return 0;
}