#include <iostream>
#include <vector>
#include <algorithm>

//큰 수의 법칙
/*
5 8 3
2 4 5 4 6
*/

using namespace std;

int main(){
    int N,M,K;  //N: 배열의 크기, M: 더하는 회수, K: 최대 반복 사용 회수
    cin>>N>>M>>K;

    vector<int> data;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        data.push_back(temp);
    }

    sort(data.rbegin(), data.rend()); //내림차순 정렬
    int first=data[0];
    int second=data[1];

    int blockSum=first*K+second;
    //반복회수의 몫과 나머지 구하기
    int iterNum=M/(K+1);
    int rem=M%(K+1);

    int total=iterNum*blockSum+first*rem;
    cout<<total<<endl;
    

}