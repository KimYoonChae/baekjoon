#include <stdio.h>
char b[2001][2001]={0};
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int min;
    if(n<m) min=n;
    else min=m;
    if(k>min) return 0;

    for(int i=0;i<2001;i++){
        for(int j=0;j<2001;j++){
            b[i][j]='0';
        }
    }

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&b[i][j]);
        }
    }

    int x=1,y=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           if(b[j][j+(k-1)]==0||b[])
        }
    }

    // 입력된 보드판 확인하기
   /* for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%c",b[i][j]);
        }printf("\n");
    }
    printf("\n%c",b[1][10]);*/

}