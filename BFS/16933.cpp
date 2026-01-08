/*
이전 상태가 낮, 다음 이동할 곳이 벽 =>  이동가능
이전 상태가 밤, 다음 이동할 곳이 벽 => 이동 불가능. 그 칸에 한번더 머물고 count++
문제
N×M의 행렬로 표현되는 맵이 있다. 
맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 
당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 
최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다. 
이동하지 않고 같은 칸에 머물러있는 경우도 가능하다. 
이 경우도 방문한 칸의 개수가 하나 늘어나는 것으로 생각해야 한다.

이번 문제에서는 낮과 밤이 번갈아가면서 등장한다. 가장 처음에 이동할 때는 낮이고, 한 번 이동할 때마다 낮과 밤이 바뀌게 된다. 이동하지 않고 같은 칸에 머무르는 경우에도 낮과 밤이 바뀌게 된다.

만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다. 단, 벽은 낮에만 부술 수 있다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000), K(1 ≤ K ≤ 10)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
*/

#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
int n,m,k;
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int A[1001][1001];
static int visited[1001][1001][11][2];
typedef struct{
    int x,y,state,dn; //day==0,night=1;
}info;
int BFS(){
    queue <info> my;
    memset(visited,-1,sizeof(visited));
    visited[1][1][0][0]=1;
    my.push({1,1,0,0});

    while(!my.empty()){
        info cur=my.front();
        my.pop();
        if(cur.x==n&&cur.y==m){
            return visited[cur.x][cur.y][cur.state][cur.dn];
        }
        int next = 1 - cur.dn;
        for(int q=0;q<4;q++){
            int x=cur.x+dx[q];
            int y=cur.y+dy[q];
            if(x>=1&&y>=1&&x<=n&&y<=m){
                if(A[x][y]==0){
                    if(visited[x][y][cur.state][next]==-1)//이동할 칸이 길이고, 간적이 없을때, 이전상태는 벽일 수도 있고 길일 수도 있고, 낮일수도 있고 밤일 수도 있다.
                {
                    visited[x][y][cur.state][next]=visited[cur.x][cur.y][cur.state][cur.dn]+1;
                    my.push({x,y,cur.state,next});
                }
            }
                if(A[x][y]==1){
                    if(cur.state<k&&cur.dn==0)//이동할 칸이 벽이고, 그럼 부숴야 하는데,k개 이하로 부술 수 있고 이전상태는 벽일수도있고 길일 수도 있음 낮일때만 부술 수 있고, 아니라면 하루 더 머물러야 하고, 그 칸을 간적이 없어야함.
                {
                    if(visited[x][y][cur.state+1][next]==-1){
                        visited[x][y][cur.state+1][next]=visited[cur.x][cur.y][cur.state][cur.dn]+1;
        
                    my.push({x,y,cur.state+1,next});
                    }
                    
                  
                }
            }
        }
    }return -1;
}}

int main(){
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            A[i][j]=s[j-1]-'0';
        }
    }

    cout<<BFS();


}
