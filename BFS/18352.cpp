#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;


int main(){
    int n,m,k,x;
    cin>>n>>m>>k>>x;
    vector<vector<int>> A;
    vector<int> visited;
    A.resize(n + 1);  
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        A[a].push_back(b);

    }
/* 
    queue <vector<int>> q;
    q.push(A[x]);
    visited[x]=0;*/
    visited.resize(n+1,-1);
    queue <int> q;
    q.push(x);
    visited[x]=0;

    vector<int> nums;
    
   

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        
        if(visited[cur]==k) {
            nums.push_back(cur);
        }

        for(int i:A[cur]){
            if(visited[i]==-1){
                visited[i]=visited[cur]+1;
                q.push(i);
            }
        }

    }

    if(nums.empty())
    cout<<-1;
    else{
        sort(nums.begin(),nums.end());
        for(int i:nums){
            cout<<i<<"\n";
        }
    }
   
}