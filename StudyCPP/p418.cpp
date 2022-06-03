#include <iostream>
using namespace std;
enum BOOL {FALSE, TRUE};
enum TYPE {HORSE, PEGASUS};

class Horse
{
public:
    void Gallop(){ cout<<"Galloping...\n";}
//    virtual void Fly() {cout<<"Horse can't Fly.\n";}
private:
    int itsAge;
};

class Pegasus: public Horse
{
public:
    virtual void Fly(){cout<<"I can fly! I can fly. I can fly!\n";}
};

const int NumberHorses=5;

int main()
{
    Horse* Ranch[NumberHorses];
    Horse* pHorse;

    int choice;
    for(int i=0;i<NumberHorses;i++){
        cout<<"(1) Horse (2)Pegasus: ";
        cin>>choice;
        if(choice==2)
            pHorse=new Pegasus;
        else
            pHorse=new Horse;
        Ranch[i] = pHorse;
    }
    cout<<endl;
    for(int i=0;i<NumberHorses;i++){
        Pegasus *pPeg=dynamic_cast<Pegasus*>(Ranch[i]);
        if(pPeg)
            pPeg->Fly();
        else
            cout<<"Just a Horse";
            
        delete Ranch[i];
    }
    return 0;
}
