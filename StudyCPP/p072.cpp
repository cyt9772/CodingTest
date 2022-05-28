#include <iostream>
using namespace std;


int main(){
    enum Days {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
    Days dayOff;
    int x;

    cout<<"what day would you like off (0-6)?";
    cin>>x;
    dayOff=Days(x);

    if(dayOff==Saturday || dayOff==Sunday)
        cout<<"\nYou're already off on weekends!"<<endl;
    else
        cout<<"\nOkay, I'll put in the vacation day."<<endl;

    return 0;
}