
using namespace std;
typedef unsigned short USHORT;

class CAT
{
public:
    CAT();
    int GetAge() const {return *itsAge;}
    int GetWeight() const {return *itsWeight;}
    void SetAge(int age) { *itsAge=age;}
    CAT operator=(const CAT&);
private:
    int* itsAge;
    int* itsWeight;
};

CAT::CAT(){
    itsAge=new int;
    itsWeight= new int;
    *itsAge=5;
    *itsWeight=9;
}

CAT CAT::operator=(const CAT& rhs){
    if(this==&rhs){
        return *this;
    }
    delete itsAge;
    delete itsWeight;

    itsAge=new int;
    itsWeight=new int;

    *itsAge=rhs.GetAge();
    *itsWeight=rhs.GetWeight();

    return *this;
}