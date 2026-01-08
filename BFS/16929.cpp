#include <iostream>
#include <memory.h>
using namespace std;
static bool flag=false;
static int visited[51][51],N,M,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
static char C[51][51];

void DFS(int a, int b, int pa, int pb){
	if(flag) return;
	visited[a][b]=1;
	for(int i=0;i<4;i++){
		int x=a+dx[i];
		int y=b+dy[i];

		if(x<0||y<0||x>=N||y>=M) continue;

		if(C[x][y]!=C[a][b]) continue;
		
		if(visited[x][y]==0){
		DFS(x,y,a,b);
		}
		else if(!(x==pa&&y==pb)){
			flag=true;
		}
		
	}

}
int main() {
	memset(visited,0,sizeof(visited));
	cin>>N>>M;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		for(int j=0;j<M;j++){
			C[i][j]=s[j];
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			
	
			if(visited[i][j]==0){
			DFS(i,j,-1,-1);
			if(flag) break;	
			}
		}
	}

	if (flag) cout<<"Yes";
	else cout<<"No";

	return 0;
}



/*
bool hasCycle = false;
vector<vector<int>> g;
vector<int> state; // 0,1,2

void dfs(int v){
    state[v] = 1; // 방문 중

    for(int nxt : g[v]){
        if(state[nxt] == 0){
            dfs(nxt);
            if(hasCycle) return;
        }
        else if(state[nxt] == 1){
            // 스택에 있는 노드로 돌아감 => 사이클
            hasCycle = true;
            return;
        }
        // state[nxt] == 2면: 이미 끝난 노드라 사이클 아님
    }

    state[v] = 2; // 방문 완료
}


*/