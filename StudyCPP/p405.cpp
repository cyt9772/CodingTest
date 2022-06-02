#include <iostream>
#include "Mammal.hpp"
using namespace std;

enum BOOL {FALSE, TRUE};

class Dog : public Mammal
{
public:
    Dog(){cout<<"Dog constructor...\n";}
    ~Dog(){cout<<"Dog destructor...\n";}
    Dog(const Dog &rhs);
    void Speak() const { cout<<"Woof!\n";}
    virtual Mammal* Clone(){return new Dog(*this);}
};
Dog::Dog(const Dog &rhs):
Mammal(rhs)
{
    cout<<"Dog copy constructor...\n";
}

class Cat : public Mammal
{
public:
    Cat(){cout<<"Cat constructor...\n";}
    ~Cat(){cout<<"Cat destructor...\n";}
    Cat(const Cat &rhs);
    void Speak() const { cout<<"Meow!\n";}
    virtual Mammal* Clone(){return new Cat(*this);}
};
Cat::Cat(const Cat &rhs):
Mammal(rhs)
{
    cout<<"Cat copy constructor...\n";
}

enum ANIMALS {MAMMAL, DOG, CAT};
const int NumAnimalTuypes=3;

int main()
{
    Mammal *theArray[NumAnimalTuypes];
    Mammal *ptr;
    int choice;

    for(int i=0;i<NumAnimalTuypes;i++){
        cout<<"(1)Dog (2)Cat (3)Mammal: ";
        cin>>choice;
        switch(choice){
            case DOG: ptr=new Dog;
                break;
            case CAT: ptr=new Cat;
                break;
            default: ptr=new Mammal;
                break;
        }
        theArray[i]=ptr;
    }

    Mammal *OtherArray[NumAnimalTuypes];
    for(int i=0;i<NumAnimalTuypes;i++){
        theArray[i]->Speak();
        OtherArray[i]=theArray[i]->Clone();
    }
    for(int i=0;i<NumAnimalTuypes;i++){
        OtherArray[i]->Speak();
    }
    return 0;
}
