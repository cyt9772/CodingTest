#include <iostream>
using namespace std;

int main(){

    int theVar=5;
    int *pPoint=&theVar;
    int *pP;
    pP=&theVar;

    cout<<"*pPoint: "<<*pPoint<<endl;
    cout<<"*pP: "<<*pP<<endl;
}