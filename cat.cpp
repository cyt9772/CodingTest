#include <iostream>
#include "cat.hpp"

using namespace std;


Cat::Cat(int initalAge){
    itsAge=initalAge;
}
Cat::~Cat(){

}

unsigned int Cat::getAge(){
    return itsAge;
}
unsigned int Cat::getWeight(){
    return itsWeight;
}

void Cat::setAge(unsigned int age){
    itsAge=age;
}
void Cat::setWeight(unsigned int weight){
    itsWeight=weight;
}
void Cat::meow(){
    cout<<"Meow..."<<endl;
}

int main(){
    Cat frisky(5);
    frisky.meow();
    cout<<"Frisky is a cat who is "<< frisky.getAge()<<" years old."<<endl;
    frisky.meow();
    frisky.setAge(7);
    cout<<"Now Frisky is ";
    cout<< frisky.getAge() << " years old."<<endl;
    return 0;
}



