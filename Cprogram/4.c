#include <stdio.h>
int main(){

int num;
scanf("%d",&num);
int arr[1000000];
int a, b;

for(int i=0;i<num;i++){
    scanf("%d %d",&a,&b);
    arr[i]=a+b;
}
for(int i=0;i<num;i++){
    printf("Case #%d: %d\n",i+1,arr[i]);
}
return 0;

}