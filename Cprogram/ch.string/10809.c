#include <stdio.h>
#include<string.h>
int main(){
char a[101];
int d[27];
for(int i=0;i<36;i++){
    d[i]=-1;
}
int alpha[27];

for(int i=97;i<=122;i++){
    alpha[i-97]=i;
}

scanf("%s",a);

for(int i=0;i<strlen(a);i++){
for(int j=0;j<26;j++){
    if((int)a[i]==alpha[j]&&d[j]==-1){
        d[j]=i; break;
    }

}}

for(int i=0;i<26;i++){
    printf("%d ",d[i]);
}


}