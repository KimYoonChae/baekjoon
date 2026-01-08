#include <iostream>
#include <vector>

using namespace std;


vector<int>visited,A,result;
static int n,cnt=0;

void DFS(int v){
    visited[v] = 1;
    int next = A[v];

    if(visited[next] == 0)
        DFS(next);
    else if(visited[next] == 1){
        int cur = next;
        do {
            cnt++;
            cur = A[cur];
        } while(cur != next);
    }

    visited[v] = 2;
}



int main() {
	int T;
	cin>>T;

	for(int i=0;i<T;i++){
		cin>>n;
		A.resize(n+1);
		visited.resize(n+1,0);
		cnt = 0;
		for(int j=1;j<=n;j++){
			cin>>A[j];
		}

		for(int j=1;j<=n;j++){
			if(visited[j]==0) {
				DFS(j);
			}
		}cout<<n-cnt;
	}


		

	
	return 0;
}