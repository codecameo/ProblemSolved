#include<stdio.h>
int main(){

int t;
scanf("%d",&t);
int cs=t;

while(t--){

int a,f;

scanf("%d %d",&a,&f);

int i,j,k;

for(k=1;k<=f;k++)
{

for(i=1;i<=a;i++)
{
for(j=1;j<=i;j++)
{
printf("%d",i);
}
printf("\n");
}

for(i=a-1;i>=1;i--)
{
for(j=1;j<=i;j++)
{
printf("%d",i);
}
printf("\n");
}

if(k<f)
printf("\n");
}
if(t>0)
printf("\n");

}
return 0;
}
