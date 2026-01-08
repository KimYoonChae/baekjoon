//integer overflow 책에 나온 정석 대로 다시 풀어보기
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector <int>O;
    O.resize(n+1,0);

    vector <int>S;


    vector <int>M;


    
    for(int i=1;i<=n;i++){
        cin>>O[i];
        S[i]=O[i]+S[i-1];
        M[i-1]=S[i]%m;
    }
    long long count=0;
    vector<long long>result;
    result.resize(n+1,0);
    for(int i=0;i<n;i++)
    {
        if(M[i]==0) count++;
        result[M[i]]++;
    }
    
    for(int i=0;i<m;i++){
        if(result[i]>1){
            count=count+((result[i]*(result[i]-1))/2);       
        }
    }
    cout<<count;
    

}