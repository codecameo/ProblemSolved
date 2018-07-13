#include <stdio.h>
#include <string.h>
char ch1[1001],ch2[1001];
void strrev(int l)
{
    int i,j;
    for(i=l-1,j=0;i>=0;i--,j++)
    ch2[j]=ch1[i];
}
int main ()
{
    int i,j,len,max,k,l;
    char ch3[1001],ch4[1001];
    while(gets(ch1)!=0){
    len=strlen(ch1);
    strrev(len);
    puts(ch2);
    for(i=0,max=-1;i<len;i++)
    {
        for(j=0,k=0;j<len;j++)
        {
            if(ch1[i]==ch2[j]){
            ch3[k++]=ch1[i];
            //printf("%c",ch3[k-1]);
            i++;
            }
            else{
            if(k){
                i--;
                break;
              }
            }
            //printf("\n");
        }
        puts(ch3);
        l=strlen(ch3);
        if(l>max)
        {
            max=l;
            strcpy(ch4,ch3);
        }
        memset(ch3,NULL,sizeof(ch3));
    }
    puts(ch4);
    }
    return 0;
}
