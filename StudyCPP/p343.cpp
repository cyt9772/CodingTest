//객체의 배열만들기

#include <iostream>
#include "CAT.hpp"
using namespace std;


int main(){
    CAT Litter[5];
    for(int i =0;i<5;i++){
        Litter[i].SetAge(2*i+1);
    }

    for(int i=0;i<5;i++){
        cout<<"cat #"<<i+1<<" : ";
        cout<<Litter[i].GetAge()<<endl;
    }
    return 0;
}