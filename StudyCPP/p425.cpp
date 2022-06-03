//다중 생성자.

#include <iostream>
using namespace std;

typedef int HANDS;
enum COLOR {Red, Green, Blue, Yellow, White, Black, Brown};
enum BOOL {FALSE, TRUE};
enum TYPE {HORSE, PEGASUS};

class Horse
{
public:
    Horse(COLOR color, HANDS height);
    virtual ~Horse(){cout<<"Horse Destructor...\n";}
    virtual void Whinny() const { cout<<"Whinny...\n";}
    virtual HANDS GetHeight() const {return itsHeight;}
    virtual COLOR GetColor() const { return itsColor;}
private:
    HANDS itsHeight;
    COLOR itsColor;
};

Horse::Horse(COLOR color, HANDS height):
    itsColor(color), itsHeight(height)
    {
            cout<<"Horse Constructor\n";
    }

class Bird
{
public:
    Bird(COLOR color, BOOL migrates);
    virtual ~Bird(){cout<<"Bird Destructor...\n";}
    virtual void Chirp() const { cout<<"Chirp...\n";}
    virtual void Fly() const{
        cout<<"I can Fly! I can Fly\n";
    }
    virtual COLOR GetColor() const { return itsColor;}
    virtual BOOL GetMigration() const { return itsMigration;}
private:
    COLOR itsColor;
    BOOL itsMigration;
};
Bird::Bird(COLOR color, BOOL migrates):
    itsColor(color), itsMigration(migrates)
    {
            cout<<"Bird Constructor\n";
    }

class Pegasus: public Horse, public Bird
{
public:
    void Chirp() const { Whinny();}
    Pegasus(COLOR, HANDS,BOOL,long);
    ~Pegasus() { cout<<"Pegasus Destructor...\n";}
    virtual long GetNumBelievers() const{
        return itsNumberBelievers;
    }
private:
    long itsNumberBelievers;
};

Pegasus::Pegasus(COLOR aColor, HANDS height, BOOL migrates, long NumBelieve):
    Horse(aColor, height),
    Bird(aColor, migrates),
    itsNumberBelievers(NumBelieve)
    {
        cout<<"Pegasus Constructo...]\n";
    }

int main()
{
    Pegasus *pPeg=new Pegasus(Red, 5, TRUE, 10);
    pPeg->Fly();
    pPeg->Whinny();
    cout<<"\nYour Pegasus is "<<pPeg->GetHeight();
    cout<<" hands tall and ";
    if(pPeg->GetMigration())
        cout<<"does migrate.";
    else
        cout<<"does migrate.";
    cout<<"\nA total of "<<pPeg->GetNumBelievers();
    cout<<" people belive it exists.\n";
    delete pPeg;
    return 0;
}