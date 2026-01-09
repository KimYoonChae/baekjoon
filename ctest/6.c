#include <stdio.h>
int main(){
    char s[100],c;
    fgets(s,sizeof(s),stdin);
    scanf("%c",&c);
    int x=strlen(s);
    int count=0;

    int a=c-'0';


    for(int i=0;i<x;i++){
        if((s[i]-'0')==a||(s[i]-'0'+32)==a||(s[i]-'0'-32)==a) count++;
    }
    printf("%d",count);
    return 0;
}