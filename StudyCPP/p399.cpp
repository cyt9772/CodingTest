#include <iostream>
//#include "Dog.hpp"
#include "CAT.hpp"

using namespace std;

class Horse : public Mammal
{
public:
    void Speak() const {cout<<"Winnie!\n";}
};

class Pig : public Mammal
{
public:
    void Speak() const {cout<<"Oink!\n";}
};

class Dog : public Mammal
{
public:
    void Speak() const {cout<<"Woof!\n";}
};

int main()
{
    Mammal* theArray[5];
    Mammal* ptr;
    int choice;

    for(int i=0;i<5;i++){
        cout<<"(1)dog (2)cat (3)horse (4)pig:";
        cin>>choice;
        switch(choice){
            case 1: ptr = new Dog;
                break;
            case 2: ptr = new CAT;
                break;
            case 3: ptr = new Horse;
                break;
            case 4: ptr = new Pig;
                break;
            default: ptr = new Mammal;
                break;
        }
        theArray[i]=ptr;
    }

    for(int i=0;i<5;i++){
        theArray[i]->Speak();
    }
    
    return 0;
}