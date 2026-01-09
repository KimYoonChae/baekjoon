#include <iostream>
#include <string>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    typedef struct{
    int num; string str;
    }data;

    int t,r;
    string s;
    string answer[10];
    cin>>t;
    string tmp;
    data d[10];
    
    for(int i=0;i<t;i++){
        cin>>r>>s;
        d[i].num=r; d[i].str=s;
    }
 
    for(int i=0;i<t;i++){
        for(int j=0;j<d[i].num;j++){
           if(j==0) tmp+=d[i].str[j];
           else{
            tmp+=d[i].str[j+1];
           }
        }
        d[i].str=tmp;
    }
    cout<<d[0].str;
}