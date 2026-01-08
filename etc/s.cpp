#include <stack>
#include <iostream>
using namespace std;

int main(){
   int n;
   cin>>n;
   stack<int> s;

   int tsum=0,count=0;
   while(1){
 if(tsum<n){
    s.push(1);
    tsum++;
   }
   else{
    if(tsum==n){
        count++;
    }
    while(!s.empty()&&s.top()==2){
        s.pop();
        tsum-=2;
    }
     if(s.empty()) break;

    tsum--;
    s.pop();
    s.push(2);
    tsum+=2;
   }
    
   }
  
   cout<<count;
}