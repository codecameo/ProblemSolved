#include<iostream>
#include<cstdio>
using namespace std;
#define mo 10056
int fenzu[1010][1010];
int A[1010];
int main()
{

	for(int i=1;i<1001;i++){
		fenzu[i][1]=1;
		for(int j=2;j<=i;j++)
		{
			fenzu[i][j]=(fenzu[i-1][j]*j+fenzu[i-1][j-1])%mo;
		}
	}
	A[1]=1;
	for(int i=2;i<1010;i++)
		A[i]=(A[i-1]*i)%mo;
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int j=1;j<=n;j++){
			ans+=fenzu[n][j]*A[j];
			ans%=mo;
		}
		printf("Case %d: %d\n",i+1,ans);
	}
	return 0;
}
