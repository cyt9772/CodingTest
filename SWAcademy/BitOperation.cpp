#include <iostream>
#include <stdio.h>
using namespace std;

/*
1. 1<<n
 - 2^n의 값을 가짐
 - 원소가 n개일 경우의 모든 부분집합의 수를 읨
 - power set(모든 부분 집합)

 2.i&(1<<j)
  - 계산 결과는 i의 j번째 bit가 1인지 아닌지를 의미
*/


//숫자를 bit로 표현
void printBits(char n){
    for(int i=7;i>=0;i--){
        if(n&(1<<i)) cout<<"1";
        else cout<<"0";
    }
}

//Bit를 이용한 부분 집합 생성 코드
void printSubSets(char arr[], int n){
    for(int i=0;i<(1<<n);i++){  //전체 부분집합의 개수, 1<<n
        cout<<"{";
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                cout<<arr[j];
            }
        }
        cout<<"}"<<endl;
    }
}

int main(){
    char i;
    for(i=-5;i<6;i++){
        printf("%3d = ", i);
        printBits(i);
        cout<<endl;
    }

    char data[]={'A','B','C','D'};
    printSubSets(data,4);
    return 0;
}