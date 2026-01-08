#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
static int dx[]={0,1,0,-1}; static int dy[]={1,0,-1,0};
static int visited[1001][1001][2];
static int A[1001][1001];
int n,m;
typedef struct{
    int x,y,state;
}info;
void BFS(int q, int w, int e, int r);
void BFS(int q, int w, int e, int r){
    queue<info> myqueue;//큐만들기
    memset(visited,-1,sizeof(visited)); //거리 배열 방문안함(-1) 초기화하기
    visited[q][w][0]=0;
    myqueue.push({q,w,0});//시작점 넣기, 시작점에서는 벽을 안부쉈으니까 0

    while(!myqueue.empty()){
        info cur;
        cur.x=myqueue.front().x;
        cur.y=myqueue.front().y;
        cur.state=myqueue.front().state;
        myqueue.pop(); //현재 노드 정보들 저장후 팝하기
        //if(cur.x==e-1&&cur.y==r-1) return;//도착점에 도달하면 리턴하기
        for(int k=0;k<4;k++){
            int x=cur.x+dx[k]; int y= cur.y+dy[k];
            if(x>=0&&y>=0&&x<n&&y<m){
                if(A[x][y]==1&&cur.state==0&&visited[x][y][1]==-1)//이동할 칸이 벽이고 그 칸에 가본적이 없다면 그리고 부수고 갈거니까 state는 1ㄹ로 써줌.
                {
                    visited[x][y][1]=visited[cur.x][cur.y][0]+1;
                    myqueue.push({x,y,1});
                }
                if(A[x][y]==0&&visited[x][y][cur.state]==-1)//이동할 칸이 길(0)이고, 그 칸에 가본적이 없다면/ 이동할 칸이 길이라는 말은 그전은 벽이여서 부쉈을 가능성도 있다는 말이다.
                {
                    visited[x][y][cur.state]=visited[cur.x][cur.y][cur.state]+1;
                    myqueue.push({x,y,cur.state}); 
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    int q,w,e,r;
    cin >> q >> w;
cin >> e >> r;

q--; w--;
e--; r--;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }

    BFS(q,w,e,r);

    int answer1=visited[e][r][0],answer2=visited[e][r][1];
    int ans = -1;

if(answer1 != -1 && answer2 != -1)
    ans = min(answer1, answer2);
else if(answer1 != -1)
    ans = answer1;
else if(answer2 != -1)
    ans = answer2;

cout << ans;


}