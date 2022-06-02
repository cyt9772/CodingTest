//동물 Dog class

#include <iostream>
#include "Mammal.hpp"
enum BREED {YORKIE, CARIAN, DANDIE, SHETLAND, DOBEMAN, LAB};

using namespace std;


class Dog: public Mammal
{
public:
    Dog();
    Dog(int age);
    Dog(int age, int weight);
    Dog(int age, BREED breed);
    Dog(int age, int weight, BREED breed);
    ~Dog();
    BREED GetBreed() const { return itsBreed;}
    void SetBreed(BREED breed){itsBreed=breed;}

    void WagTail(){cout<<"Tail wagging...\n";}
    void BegForFood() {cout<<"Begging for food...\n";}
    void Speak() const {cout<<"Woof!!\n";}

    void Move() const {cout<<"Dog move 5 steps.\n";}
    void Move(int distance){
        cout<<"In dog move...\n";
        Mammal::Move(distance);
    }

protected:
    BREED itsBreed;
};

Dog::Dog():
    itsBreed(YORKIE)
    {
        cout<<"Dog constructor...\n";
    }
Dog::Dog(int age):
    Mammal(age),
    itsBreed(YORKIE)
    {
        cout<<"Dog(int) constructor...\n";
    }

Dog::Dog(int age, int weight):
    Mammal(age),
    itsBreed(YORKIE)
    {
        itsWeight=weight;
        cout<<"Dog(int, int) constructor...\n";
    }

Dog::Dog(int age, int weight, BREED breed):
    Mammal(age),
    itsBreed(breed)
    {
        itsWeight=weight;
        cout<<"Dog(int, int, BREED) constructor...\n";
    }

Dog::Dog(int age, BREED breed):
    Mammal(age),
    itsBreed(breed)
    {
        cout<<"Dog(int, BREED) constructor...\n";
    }

Dog::~Dog()
{
    cout<<"Dog destructor...\n";
}