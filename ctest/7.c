#include <stdio.h>
int main(){
  /*  
    char c;

    scanf("%c",&c);
   
    int a=c-'0';
    printf("%d",a);*/

    char s[100];
    fgets(s,sizeof(s),stdin);

    int flag=1; //1=>true

    int x=strlen(s);
    if(x!=5){
        flag=0;
    }
    else{

        int r=s[0]-'0';
        int r3=((s[2]-'0')+(s[3]-'0'));
        if(r>9) {flag=0;}        
        if(r==9&&(s[1]-'0'<5||s[1]-'0'>9)) flag=0;  
        else if(r==0&&s[1]-'0'<0&&s[1]-'0'>7) flag=0;    
        
        if(r3<1&&r3>12) flag=0;         
    }
    
    if (flag==1) printf("Yes");
    else printf("No");
 


}