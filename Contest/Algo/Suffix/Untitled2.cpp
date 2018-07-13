#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct suffix_data
{
	int i;
	int j;
	int pos;
	bool operator < (const suffix_data &b ) const
	{
		return i==b.i? ( j<b.j? true: false ) : (i<b.i? true:false );
	}
};

suffix_data s[10004];
int suffix[15][10004],N,lg;
char ch[10004];
int lcp[10004],sub[10004];

int compute_lcp(int k)
{
	int a,b,c,x,y;
	c=0;
	x=s[k].pos;
	y=s[k-1].pos;
	for(a=lg;a>=0 && x<N && y<N;a--)
	{
		if(suffix[a][x]==suffix[a][y])
		{
			c=c+(1<<a);
			x=x+(1<<a);
			y=y+(1<<a);
		}
	}
	return c;
}

int main()
{


	int z,y;

	scanf("%d",&z);

	for(y=1;y<=z;y++)
	{


	scanf("%s",ch);
	N=strlen(ch);

	int a,b,c,t,d,e;

	for(a=1,lg=0;a/2<N;a=a*2,lg++) { }
	--lg;
	for(a=0;a<N;a++)
	{
		suffix[0][a]=ch[a]-'a';
	}
	t=1;
	for(a=1;a<=lg;a++)
	{
		for(b=0;b<N;b++)
		{
			s[b].i=suffix[a-1][b];
			s[b].j= b+t<N? suffix[a-1][b+t] : -1;
			s[b].pos=b;
			//printf("%d %d %d\n",s[b].i,s[b].j,s[b].pos);
		}
		sort(s,s+N);
        for(b=0;b<N;b++)
            printf("%d %d %d\n",s[b].i,s[b].j,s[b].pos);
		e=1;
		suffix[a][s[0].pos]=e;
		for(b=1;b<N;b++)
		{
			c=s[b].pos;
			d=s[b-1].pos;
			suffix[a][c]= (s[b].i==s[b-1].i && s[b].j==s[b-1].j)? suffix[a][d] : (++e);
			//printf("%d %d %d\n",c,d,suffix[a][c]);
		}
		t=t*2;
	}
	int lo,hi,l;

	e=0;

	scanf("%d %d",&lo,&hi);

	for(a=0;a<N;a++)
	{
		l=N-s[a].pos;

		if(a)
		{
			lcp[a]=compute_lcp(a);
			t=lcp[a]+1;
		}
		else
		{
			lcp[a]=l;
			t=1;
		}

		//cout<<t<<" "<<l<<" "<<lo<<" "<<hi<<" ";
		if(t<=lo && l>=hi)
		{
			e=e+(hi-lo+1);
			continue;
		}

		if(lo<=t && hi>=l)
		{
			e=e+(l-t+1);
			continue;
		}

		if(lo<t && hi>=t && hi<=l)
		{
			e=e+(hi-t+1);
			continue;
		}

		if(lo>t && lo<=l && hi>=l)
		{
			e=e+(l-lo+1);
			continue;
		}
		//cout<<e<<endl;
		//cout<<lcp[a]<<endl;
	}
	printf("Case %d: %d\n",y,e);

	}
	return 0;
}
