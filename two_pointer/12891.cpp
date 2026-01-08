#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int max, part;
    cin>>max>>part;
    string c;
    vector<int>password(4);
    cin>>c;
   
    for(int i=0;i<4;i++)
    {
    cin>>password[i];
    } 

    int s=0,e=part-1; int real[4]={0};
    int count=max-part+1;
    for(int i=s;i<=e;i++){
            if(c[i]=='A'){
                real[0]++;
            }
            if(c[i]=='C'){
                real[1]++;
            }
            if(c[i]=='G'){
                real[2]++;
            }
            if(c[i]=='T'){
                real[3]++;
            }
        }
    for(int i=0;i<count;i++){
        s++; e++;
        c[s]
    }


    /*
    int count=0;
    int real[4]={0};
    
    while(1){
       if(e>max-1) break;
        for(int i=s;i<=e;i++){
            if(c[i]=='A'){
                real[0]++;
            }
            if(c[i]=='C'){
                real[1]++;
            }
            if(c[i]=='G'){
                real[2]++;
            }
            if(c[i]=='T'){
                real[3]++;
            }
        }

        if(password[0]<=real[0]&&password[1]<=real[1]&&password[2]<=real[2]&&password[3]<=real[3]) {count++;}
        for(int i=0;i<4;i++){
            real[i]=0;
        }
        s++; e++;
         
          
     cout<<count;
   
    }*/

   
    
}