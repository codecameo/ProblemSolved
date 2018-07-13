#include <stdio.h>
char ch[100000];
int main ()
{
int k,n=0,i,count,tcase=1,j;
scanf("%d",&k);
while(k--)
{
scanf("%d",&n);
getchar();
for(j=0;j<n;j++)
scanf("%c",&ch[j]);
for(i=0,count=0;i<n;i++)
{
if(ch[i]=='.')
{
count++;
i=i+2;
}
}
printf("Case %d: %d\n",tcase,count);
tcase++;
}
return 0;
}
