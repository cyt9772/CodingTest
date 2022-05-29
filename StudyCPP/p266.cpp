//swap with reference

#include <iostream>
using namespace std;

void swap(int &x, int &y);

int main(){
    int x=5, y=10;

    cout<<"Main before swap, x: "<<x<<" y: "<<y<<endl;
    swap(x,y);
    cout<<"Main after swap, x: "<<x<<" y: "<<y<<endl;

    return 0;
}

void swap(int &rx, int &ry){
    cout<<"Swap before swap, x: "<<rx<<" y: "<<ry<<endl;
    int temp=rx;
    rx=ry;
    ry=temp;
    cout<<"Main after swap, x: "<<rx<<" y: "<<ry<<endl;
}
