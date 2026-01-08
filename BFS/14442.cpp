/*
문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 
당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 
최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000), K(1 ≤ K ≤ 10)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

*/

#include <iostream> 
#include <queue>
#include <memory.h>
using namespace std;

static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int visited[1001][1001][11];
static int A[1001][1001];
static int n,m,k;
typedef struct{
    int x,y, state;
}info;
void BFS(int i, int j);
void BFS(int i, int j){
    queue<info> myqueue; //큐생성
    memset(visited,-1,sizeof(visited)); //모두 안가본것으로 초기화
    //시작점 방문처리 및 큐 삽입
    visited[i][j][0]=1; //시작점도 count
    myqueue.push({i,j,0});
    while (!myqueue.empty())
    {
        //현재 노드 저장 및 팝하기
        info cur;
        cur.x=myqueue.front().x;
        cur.y=myqueue.front().y;
        cur.state=myqueue.front().state;
        myqueue.pop();

        for(int q=0;q<4;q++){
            int x=cur.x+dx[q];
            int y=cur.y+dy[q];
            if(x>=1&&y>=1&&x<=n&&y<=m){
                if(A[x][y]==1&&cur.state<k&&visited[x][y][cur.state+1]==-1)//이동할 칸이 벽이고, 가본적이 없다면, 벽을 부숴야하는데 k개 이하로 부쉈어야하고, cur.state가 1이상일수도 있는일임.
                {
                    visited[x][y][cur.state+1]=visited[cur.x][cur.y][cur.state]+1;
                    myqueue.push({x,y,cur.state+1});
                }
                if(A[x][y]==0&&visited[x][y][cur.state]==-1)//이동할 칸이 길이고, 가본적이 없다면
                {
                    visited[x][y][cur.state]=visited[cur.x][cur.y][cur.state]+1;
                    myqueue.push({x,y,cur.state});
                }
            }
        }
    }
    
}

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            A[i][j]=s[j-1]-'0';
        }
    }
      

    BFS(1,1);

    int ans=-1;

    
    for(int i=0;i<=k;i++){
       if(visited[n][m][i] != -1){
        if(ans == -1 || ans > visited[n][m][i])
            ans = visited[n][m][i];
    }
}
cout << ans;


 
}