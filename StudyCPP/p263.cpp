//swap no pointer or reference

#include <iostream>
using namespace std;

void swap(int x, int y);

int main(){
    int x=5, y=10;

    cout<<"Main before swap, x: "<<x<<" y: "<<y<<endl;
    swap(x,y);
    cout<<"Main after swap, x: "<<x<<" y: "<<y<<endl;

    return 0;
}

void swap(int x, int y){
    cout<<"Swap before swap, x: "<<x<<" y: "<<y<<endl;
    int temp=x;
    x=y;
    y=temp;
    cout<<"Main after swap, x: "<<x<<" y: "<<y<<endl;
}
