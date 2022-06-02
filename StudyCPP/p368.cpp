//linked list 코딩

#include <iostream>
#include "node.hpp"
using namespace std;


int main(){
    Node *pNode=0;
    CAT *pCat=new CAT(0);
    int age;

    Node *pHead=new Node(pCat);

    while(1)
    {
        cout<<"New Cat's age?(0 to quit): ";
        cin>>age;
        if(!age)
            break;
        pCat=new CAT(age);
        pNode = new Node(pCat);
        pHead->Insert(pNode);
    }

    pHead->Display();
    delete pHead;
    cout<<"Exiting...";
    
    return 0;

}