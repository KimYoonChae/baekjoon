#include <stdio.h>
typedef struct{
    char name[100];
    int price;
} fruit;

int main(){
    int n;
    scanf("%d", &n);
    fruit f[100];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s %d",f[i].name,&f[i].price);
        sum+=f[i].price;

    }
    int avg=sum/n;

  
     for(int i=0;i<n;i++)
    {
        if(f[i].price>=avg){
            printf("%s\n",f[i].name);
        }

    }

}