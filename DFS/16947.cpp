#include <iostream>
#include <vector>
using namespace std;

int n;
bool cycle=false;vector<vector<int>>A;vector<int>visited;
void DFS(int a, int pa){
	visited[a]=1;
	cout<<a;
	for(int i : A[a]){
		if(visited[i]==0){
			
			DFS(i,a);
			

		}
		else if(i!=pa){
			cout<<i;
			cycle=true;
			
		}
	}

	
}
int main() {
	cin>>n;

	int a,b;
	
	A.resize(n+1);
	
	visited.resize(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			DFS(i,-1);
		}
	}
cout<<"\n";
	

	return 0;
}