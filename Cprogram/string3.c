#include <stdio.h>
#include <string.h>
int main(){
    /*
  해당 문장의 영문자를 모두 대문자로 출력Handong Global University  HANDONG GLOBAL UNIVERSITY
    */

    char s[100];
    
    gets(s);
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='a'&& s[i]<='z')
        s[i]=s[i]-32;
    }

    printf("%s",s);
    



}