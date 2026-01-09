#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int max=0;
    if(a==b&&b==c&&a==c) printf("%d",a*3);
    else{
       max = a;
if (b > max) max = b;
if (c > max) max = c;
    int sum=a+b+c;

  

    int result=(max-(sum-max-1));
    int r=((max-result)+(sum-max));
  if(sum-max>max) r=a+b+c;
    printf("%d",r);
    }
   
}