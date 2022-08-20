#include <iostream>
#include <stdio.h>
using namespace std;


//선택정렬
void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int tmp=arr[min];
        arr[min]=arr[i];
        arr[i]=tmp;
    }
}


int main(){

    return 0;
}