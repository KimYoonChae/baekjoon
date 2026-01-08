#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static int numbers[101];
static int visited[101]={0},finished[101]={0};
vector<int>result;
void DFS(int a); 
void DFS(int a){
    visited[a]=1;
    int next=numbers[a];
    if(visited[next]==0){
        DFS(next);
    }
    else if(finished[next]==0){
        int t=next;
        result.push_back(t);
        while(t!=a){
            t=numbers[t];
            result.push_back(t);
        }
    }
    finished[a]=1;
    }

int main(){
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>numbers[i];
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==0)DFS(i);
    }
    cout<<result.size()<<"\n";
    for(int i:result) cout<<i<<"\n";

    

}