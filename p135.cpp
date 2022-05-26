#include <iostream>
using namespace std;

int fib(int n);

int main(){
    int n, ans;
    cout <<"Enter number to find.";
    cin>>n;
    cout<<endl;

    ans=fib(n);

    cout<<"Answer: "<<ans<<endl;
    return 0;
}

int fib(int n){
    if(n<3){
        return 1;
    }else{
        return fib(n-2)+fib(n-1);
    }


}

