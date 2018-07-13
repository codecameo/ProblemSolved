#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
void strev(char st[]){
char st1[1000];
int l=strlen(st),i,j;
for(i=l-1,j=0;i>=0;i--){
st1[j++]=st[i];
}
st1[j]=NULL;
strcpy(st,st1);
}
int palin(char input[])
{
int len,c;
char out[1000];
strcpy(out,input);
strev(out);
c=strcmp(input,out);
if (c==0){
len=strlen(input);
return len;
}
else
return 0;
}
int main()
{
    int l,max,j,ln,k,tcase,i;
    char st2[1000],input[1000];
    scanf("%d",&tcase);
    getchar();
    while(tcase--){
    max=0;
    gets(input);
    //puts(input);
    ln=strlen(input);
    for(i=0;i<ln;i++){
    k=0;
    for(j=i;j<ln;j++){
    st2[k++]=input[j];
    st2[k]=NULL;
    //puts(st2);
    l=palin(st2);
    if(l>max && l!=1)
    max=l;
    }
    }
    printf("%d\n",max);
    }
    return 0;
}
