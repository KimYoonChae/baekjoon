#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

vector<vector<int>>A;
static int visited[2001];
static int N,M,cnt=0;
bool flag=false;

void DFS(int node, int d){
	

	if(d>=5){flag=true; return;}

	for(int i : A[node]){
		if(visited[i]==0){
			visited[i]=1;
			DFS(i,d+1);
			visited[i]=0;

		
		}
	}
}

int main() {
	

	cin>>N>>M;
	A.resize(N+1);

	int a,b;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	for(int i=0;i<N;i++){
			memset(visited,0,sizeof(visited));
			visited[i]=1;
			DFS(i,1);
			if(flag) break;
		
	}

	if(flag) cout<<1;
	else cout<<0;
	return 0;
}