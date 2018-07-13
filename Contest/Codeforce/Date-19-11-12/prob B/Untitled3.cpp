#include <stdio.h>
#include <string.h>
int main(){
    bool flag=0,flag1=0,flag2=0;
int l,i;
char st[50];
gets(st);
l=strlen(st);
for(i=0;i<l;i++){
//printf("%c",st[i]);
if(flag==0 && flag1==1){//printf("%cc",st[i]);
if(st[i-2]=='r' && st[i-1]=='u'){
printf("/");
flag=1;}
}
printf("%c",st[i]);
if(flag2==0){
if(st[i]=='p'){
printf("://%c",st[i+1]);
i++;
flag2=1;
}
}
if(flag1==0){
if(st[i+1]=='r' && st[i+2]=='u'){
printf(".");
flag1=1;}
}
}
}
