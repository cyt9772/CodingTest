#include <iostream>
#include "CAT.hpp"
using namespace std;

class Node
{
public:
    Node(CAT*);
    ~Node();
    void SetNext(Node *node){itsNext=node;}
    Node* GetNext() const {return itsNext;}
    CAT* GetCat() const {return itsCat;}
    void Insert(Node *);
    void Display();
private:
    CAT* itsCat;
    Node* itsNext;
};

Node::Node(CAT *pCat):
    itsCat(pCat),
    itsNext(0)
{}

Node::~Node(){
    cout<<"Deleting Node...\n";
    delete itsCat;
    itsCat=0;
    delete itsNext;
    itsNext=0;
}

void Node::Insert(Node* newNode){
    if(!itsNext) //null이면
        itsNext=newNode;
    else{ //null이 아니면
        int NextCatsAge=itsNext->GetCat()->GetAge();
        int NewAge=newNode->GetCat()->GetAge();
        int ThisNodeAge=itsCat->GetAge();

        if(NewAge>ThisNodeAge && NewAge<NextCatsAge){
            newNode->SetNext(itsNext);
            itsNext=newNode;
        }else
            itsNext->Insert(newNode);
    }    
}

void Node::Display(){
    if(itsCat->GetAge()>0){
        cout<<"My cat is ";
        cout<<itsCat->GetAge()<<" years old\n";
    }
    if(itsNext)
        itsNext->Display();
}