//다차원 배열만들기

#include <iostream>

using namespace std;


int main(){
    int someArray[5][2]={{0,0},{1,2},{2,4},{3,6},{4,8}};
    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            cout<<"SomeArray["<<i<<"]["<<j<<"]: ";
            cout<<someArray[i][j]<<endl;
        }
    }
    return 0;
}