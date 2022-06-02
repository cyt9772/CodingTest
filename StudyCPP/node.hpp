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
    
}

