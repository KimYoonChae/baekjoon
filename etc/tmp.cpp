#include <iostream>
using namespace std;

static int M,N;
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int A[501][501];//원래 데이터
static int B[501][501]={0};//방문여부 체크 배열
static int C[501][501]={0};//결과값

int DFS(int i, int j);

int DFS(int i, int j){
    if(i==M-1&&j==N-1) return 1; //목적지에 가면 방법한개 찾으니까 1리턴
if(B[i][j]!=0) return C[i][j]; //이미 방문한거니까 C에 저장된 값리턴
   C[i][j]=0;
    B[i][j]=1;//방문햇음표시
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        
         if(x>=0&&y>=0&&x<M&&y<N){
            if(A[i][j]>A[x][y])
            {
                 C[i][j]+=DFS(x,y);//사방으로 갈 수있는거 더하기
      
            }
        }
      
    }    return C[i][j];
    
}

   
   
   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>M>>N;//행,열

    //원래 데이터 입력받기
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    
    DFS(0,0);
    cout<<C[0][0];
/*  
for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<C[i][j];
        }cout<<"\n";
    }

*/


  

}