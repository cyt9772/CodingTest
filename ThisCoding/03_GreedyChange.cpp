#include <iostream>
//당장 좋은 것만 선택하는 그리디

using namespace std;

int main(){
    int N; //거스름돈
    int coins[]={500,100,50,10};
    int numCoins=0;

    cout<<"program start"<<endl;

    //거스름돈 입력
    cin>>N;
    for(int coin: coins){
        numCoins +=(N/coin);
        N=N%coin;
    } 
    cout<<numCoins<<endl;

}