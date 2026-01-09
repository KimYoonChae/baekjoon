/*#include <stdio.h> 
int main(){
//첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
//첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.
int n;
scanf("%d",&n);
int blank=n-1, star=(n-blank);
for(int i=0;i<n;i++){
    for(int j=blank;j>0;j--) printf(" ");
    for(int t=0;t<star;t++) printf("*");
    
    printf("\n");

        star+=2; blank--;
    }
   
 star-=4; 
  printf("%d %d", blank, star);

    for(int i=0;i<n-1;i++){
    for(int j=blank;j<n;j++) printf(" ");
    for(int t=star;t>0;t--) printf("*");
    star-=2; blank++;
    printf("\n");

        
    }


return 0;
}*/
#include <stdio.h>
int main(){
    printf("%d",(int)"A");
}