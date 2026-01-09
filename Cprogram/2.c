#include <stdio.h>
int main(){
char c[5][15];
for(int i=0;i<5;i++){
    scanf("%s",c[i]);
}
for(int i=0;i<5;i++){
    for(int j=0;j<15;j++){
        if(c[i][j]==0){
            for(int t=j+1;t<15;t++){
                c[i][t]='!';
            }
        }
    }
}

for(int i=0;i<15;i++){
    for(int j=0;j<5;j++){
       if(c[i][j]!=0)
        printf("%c",c[j][i]);
    }
    if(i>=6){ break;
}}
for(int i=6;i<15;i++){
    for(int j=0;j<5;j++){
       if(c[i][j]!=0)
        printf("%c",c[j][i]);
    }

}
}