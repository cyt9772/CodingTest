#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 숫자 카드 게임
각 열에서 가장 숫자가 높은 카드를 뽑은 후, 뽑힌 카드 중 가장 숫자가 작은 카드 선택
3 3
3 1 2
4 1 4
2 2 2

2 4
7 3 1 8
3 3 3 4
*/

int main(){
    int N,M;
    int max_value=0;

    cin>>N>>M;
    for(int i=0;i<N;i++){
        int min_value=10001;
        for(int j=0;j<M;j++){
            int x;
            cin>>x;
            if(x<min_value){
                min_value=x;
            }
        }
        if(min_value>max_value){
            max_value=min_value;
        }
    }
    cout<<max_value<<endl;
}