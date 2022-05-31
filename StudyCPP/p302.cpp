#include <iostream>
using namespace std;
typedef unsigned short USHORT;
enum BOOL {FALSE, TRUE};

class CAT{
public:
    CAT();
    CAT(const CAT &);
    ~CAT();

    int GetAge() const {return *itsAge;}
    int GetWeight() const {return *itsWeight;}
    void SetAge(int age) {*itsAge=age;}
private:
    int *itsAge;
    int *itsWeight;
};

CAT::CAT(){
    itsAge=new int;
    itsWeight=new int;
    *itsAge=5;
    *itsWeight=9;
}

CAT::CAT(const CAT &rhs){
    itsAge=new int;
    itsWeight=new int;
    *itsAge=rhs.GetAge();
    *itsWeight=rhs.GetWeight();
}

CAT::~CAT(){
    delete itsAge;
    itsAge=0;
    delete itsWeight;
    itsWeight=0;
}

int main(){
    CAT Frisky;
    cout<<"Frisky's age: "<<Frisky.GetAge()<<endl;
    cout<<"Setting Frisky's age to 6"<<endl;
    Frisky.SetAge(6);

    cout<<"Creating boots from Frisky...\n";
    CAT boots(Frisky);
    cout<<"Frisky's age: "<<Frisky.GetAge()<<endl;
    cout<<"Boot's age: "<<boots.GetAge()<<endl;

    cout<<"Setting Frisky's age to 7...\n";
    Frisky.SetAge(7);
    cout<<"Frisky's age: "<<Frisky.GetAge()<<endl;
    cout<<"Boot's age: "<<boots.GetAge()<<endl;

    return 0;
}