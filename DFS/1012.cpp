#include <iostream>
#include <algorithm>
using namespace std;
/*
입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 
그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 
그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다. 두 배추의 위치가 같은 경우는 없다.

출력
각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.
*/

void DFS(int i, int j, int s1, int s2); //시작좌표 + 각 테스트 케이스의 밭 크기 좌표
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int visited[51][51]={0};
static int A[51][51]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     int T ,M,N,K; //테스트 케이스 수, 가로길이, 세로길이, 배추개수
    int numbers[100];
    cin>> T; //테스트 케이스 수 입력
    int x,y; //배추 심어진 곳의 좌표
    for(int i=0;i<T;i++){//테스트 케이스 만큼 반복
        int count=0;
        cin>>M>>N>>K; //가로길이, 세로 길이, 배추개수 입력받기
        for(int j=0;j<K;j++){ //배추 개수만큼 좌표입력받기
            cin>>x>>y;
            A[x][y]=1;
        }
        for(int q=0;q<M;q++){
            for(int w=0;w<N;w++){
                if(A[q][w]==1&&visited[q][w]==0){ 
                    count++;
                    DFS(q,w,M,N);
                }
               // cout<<count<<" ";
            }
        }
        numbers[i]=count;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                A[i][j] = 0;
                visited[i][j] = 0;
            }
        
    }
    for(int i=0;i<T;i++){
         cout<<numbers[i]<<"\n";
    }
   
 
}

void DFS(int i, int j, int s1, int s2){
visited[i][j]=1;
for(int q=0;q<4;q++){
    int x=i+dx[q];
    int y=j+dy[q];
    if(x>=0&&y>=0&&x<s1&&y<s2){
        if(visited[x][y]==0&&A[x][y]==1) DFS(x,y,s1,s2);
    }
}
}