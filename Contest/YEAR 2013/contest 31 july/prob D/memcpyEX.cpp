#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int b[100]={0},i,le,j;
	gets(a);
	le=strlen(a);
	for(i=0;i<le;i++)
	{
		b[a[i]-60]++;
	}
	le=0;
	for(i=0;i<100;i++)
	if(le<b[i])
	{
	j=i;le=b[i];
	}
	printf("%c\n",j+60);
}
