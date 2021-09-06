#include <iostream>

#define MAX 55

using namespace std;

int map[MAX][MAX];

int dx[]={-1, 0, 1, 0};   //순서는 북, 동, 남, 서
int dy[]={0, 1, 0, -1};

int main(){
    int n,m; //map size
    cin>>n>>m;
    int x, y, dir; //start point & direction
    cin>>x>>y>>dir;


    //input map information
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }

    int cnt=0;

    //map info=> 0: not visited, 1: wall, 2: visited.
    while(true){
        //visit current position
        if(map[x][y]==0){
            map[x][y]=2; //mark as visited
        }
        if(map[x+1][y]!=0 && map[x-1][y]!=0 && map[x][y+1]!=0 && map[x][y-1]!=0){ //visited or wall
            if(map[x-dx[dir]][y-dy[dir]]==1){ //impossible backward
                break;
            }
            else{ //backward
                x -= dx[dir];
                y -= dy[dir];
            }
        }else{
            dir=(dir+3)%4; //원래는  dir-1 이지만 - 값때문에 항상 방향값에 +4(왼쪽으로 돌때마다 -1)
            if(map[x+dx[dir]][y+dy[dir]]==0){
                x +=dx[dir];
                y +=dy[dir];
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==2){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}