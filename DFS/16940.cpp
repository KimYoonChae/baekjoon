#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int main() {
	int n;
	cin>>n;
    queue<int>q;
	int a,b;
	vector<vector<int>> V;
	V.resize(n+1);
	for(int i=0;i<n-1;i++){
      cin>>a>>b;
	  V[a].push_back(b);
	}
	vector<int> visited;
	visited.resize(n+1,0);
	
	visited[1]=1;
	q.push(1);

	vector<int> result;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		cout<<cur;
		result.push_back(cur);
		for(int i : V[cur]){
			if(visited[i]==0){
				q.push(i);
				visited[i]=1;
			}

		}
	}
	
 int tmp;
 bool flag=true;
	for(int i=0;i<result.size();i++){
		cin>>tmp;
		if(i==0){
			if(tmp!=result[i]) flag=false;
		}
		if(i==3){
			if(tmp!=result[i]) flag=false;
		}
		
	}
if(flag) cout<<1;
else cout<<0;

	return 0;
}