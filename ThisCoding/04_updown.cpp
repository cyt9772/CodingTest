#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/* 상하좌우
    LRUD 동작 이후 최종 좌표
5
R R R U D D
*/

int main(){
    int N;
    char c;
    int posx=1, posy=1;
    int dx=0, dy=0;
    int nx,ny;
    string plans;

    nx=posx+dx;
    ny=posy+dy;

    cin>>N;

    cin.ignore();
    getline(cin,plans);

    for(int i=0;i<plans.size();i++){
        c=plans[i];
        dx=0;
        dy=0;
        switch(c){
            case 'L':
                dy=-1;
                break;
            case 'R':
                dy=1;
                break;
            case 'U':
                dx=-1;
                break;
            case 'D':
                dx=1;
                break;
            default:
                break;
        }
        nx=posx+dx;
        ny=posy+dy;

        if((nx>0 && nx<=N)&&(ny>0 && ny<=N)){
            posx=nx;
            posy=ny;
        }
    }
    cout<<posx<<" "<<posy<<endl;


}