#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    cin>>n;

    queue<int> q;
    int sum=0,count=0;
    while(1){
        if(sum<n){
            sum+=2;
            q.push(2);
        }
        else{
            if(sum==n){
                count++;
            }
            
        }
    }
    cout<<count;
}