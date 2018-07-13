#include <stdio.h>
#include <math.h>
int n,k;
int line(int li)
{
	long long int  i,ans,p;
	p=k;
	ans=li;
	i=1;
	while (p<=li)
	{
	    //p=pow(k,i);
		ans+=li/p;
		p*=k;
	}
	if(ans>=n)
	return 1;
	else
	return 0;
}

int main()
{
	int low,high,mid;
	scanf("%d %d",&n,&k);
	low=0;high=n;
	while (low<=high)
	{
		mid=(low+high)/2;
		if (line(mid)==1)
		high=mid-1;
		else
		low=mid+1;
	}
	printf("%d\n",high+1);
	return 0;
}
