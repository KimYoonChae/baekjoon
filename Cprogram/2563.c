#include <stdio.h>
int main(){
int count; int arr[100][100];
scanf("%d",&count);
for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
        arr[i][j]=0;
    }
}
int x,y;
for(int i=0;i<count;i++){
   scanf("%d %d",&x,&y);
   for(int j=x;j<10+x;j++){
    for(int t=y;t<10+y;t++){
        arr[j][t]=1;
    }
} 
}
int c=0;
for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
        if(arr[i][j]==1) c++;
    }
}
printf("%d",c);



    return 0;
}