#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
static int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
static int R,C;//행,열
static int water[51][51],hedgehog[51][51];
static char grid[51][51];

int main(){
    cin>>R>>C;
    memset(water,-1,sizeof(water));
    memset(hedgehog,-1,sizeof(hedgehog));
    queue<pair<int,int>>wq,hq;
    int sx=-1,sy=-1; //고슴도치 위치
    int bx=-1,by=-1;//비버의 위치


    for(int i=0;i<R;i++){
        string s;
        cin>>s;
        for(int j=0;j<C;j++){
            grid[i][j]=s[j];
            if(grid[i][j]=='*'){
                water[i][j]=0;
                wq.push({i,j});
            }
            if(grid[i][j]=='S'){
                sx=i;sy=j;
            }
            if(grid[i][j]=='D'){
                bx=i;by=j;
            }
        }
    }
    hq.push({sx,sy});
    hedgehog[sx][sy]=0;

    while(!wq.empty()){
        pair<int,int> curwater=wq.front();
        wq.pop();
        for(int i=0;i<4;i++){
            int wx=curwater.first+dx[i];
            int wy=curwater.second+dy[i];
            //좌표 경계값 검사
            if(wx<0||wy<0||wx>=R||wy>=C) continue;
            //비버의 숲인 경우
            if(grid[wx][wy]=='D') continue;
            //이미 물이 차있는 경우
            if(water[wx][wy]!=-1) continue;
            //돌(벽)이 있어서 이동 못하는경우
            if(grid[wx][wy]=='X') continue;

            water[wx][wy]=water[curwater.first][curwater.second]+1;
            wq.push({wx,wy});
        }
    }
    while(!hq.empty()){
        pair<int,int> curhedge=hq.front();
        int curtime=hedgehog[curhedge.first][curhedge.second];
        hq.pop();
        if((curhedge.first==bx&&curhedge.second-1==by)||(curhedge.first==bx&&curhedge.second+1==by)
            ||(curhedge.second==by&&curhedge.first-1==bx)||(curhedge.second==by&&curhedge.first+1==bx)){
                cout<<curtime+1;
                return 0;
            }
        for(int i=0;i<4;i++){
            int hx=curhedge.first+dx[i];
            int hy=curhedge.second+dy[i];
            //좌표 경계값 검사
            if(hx<0||hy<0||hx>=R||hy>=C) continue;
            //이미 고슴도치가 왔다간 경우
            if(hedgehog[hx][hy]!=-1) continue;
            //돌(벽)이 있어서 이동 못하는 경우
            if(grid[hx][hy]=='X') continue;
            //이미 물이 차서 못가는 경우
            int nexttime=curtime+1;
            if(water[hx][hy]!=-1&&water[hx][hy]<=nexttime) continue;
            hedgehog[hx][hy]=hedgehog[curhedge.first][curhedge.second]+1;
            hq.push({hx,hy});
        }
    }
    cout<<"KAKTUS";
    return 0;
}