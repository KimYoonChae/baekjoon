#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

static int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
static int N,M,K; //행열의 크기와 벽을 부수기 가능한 개수
static int visited[1001][1001][11][2];
static int A[1001][1001];
typedef struct{
    int x,y,state,dn;
}info;
int BFS(){
    queue<info>q;
    memset(visited,-1,sizeof(visited));
    //시작점 세팅
    visited[1][1][0][0]=1;
    q.push({1,1,0,0});

    while(!q.empty()){
        info cur=q.front();
        q.pop();

        //도착점 만났을때
        if(cur.x==N&&cur.y==M) return visited[cur.x][cur.y][cur.state][cur.dn];
        
        for(int k=0;k<4;k++){
            int x=cur.x+dx[k];
            int y=cur.y+dy[k];

            if(x>=1&&y>=1&&x<=N&&y<=M){
                int next=1-cur.dn;
                //앞이 길일때
                if(A[x][y]==0 && visited[x][y][cur.state][next]==-1){
                    visited[x][y][cur.state][next]=visited[cur.x][cur.y][cur.state][cur.dn]+1;
                    q.push({x,y,cur.state,next});
                }
                //앞이 벽일때
                else if(A[x][y]==1 && cur.state<K){
                    if(cur.dn==0 && visited[x][y][cur.state+1][next]==-1) //현상태가 낮이고 방문한적 없다면
                    {visited[x][y][cur.state+1][next]=visited[cur.x][cur.y][cur.state][cur.dn]+1;
                    q.push({x,y,cur.state+1,next});}
                    if(cur.dn==1&&visited[x][y][cur.state][next]==-1){ //현상태가 밤이라서 담 상태가 방문한적 없더라도, 머물러야 하는 상황이라면
                    visited[cur.x][cur.y][cur.state][next]=visited[cur.x][cur.y][cur.state][cur.dn]+1;
                    q.push({cur.x,cur.y,cur.state,next});
                    }
                }
            
                }
            }   
        }return -1;
    }
    


int main(){
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        string s;
        cin>>s;
        for(int j=1;j<=M;j++){
            A[i][j]=s[j-1]-'0';
        }
    }

    cout<<BFS();

}