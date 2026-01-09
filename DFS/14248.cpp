#include <iostream>
using namespace std;
int cnt=0;
int n,A[100001],visited[100001]={0};
void dfs(int node){
    visited[node]=1;
    cnt++;
//cout<<node<<A[node]<<"\n";
    
    int nxt=A[node]; 
    
    
    
        

 if(node-nxt>0&&visited[node-nxt]==0){
         dfs(node-nxt);
    }
    if(node+nxt<=n&&visited[node+nxt]==0){
          dfs(node+nxt);
    }
 
  

    
    
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }

    int start;

    cin>>start;
    dfs(start);

    cout<<cnt;

}