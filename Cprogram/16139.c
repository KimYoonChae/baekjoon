#include <stdio.h>
int main(){
    char str[20000], a;
    int x,y,count[2001]={0};
    fgets(str,sizeof(str),stdin); //문자열 입력


    int q;
    scanf("%d",&q); //질문개수 입력

    int c=0;
    for(int i=0;i<q;i++){ //질문개수 동안
        scanf(" %c %d %d",&a,&x,&y); //비교할 문자, 범위 입력받기
        for(int j=x;j<=y;j++){
           
            if(str[j]-'0'==a-'0') {
                c++;
            }
        } count[i]=c;c=0;
    }

    for(int i=0;i<q;i++){
        printf("%d\n",count[i]);
    }
}