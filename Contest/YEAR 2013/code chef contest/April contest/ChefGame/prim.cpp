#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
#define N 101
#define INF 9999999
/*struct node
{
	int x,y;
	double w;
}e[N*N];*/
int n;
double a[N][N];
double prim(int x)
{
	int v[N],i,j,k;
	double t=0,dis[N];
	for(i=0;i<n;i++)
	{
		v[i]=0;
		dis[i]=a[x][i];
	}
	v[0]=1;
	for(i=1;i<n;i++)
	{
		double min=INF;
		for(j=0;j<n;j++)
		{
			if(min>dis[j]&&!v[j])
			{
				min=dis[j];
				k=j;
			}
		}
		v[k]=1;
		t+=min;
		for(j=0;j<n;j++)
		{
			if(dis[j]>a[k][j]&&!v[j])
			{
				dis[j]=a[k][j];
			}
		}
	}
	return t;
}
int main()
{
	int i,j,k=0;
	double x[N],y[N];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%lf %lf",&x[i],&y[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			a[i][j]=a[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
	}
	printf("%.2lf\n",prim(0));
	return 0;
}
