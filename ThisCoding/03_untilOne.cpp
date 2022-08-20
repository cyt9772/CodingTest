#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 1이 될때까지
    1. N에서 1을 뺀다
    2. N을 K로 나눈다

    25 5
*/

int main(){
    int N,K, cnt=0;
    cin>>N>>K;

    //N을 넘지않는 최대 K의 배수 찾기
    while(true){
        int diff=0;
        diff=N-(N/K)*K;
        N= N-diff;
        cnt +=diff;
        N=N/K;
        cnt ++;
        if(N<K){
            if(N==1) break;
            else cnt +=(N-1);
            break;
        }
    }
    cout<<cnt<<endl;


}