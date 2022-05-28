#include <iostream>
using namespace std;


int main(){
    int intOne;
    int &rSomeRef=intOne;

    intOne=5;
    cout<<"intOne: "<<intOne <<endl;
    cout<<"rSomeRef: "<<rSomeRef<<endl;
    cout<<"&intOne: "<<&intOne <<endl;
    cout<<"&rSomeRef: "<<&rSomeRef<<endl;

    int intTwo=8;
    rSomeRef=intTwo;

    cout<<"intOne:\t"<<intOne<<endl;
    cout<<"intTwo:\t"<<intTwo<<endl;
    cout<<"rSomeRef:\t"<<rSomeRef<<endl;
    cout<<"&intOne:\t"<<&intOne<<endl;
    cout<<"&intTwo:\t"<<&intTwo<<endl;
    cout<<"&rSomeRef:\t"<<&rSomeRef<<endl;

    return 0;
}
