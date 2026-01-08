#include <iostream>
#include <vector>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;
    int r;
    cin>>r;

    vector <int>v;
    v.resize(n+1);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(v[j]>v[j+1]){
                int tmp=v[j];
                v[j]=v[j+1];
                v[j+1]=tmp;
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]+v[j]==r){
                count++;
            }
        }
    }

    cout<<count;
}