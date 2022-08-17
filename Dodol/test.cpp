#include <stdio.h>

int main(){
 int arr[]={3,1,4,1,5,9,2,6,5,3};
 int len=sizeof(arr)/sizeof(int);

 for(int i=0;i<len;i++)
 {
     printf("%d ", arr[i]);
 }

}