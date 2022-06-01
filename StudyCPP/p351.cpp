//new를 사용하여 배열만들기

#include <iostream>
#include "CAT.hpp"
using namespace std;


int main(){
    CAT *Family=new CAT[500];
    CAT *pCat;
    for(int i=0;i<500;i++){
        pCat= new CAT;
        pCat->SetAge(2*i+1);
        Family[i]=*pCat;
    }

    for(int i=0;i<500;i++){
        cout<<"Cat #"<<i+1<<": ";
        cout<<Family[i].GetAge()<<endl;
    }

    delete [] Family;

    return 0;
}