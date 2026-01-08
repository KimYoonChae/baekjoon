#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int visited[1001][1001][2];
static int A[1001][1001];
int n,m;
typedef struct{
    int x; int y; int state;
}info;
void BFS(int i, int j);
void BFS(int i, int j){
    queue<info> myqueue;
    memset(visited,-1,sizeof(visited));//모두 방문하지 않음(-1)로 초기화함
    visited[i][j][0]=1; //시작점에서는 벽을 안부쉈으니까 state는 0이고, 시작점도 count하니까 방문처리함
    myqueue.push({i,j,0});//큐에 푸쉬

    while(!myqueue.empty()){
        info cur; cur.x=myqueue.front().x;cur.y=myqueue.front().y; cur.state=myqueue.front().state; //현재 상태저장
        myqueue.pop(); //큐 팝
        for(int k=0;k<4;k++){
            int x1=cur.x+dx[k]; int y1=cur.y+dy[k];
            if(x1>=1&&y1>=1&&x1<=n&&y1<=m){
                if(A[x1][y1]==0&&visited[x1][y1][cur.state]==-1){ //이동할 자리가 뱍이 아니고(0), 방문한적이 없다면
                    visited[x1][y1][cur.state]=visited[cur.x][ cur.y][cur.state]+1; //거리배열에 새롭게 이동한 노드의 depth를 현재 노드의 depth+1로 업데이트
                    myqueue.push({x1,y1,cur.state}); //큐에 삽입
                }
                if(A[x1][y1]==1&&cur.state==0&&visited[x1][y1][0]==-1){ // 이동할 자리가 벽이고(1), 그렇다면 현재는 0이겠지. 그리고 이동할 자리를 방문한 적이 없다면(-1)
                    visited[x1][y1][1]=visited[cur.x][cur.y][0]+1; //새롭게 이동할 노드의 depth를 현재 노드의 depth+1로 업데이트
                     myqueue.push({x1,y1,1}); //큐에 삽입
                }
            }
        }
    }
}

int main(){
   

   ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string row; cin >> row;
        for (int j = 1; j <= m; j++) {
            A[i][j] = row[j - 1] - '0';
        }
    }


    BFS(1,1);
      int ans0 = visited[n][m][0];
    int ans1 = visited[n][m][1];

    // 두 경로 중 가능한 최솟값 출력 (둘 다 -1이면 -1 출력)
    if (ans0 == -1 && ans1 == -1) cout << -1;
    else if (ans0 == -1) cout << ans1;
    else if (ans1 == -1) cout << ans0;
    else cout << min(ans0, ans1);
}