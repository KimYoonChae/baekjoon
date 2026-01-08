#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

/*전역 변수*/
static char grid[1001][1001]; //입력받을 맵
static int humandist[1001][1001]; //사람이 방문한 시간 저장
static int firedist[1001][1001]; //불이 방문한 시간 저장
static int dx[]={0,1,0,-1}, dy[]={1,0,-1,0}; //사방으로 확인을 위해 필요한 변수
int flag=0;


int main(){
    int T; //테스트 케이스 개수
    int R,C; //행과 열

    cin>>T;//테스트 케이스 입력받고 그만큼 반복
    for(int i=0;i<T;i++){
        cin>>C>>R; //행,열 입력

        //불, 사람 큐 생성 및 초기화 + 사람의 현재 위치 초기화
        queue<pair<int,int>>fq,pq;
        memset(firedist,-1,sizeof(firedist));
        memset(humandist,-1,sizeof(humandist));
        int sx=-1, sy=-1;

        for(int i=0;i<R;i++){
        string s; //맵 입력 받기
        cin>>s;
        for(int j=0;j<C;j++){
            grid[i][j]=s[j];

            if(grid[i][j]=='*'){
                //큐에 넣고 0으로 만들기 (불의 시작점 넣기)
                firedist[i][j]=0;
                fq.push({i,j});
            }

            if(grid[i][j]=='@'){
                sx=i, sy=j; // 사람의 현재 위치 업데이트
            }
        }
    }

     //사람의 현재 위치 푸쉬, 사람의 시작점 넣기
    pq.push({sx,sy});
    humandist[sx][sy]=0;

    //불 BFS
    while(!fq.empty()){
        pair<int,int>curfire=fq.front();
        fq.pop();

        for(int i=0;i<4;i++){
            int fx=curfire.first+dx[i];
            int fy=curfire.second+dy[i];

            //범위 유효성 체크
            if(fx<0||fy<0||fx>=R||fy>=C) continue;
            //다음칸이 벽이라면
            if(grid[fx][fy]=='#') continue;
            //다음칸이 이미 불이 왔다간 칸이라면
            if(firedist[fx][fy]!=-1) continue;

            firedist[fx][fy]=firedist[curfire.first][curfire.second]+1;
            fq.push({fx,fy});
        }
    }

    //사람 BFS
    while(!pq.empty()){
        pair<int,int>curpeople=pq.front();
        int curtime = humandist[curpeople.first][curpeople.second];
        pq.pop();

        //현재 사람이 가장자리에 있다면 탈출
        if(curpeople.first==0||curpeople.second==0||curpeople.first==R-1||curpeople.second==C-1){
            cout<<curtime+1<<"\n";
            flag=1;

            break;
        }
        for(int i=0;i<4;i++){
            int px=curpeople.first+dx[i];
            int py=curpeople.second+dy[i];

            int nexttime=curtime+1;
           
           
            //범위 유효성 체크
            if(px<0||py<0||px>=R||py>=C) continue;
            //다음칸이 벽이라면 사람이 이동 못함
            if(grid[px][py]=='#') continue;
             //이미 사람이 왔다갔다면 못감
            if(humandist[px][py]!=-1) continue; 
            //다음칸에 이미 불이 왔다가서 불이 붙어있는 상황이라면 사람이 못감
            if(firedist[px][py]!=-1&&firedist[px][py]<=nexttime) continue;

            humandist[px][py]=nexttime;
            pq.push({px,py});
        }
    } 
    if(flag==0)cout<<"IMPOSSIBLE\n";
    //다하고 나서 그리드도 초기화하기!
    memset(grid,-1,sizeof(grid));
    flag=0;
    }
}




    
