#include <iostream>
using namespace std;
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int visited[26];
static int A[21][21];
static int maxlen=0;
void DFS(int i, int j, int depth);
int R,C;

void DFS(int i, int j, int depth){
    if(maxlen<depth) maxlen=depth;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0&&y>=0&&x<R&&y<C){
            if(visited[A[x][y]-'A']==0&&A[x][y]!=A[i][j]){
                visited[A[x][y]-'A']=1;
                DFS(x,y,depth+1);
                visited[A[x][y]-'A']=0;
            }
        }
    }
}
int main(){
    for(int i=0;i<26;i++){
        visited[i]=0;
    }
    cin>>R>>C;
    for(int i=0;i<R;i++){
        string s;
        cin>>s;
        for(int j=0;j<C;j++){
            A[i][j]=s[j]-0;
        }
    }
    visited[A[0][0]-'A']=1;
    DFS(0,0,1);
    cout<<maxlen;
}