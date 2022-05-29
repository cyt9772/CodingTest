//swap with pointer

#include <iostream>
using namespace std;

void swap(int *x, int *y);

int main(){
    int x=5, y=10;

    cout<<"Main before swap, x: "<<x<<" y: "<<y<<endl;
    swap(&x,&y);
    cout<<"Main after swap, x: "<<x<<" y: "<<y<<endl;

    return 0;
}

void swap(int *px, int *py){
    cout<<"Swap before swap, x: "<<*px<<" y: "<<*py<<endl;
    int temp=*px;
    *px=*py;
    *py=temp;
    cout<<"Main after swap, x: "<<*px<<" y: "<<*py<<endl;
}
