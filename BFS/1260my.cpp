#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

static vector<bool> visited;
static vector<vector<int>> L;
void DFS(int node);
void BFS(int node);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,e,s; //노드 개수, 에지개수, 시작점
    int a,b; //첫노드 끝노드

    cin>>n>>e>>s;
    L.resize(n+1);
    visited.resize(n+1,false);
    for(int i=0;i<e;i++){
        cin>>a>>b;
        L[a].push_back(b);
        L[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(L[i].begin(),L[i].end());
    }
    DFS(s);
    cout<<"\n";
    fill(visited.begin(),visited.end(),false);
    BFS(s);
}

void DFS(int node){
    cout<<node<<" ";
    visited[node]=true;
    for(int i:L[node]){
        if(!visited[i]){
            visited[i]=true;
            DFS(i);
        }
    }
}

void BFS(int node){
    queue<int> q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        for(int i:L[cur]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
        
    }
}