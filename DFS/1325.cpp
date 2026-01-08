#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Cnt;
static vector<vector<int>>A; 
static int visited[10001];
void DFS(int node);
void DFS(int node){
     visited[node] = 1;
        Cnt++;
        for(int i:A[node]){
          if(visited[i]==0){
            DFS(i);
          }
        }
}
int main(){
    int n,m; //n노드수,m관계수
    cin>>n>>m;
    int x,y;
    A.resize(n + 1);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        A[y].push_back(x);
    }
    int max=0;
    vector <int> idx;
    for(int i=1;i<=n;i++){
         memset(visited, 0, sizeof(visited));
        Cnt=0;
       DFS(i);
       if(Cnt>max){
        max=Cnt;
        idx.clear();
        idx.push_back(i);
       }
       else if(Cnt==max){
        idx.push_back(i);
       }
    }
    for(int i:idx)
   {
    cout<<i<<" ";
   }

    
}