#include <iostream>
#include <string>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    getline(cin, s);

    for(int i=0;i<s.length();i++){
        if(s[0]==' ') s+=s[i+1];
    }
    if(s[s.length()-1]==' '){
        for(int i=0;i<s.length()-1;i++){
          s+=s[i];
        }
    }

    int count=1;
    for(int i=0;i<s.length();i++){
        if(s[i]==' ') count++;
    }cout<<s.length();
}