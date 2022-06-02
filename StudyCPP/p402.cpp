#include <iostream>
#include "Mammal.hpp"
using namespace std;

enum BOOL {FALSE, TRUE};

class Dog : public Mammal
{
public:
    void Speak() const { cout<<"Woof!\n";}
};

class Cat : public Mammal
{
public:
    void Speak() const { cout<<"Meow!\n";}
};

void ValueFunction(Mammal);
void PtrFunction(Mammal*);
void RefFunction(Mammal&);

int main()
{
    Mammal* ptr=0;
    int choice;

    while(1){
        BOOL fQuit=FALSE;
        cout<<"(1)Dog (2)Cat (0)Quit: ";
        cin>>choice;

        switch(choice){
            case 0:
                fQuit=TRUE;
                break;
            case 1:
                ptr=new Dog;
                break;
            case 2:
                ptr=new Cat;
                break;
            default:
                ptr=new Mammal;
                break;
        }
        if(fQuit)
            break;
        PtrFunction(ptr);
        RefFunction(*ptr);
        ValueFunction(*ptr);
    }    
    return 0;
}

void ValueFunction(Mammal mammalValue){
    mammalValue.Speak();
}

void PtrFunction(Mammal *pMammal){
    pMammal->Speak();
}

void RefFunction(Mammal &rMammal){
    rMammal.Speak();
}