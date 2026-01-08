#include <iostream>
using namespace std;

static int M,N;
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int A[502][502];
int count=0;
void DFS(int i, int j);

void DFS(int i, int j){
    if(A[i][j]==A[M][N]) count++;
   // cout<<A[i][j]<<" ";
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];

        if(A[i][j]>A[x][y])
        {
                DFS(x,y);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M>>N;

    for(int i=0;i<M+1;i++){
            A[i][0] = 10001;
            A[i][N+1] = 10001;
    }

    for(int i=0;i<N+1;i++){
            A[0][i] = 10001;
            A[M+1][i] = 10001;
    }

    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>A[i][j];
        }
    }

    DFS(1,1);

    cout<<count;

}
