#include <stdio.h>
#include <string.h>
/*
6시 41분
*/
int main(){
    char s1[65], s2[65];
    int check[65],c=0;
    scanf("%s %s",s1, s2);
    for(int i=0;i<strlen(s1);i++){
        if(s1[i]!=s2[i]){
            check[c++]=i;
        }
        for(int j=i;j<strlen(s1);j++){
            if(s1[j]==s2[j+1]) check[c++]=i;
        }
        
    }
    int n=c-1;
    int flag=1;

    for(int i=0;i<c;i++){
        if(s2[check[i]]==s1[check[n--]]){
            flag=1;
        }
        else flag=0;
    }
    
    if(flag==1) printf("%d %d", check[0]+1,check[c-1]+1);
    else printf("0");

   
}