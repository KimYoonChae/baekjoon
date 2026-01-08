#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int A[1001];
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }

    queue<int>q;
    q.push(1);
    int visited[1001];
    memset(visited, -1, sizeof(visited));

    visited[1]=0;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        
        if(cur==n){
            cout<<visited[cur];
            return 0;
        }

        int next=cur+A[cur];


        if(next<=n&&visited[next]==-1){
            visited[next]=visited[cur]+1;
            q.push(next);
        }
    }
    cout<<-1;
}