//선형탐색 예제

#include <iostream>
using  namespace std;

int SequentialSearch(int arr[], int n, int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}

int main(){
    int data[7]={2,4,8,1,5,7,9};

    cout<<"9: "<<SequentialSearch(data, 7,9)<<endl;
    cout<<"3: "<<SequentialSearch(data, 7,3)<<endl;
    cout<<"2: "<<SequentialSearch(data, 7,2)<<endl;

    return 0;
}