#include <iostream>
using namespace std;

int main(){
    long sentinelOne[3];
    long targetArray[25];
    long sentinelTwo[3];

    for(int i=0;i<3;i++){
        sentinelOne[i]=sentinelTwo[i]=0;
    }
    for(int i=0;i<25;i++)
        targetArray[i]=0;

    cout<<"Test 1: \n";
    cout<<"targetArray[0]: "<<targetArray[0]<<endl;
    cout<<"targetArray[24]: "<<targetArray[24]<<endl;

    for(int i=0;i<3;i++){
        cout<<"sentinelOne["<<i<<"]:";
        cout<<sentinelOne[i]<<endl;
        cout<<"sentinelTwo["<<i<<"]:";
        cout<<sentinelTwo[i]<<endl;
    }

    cout<<"Assigning...\n";
    for(int i=0;i<=25;i++){
        targetArray[i]=20;
    }

    cout<<"Test 2: \n";
    cout<<"targetArray[0]: "<<targetArray[0]<<endl;
    cout<<"targetArray[24]: "<<targetArray[24]<<endl;
    cout<<"targetArray[25]: "<<targetArray[25]<<endl;

    for(int i=0;i<3;i++){
       cout<<"sentinelOne["<<i<<"]:";
       cout<<sentinelOne[i]<<endl;
       cout<<"sentinelTwo["<<i<<"]:";
       cout<<sentinelTwo[i]<<endl;
    }


    return 0;
}