#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define cs c_str()
#define pub push_back
#define pob pop_back
#define sz size()
#define np next_permutation
#define FORst(it,x) for(map<string ,int>::iterator it=x.begin();it!=x.end();it++)
#define mem(a,s) memset(a,s,sizeof(a))
#define pi acos(-1.0)
#define eps 1e-9
#define scanfd(a) scanf("%d",&a)
#define scanfc(a) scanf("%c",&a)
#define scanfs(a) scanf("%s",a)
#define max(i,j) i>j?i:j;

#define LL long long
#define LLU long long unsigned
#define LLD long long double
#define N 1000000
#define MAX 0x3f
#define INF_MAX 2147483647
#define INF_MIN -2147483647

/*bool comp(const char &a, const char &b)
{
int delta = tolower(a) - tolower(b);
return delta ? delta < 0 : a <b;
}*/

int a[10000001],b[10];
int valid(int n)
{
mem(b,0);
int i,j,cnt=0;
while(n>0)
{
i=n%10;
if(b[i]==0)
{
cnt++;
b[i]=1;
}
if (cnt>2) return 0;
n/=10;
}
return 1;
}

void fnc()
{
int i;
a[0]=a[1]=1;

for(i=2;i<=10000000;i++)
{
if(valid(i))
{
a[i]=a[i-1]+1;
}
else a[i]=a[i-1];
}

}

int main()
{
int n,m,i,j,k;
a[0]=a[1]=1;

fnc();
while(cin >> n)
{
cout<< a[n] << endl;
}

}
