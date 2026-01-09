#include <stdio.h>
#include <string.h>
int main(){
    char s[101];
    gets(s);

    char r[101];
    int a=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]-'0'>=2&&s[i]-'0'<=9){
            for(int j=0;j<s[i]-'0';j++){
                r[a++]=s[i-1];
            }
        }
        else if(s[i+1]-'0'<2||s[i+1]-'0'>9){
            r[a++]=s[i];
        }
    }
    printf("%s",r);
}