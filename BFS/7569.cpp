#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

/*
입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H가 주어진다.
 M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다. 
 둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다. 
 각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다. 
 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 
 이러한 N개의 줄이 H번 반복하여 주어진다.

토마토가 하나 이상 있는 경우만 입력으로 주어진다.

출력
여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다. 
만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.


*/

static int dx[]={0,1,0,-1,0,0},dy[]={1,0,-1,0,0,0},dh[]={0,0,0,0,1,-1}; //우,하,좌,상,위,아래
static int ripedist[101][101][101], grid[101][101][101];

typedef struct{
    int x,y,box;
} info;

int main(){
    int M,N,H; //가로, 세로, 상자의 수
    queue<info> q;
    memset(ripedist,-1,sizeof(ripedist));
    
    cin>>M>>N>>H;
    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>grid[i][j][k];
                if(grid[i][j][k]==1){
                    q.push({i,j,k});
                    ripedist[i][j][k]=0;
                }
            }
        }
    }

    /*이미 다 익어있는 상태라면*/
    int flag=1;
    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j][k]==0) flag=0; 
            }
        }
    }

    if(flag==1){
        cout<<0;
        return 0;
    }
    
    /*BFS시작*/
    int result=0;
    while(!q.empty()){
        info cur=q.front();
        q.pop();
        result=ripedist[cur.x][cur.y][cur.box];
        for(int i=0;i<6;i++){
            int x=cur.x+dx[i];
            int y=cur.y+dy[i];
            int h=cur.box+dh[i];

            //유효성 검사
            if(x<0||y<0||x>=N||y>=M||h<0||h>=H) continue;
            //과일이 없다면
            if(grid[x][y][h]==-1) continue;
            //이미 익어있다면
            if(ripedist[x][y][h]!=-1) continue;

            ripedist[x][y][h]=ripedist[cur.x][cur.y][cur.box]+1;
            q.push({x,y,h});
        }
    }

    int flag2=1;

     for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
             // cout<<ripedist[i][j][k];
        
                    if(ripedist[i][j][k]==-1&&grid[i][j][k]==0) flag2=0;
                
            }
      
           // cout<<"\n";
        }
    }



if(flag2==0) cout<<-1;
else cout<<result;

//cout<<result;

}