#include <iostream>
using namespace std;

int Add(int x, int y){
    cout<<"In Add(), received "<<x<<" and "<<y <<endl;
    return x+y;
}

int main(){
    cout << "I'm in main()!\n";
    int a,b,c;
    cout << "Enter two numbers: ";
    cin>>a;
    cin>>b;

    cout << "\n Calling Add()"<<endl;
    c=Add(a,b);
    cout <<"back in main()."<<endl;
    cout << " c was set to "<<c<<endl;
    cout<<" Exiting..."<<endl;
    return 0;
}