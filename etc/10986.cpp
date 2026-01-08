#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,count=0;
 
    cin>>n>>m;   vector<int> v(n+1, 0);
    //std::vector<int>s(n+1,0);
    vector<vector<int>>s(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        cin>>v[i]; s[i][1]=v[i]*2;
          
        
    }

    for(int i=1;i<n;i++){ 
        int a=i+2;
        for(int j=2;j<=n;j++){
            if(j==2) s[i][j]=v[i]+v[i+1];
            else{
                if (a > n) break;
                s[i][j]=s[i][j-1]+v[a++];
            }
        }
       
    }

cout<<count<<"\n";
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
           cout<<s[i][j]<<" ";
           if(s[i][j]%m==0)count+=1;
        }cout<<count<<"\n";
    }
cout<<count;
}