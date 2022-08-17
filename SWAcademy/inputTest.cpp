#include <iostream>
#include <stdio.h>
using namespace std;

//input example
/*
10
5 10
0000000000
0123456789
0000000000
0000000000
0000000000
*/

int main(){
    //file에서 읽기
 //   freopen("sample_input.txt","r", stdin);

/*
    int t,r,c;
    char arr[100][100];
    scanf("%d",&t);
    scanf("%d %d", &r, &c);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf(" %c", &arr[i][j]);
    
    printf("%d\n%d\n%d\n", t,r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%c", arr[i][j]);
        }
        cout<<endl;
    }
*/

/* 다른 입력 방법
    for(int i=0;i<r;i++)
        scanf("%s",arr[i]);
*/
//====================================================
// C++
    int t,r,c;
    char arr[100][100];

    cin>>t>>r>>c;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    //다른 입력
    //for(int i=0;i<r;i++)
    //  cin>>arr[i]

    cout<<t<<" "<<r<<" "<<c<<" "<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    return 0;
}