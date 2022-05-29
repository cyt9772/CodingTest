#include <iostream>
using namespace std;
typedef unsigned short USHORT;


class SimpleCat
{
public:
    SimpleCat(int age, int weight);
    ~SimpleCat(){}
    int GetAge(){return itsAge;}
    int GetWeight(){return itsWeight;}

private:
    int itsAge;
    int itsWeight;
};

SimpleCat::SimpleCat(int age, int weight): itsAge(age), itsWeight(weight){}
SimpleCat &TheFunction();

int main(){
    SimpleCat &rCat=TheFunction();
    int age=rCat.GetAge();
    cout<<"rCat is "<<age<<" years old.\n";
    cout<<"&rCat: "<<&rCat<<endl;
    SimpleCat *pCat=&rCat;
    delete pCat;
    //rCat이 가리키는 값은?
    return 0;
}

SimpleCat &TheFunction(){
    SimpleCat *pFrisky=new SimpleCat(5,9);
    cout<<"pFrisky: " <<pFrisky<<endl;
    return *pFrisky;
}