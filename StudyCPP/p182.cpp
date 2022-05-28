#include<iostream>
using namespace std;

int main(){
    int counter=0;
loop: counter++;
    cout<<"Counter: "<<counter<<endl;
    
    if(counter<5)
    goto loop;

    cout<<"Complete. Counter"<<endl;
}