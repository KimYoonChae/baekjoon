#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
/*
입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. 
M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 
단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 
즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 
하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 
정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

1=불
0=지나갈 수 있는 공간
-1:벽

토마토가 하나 이상 있는 경우만 입력으로 주어진다.

출력
여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 
만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
*/

static int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
static int ripedist[1001][1001],grid[1001][1001];

int main(){
    int M,N;
    cin>>N>>M; //열, 행 입력받기

    int ripecount=0;

    memset(ripedist,-1,sizeof(ripedist));
    queue<pair<int,int>>rq;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];

            if(grid[i][j]==1){
                ripedist[i][j]=1;
                rq.push({i,j});
                ripecount++;
            }

        }
    }

    //원래부터 과일이 다 익어있다면 
    int flag1=1;
       for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==0){
               flag1=0;
            }

        }
    }
    if(flag1==1) {cout<<0;return 0;} 




   int result=-1;
    while(!rq.empty()){
        pair<int,int>curripe=rq.front();
        rq.pop();
       // cout<<ripedist[curripe.first][curripe.second];
        result=ripedist[curripe.first][curripe.second]-1;    
        
        for(int i=0;i<4;i++){
            int rx=curripe.first+dx[i];
            int ry=curripe.second+dy[i];

            //좌표 유효성 체크
            if(rx<0||ry<0||rx>=M||ry>=N) continue;
            //다음칸이 과일이 없다면(벽이라면)
            if(grid[rx][ry]==-1) continue;
            //다음칸이 이미 방문했던 칸이라면
            if(ripedist[rx][ry]!=-1) continue;

        
            ripedist[rx][ry]=ripedist[curripe.first][curripe.second]+1;
            rq.push({rx,ry});
            
        }
    
    }

    
    int flag=1;
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==0&&ripedist[i][j]==-1) flag=0; //BFS를 돌고도 익지 못한 과일이라면
        }
    }
    if(flag==0) cout<<-1;
    else
   cout<<result;
 
    
    
}