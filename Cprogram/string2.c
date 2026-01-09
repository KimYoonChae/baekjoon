#include <stdio.h>
#include <string.h>
int main(){
    /*
     해당 문장의 영문자를 모두 소문자로 출력c  handong global university
    */

    char s[100];
    
    gets(s);
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='A'&& s[i]<='Z')
        s[i]=s[i]+32;
    }

    printf("%s",s);
    



}