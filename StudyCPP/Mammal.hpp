//동물 base class

#include <iostream>
using namespace std;

class Mammal
{
public:
    Mammal();
    Mammal(int age);
    Mammal(const Mammal &rhs);
    ~Mammal();

    int GetAge() const { return itsAge;}
    void SetAge(int age){itsAge=age;}
    int GetWeight() const {return itsWeight;}
    void SetWeight(int weight){itsWeight=weight;}

//    void Speak() const {cout<<"Mammal sound!!!\n";}
    void Sleep()const {cout<<"I'm sleeping now\n";}
    void Move() const {cout<<"Mammal move one step.\n";}
    void Move(int distance) const{
        cout<<"Mammal Move ";
        cout<<distance<<" steps.\n";
    }
    virtual void Speak() const {cout<<"Mammal Speak!\n";}
    virtual Mammal* Clone(){return new Mammal(*this);}
    

protected:
    int itsAge;
    int itsWeight;
};

Mammal::Mammal():
    itsAge(1),
    itsWeight(5)
{
    cout<<"Mammal constructor...\n";
}

Mammal::Mammal(int age):
    itsAge(age),
    itsWeight(5)
    {
        cout<<"Mammal(int) constructor...\n";
    }
Mammal::Mammal(const Mammal &rhs):
    itsAge(rhs.GetAge()),
    itsWeight(5)
    {
        cout<<"Mammal(&rhs) constructor...\n";
    }

Mammal::~Mammal()
{
    cout<<"Mammal destructor...\n";
}