#include <stdio.h>
#include <string.h>
/*
한 개의 문장(line)을 입력 받아
해당 문장의 각 단어 첫문자를 이용한 약어 표현 출력Handong Global University  HGU
*/
int main(){

    char str[100];
    gets(str);
    int a=1;
    char result[100];
    result[0]=str[0];
       for(int i=0;i<strlen(str);i++){
        if(str[i]==' ') result[a++]=str[i+1];
    }
    for(int i=0;i<a;i++){
        printf("%c",result[i]);
  
    }
        
}