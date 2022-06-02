#include <iostream>
#include "Dog.hpp"

using namespace std;

int main()
{
    Mammal *pDog = new Dog;
    pDog->Move();
    pDog->Speak();
    
    return 0;
}