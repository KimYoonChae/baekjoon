#include <stdio.h>
int main(){
  int num,n[101],idx,max;
  scanf("%d",&num);

  for(int i=0;i<num;i++){
    scanf("%d",&n[i]);
    if(i==0) {
        max=n[0]; idx=0;
    }
    else{
        if(n[i]>max){
            max=n[i];
            idx=i+1;
        }
    }
  }
  printf("%d %d",idx,max);
    return 0;
}