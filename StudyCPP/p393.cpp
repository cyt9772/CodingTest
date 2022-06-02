#include <iostream>
#include "Dog.hpp"

using namespace std;

int main()
{
    Mammal bigAnimal;
    Dog fido;
    
    bigAnimal.Move();
    bigAnimal.Move(5);
    fido.Move();
    fido.Move(10);    
    return 0;
}