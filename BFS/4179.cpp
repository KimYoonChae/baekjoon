#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
/*
문제
https://www.acmicpc.net/problem/4179
*/
static int dx[]={0,1,0,-1}, dy[]={1,0,-1,0}; //사방으로 이동 체크
static int firetime[1001][1001], distHuman[1001][1001]; //불의 방문 여부 체크 좌표, 사람의 방문 여부 체크 좌표
static char grid[1001][1001]; //입력 받을 맵
int R,C; //행과 열

int main(){
    queue<pair<int,int>> fq,pq; //불큐, 사람 큐

    //불, 사람 모두 방문하기 전이니까 -1로 초기화
    memset(firetime,-1,sizeof(firetime));
    memset(distHuman,-1,sizeof(distHuman));
    int sx=-1,sy=-1; //현재 사람의 위치도 -1로 초기화

    cin>>R>>C; //행과 열 입력받기
    //맵 입력 받기
    for(int i=0;i<R;i++){
        string s;
        cin>>s;
        for(int j=0;j<C;j++){
            grid[i][j]=s[j];

            //불이 들어올때마다 큐에 넣고, 불의 방문시간도 0으로 만들기 ==> 시작점을 여러개 넣음
            if(grid[i][j]=='F'){
                fq.push({i,j});
                firetime[i][j]=0;
            }
            //사람이 들어온다면 현재 사람의 좌표도 업데이트 해주기
            if(grid[i][j]=='J'){
                sx=i; sy=j;
            }
        }
    } 
    //현재 사람의 좌표 큐에 넣고, 방문시간도 0으로 시작점 넣어주기
    pq.push({sx,sy});
    distHuman[sx][sy]=0;
 
    //불 BFS
    while(!fq.empty()){
        //현재 상태 저장 및 큐 팝
        pair<int,int> fcur= fq.front();
        fq.pop();

        for(int i=0;i<4;i++){
            int fx= fcur.first + dx[i];
            int fy = fcur.second + dy[i];
            
            //그리드 범위 유효성
            if(fx<0||fy<0||fx>=R||fy>=C) continue;
            //벽이이라면
            if(grid[fx][fy]=='#') continue;
            //이미 불이 도착해서 !=-1이라면
            if(firetime[fx][fy]!=-1) continue;

            firetime[fx][fy]=firetime[fcur.first][fcur.second]+1;
            fq.push({fx,fy});
        }
    }

   
    //사람 BFS
    while(!pq.empty()){
        //현재 상태 저장 및 큐 팝
        pair<int,int> pcur=pq.front();
        int curtime = distHuman[pcur.first][pcur.second]; //현재 지점에 사람이 도착한 시간 저장!!
        pq.pop();
        
        //만약에 현재 가장 자리에 서있다면 한칸 더 움직인 시간 ==> 탈출!
        if(pcur.first==0||pcur.second==0||pcur.first==R-1||pcur.second==C-1){
                cout<<curtime+1;
                return 0;
            }

        for(int i=0;i<4;i++){
            int px= pcur.first + dx[i];
            int py= pcur.second + dy[i];
            //범위 유효성 체크
            if(px<0||py<0||px>=R||py>=C) continue;
            //벽이라면 사람이 못감
            if(grid[px][py]=='#') continue;

            //사람이 이미 왔다간 길이라면 못감
            if(distHuman[px][py]!=-1) continue;

            //다음에 이동할 시간 저장
            int nexttime=curtime+1;

            //만약 불이 이미 왔다갔고, 그시간이 사람이 다음 이동할 시간보다 적다면 못감 => 왜?: 이미 불이 붙어있으니까
            if(firetime[px][py]!=-1 && firetime[px][py]<=nexttime) continue;
        
            //위의 조건들 다 피해간다면, 다음 시간 저장하고 큐 푸쉬
            distHuman[px][py]=nexttime;
            pq.push({px,py});
           }
    }

    //큐가 비었는데도 탈출못하면 프린트
    cout<<"IMPOSSIBLE";
}