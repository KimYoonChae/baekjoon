#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<vector<int>>v;
int cnt=0;
vector<int>visited,finished;
void DFS(int a){
	visited[a]=1;

	for(int i:v[a]){
		if(visited[i]!=1){
			DFS(i);
		}
		else if(finished[a]==0){
			cnt++;

		}
	}

	finished[a]=1;
}
int main() {
	cin>>n;
	cin>>m;
	v.resize(m+1);
	finished.resize(n+1,0);
	visited.resize(n+1,0);
	int a,b;
	for(int i=0;i<m;i++){
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
	}
	DFS(1);
	cout<<cnt;
	return 0;
}