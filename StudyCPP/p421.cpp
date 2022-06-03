#include <iostream>
using namespace std;
enum BOOL {FALSE, TRUE};
enum TYPE {HORSE, PEGASUS};

class Horse
{
public:
    Horse(){cout<<"Horse constructor...\n";}
    virtual ~Horse(){cout<<"Horse Destructor...\n";}
    virtual void Whinny() const { cout<<"Whinny...\n";}
private:
    int itsAge;
};

class Bird
{
public:
    Bird(){cout<<"Bird constructor...\n";}
    virtual ~Bird(){cout<<"Bird Destructor...\n";}
    virtual void Chirp() const { cout<<"Chirp...\n";}
    virtual void Fly() {
        cout<<"I can Fly! I can Fly\n";
    }
private:
    int itsWeight;
};

class Pegasus: public Horse, public Bird
{
public:
    void Chirp() const { Whinny();}
    Pegasus() {cout<<"Pegasus Constructor...\n";}
    ~Pegasus() { cout<<"Pegasus Destructor...\n";}
};

const int MagicNumber=2;

int main()
{
    Horse* Ranch[MagicNumber];
    Bird* Aviary[MagicNumber];
    Horse* pHorse;
    Bird* pBird;

    int choice;
    for(int i=0;i<MagicNumber;i++){
        cout<<"(1) Horse (2)Pegasus: ";
        cin>>choice;
        if(choice==2)
            pHorse=new Pegasus;
        else
            pHorse=new Horse;
        Ranch[i] = pHorse;
    }
    cout<<endl;
    
    for(int i=0;i<MagicNumber;i++){
        cout<<"(1) Bird (2)Pegasus: ";
        cin>>choice;
        if(choice==2)
            pBird=new Pegasus;
        else
            pBird=new Bird;
        Aviary[i] = pBird;
    }

    cout<<endl;

    for(int i=0;i<MagicNumber;i++){
        cout<<"\nRanch["<<i<<"]:";
        Ranch[i]->Whinny();
        delete Ranch[i];
    }
    for(int i=0;i<MagicNumber;i++){
        cout<<"\nAviary["<<i<<"]:";
        Aviary[i]->Chirp();
        Aviary[i]->Fly();
        delete Aviary[i];
    }
    return 0;
}
