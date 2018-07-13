#include<stdio.h>
#include<string.h>
int main()
{
int n;
scanf("%d",&n);
while(n--)
{
char st[10];
scanf("%s",st);
if(strlen(st)==5)
printf("3\n");
else
{
int c=0;
if(st[0]=='o')
c++;
if(st[1]=='n')
c++;
if(st[2]=='e')
c++;

if(c>=2)
printf("1\n");
else
printf("2\n");
}
}
return 0;
}
