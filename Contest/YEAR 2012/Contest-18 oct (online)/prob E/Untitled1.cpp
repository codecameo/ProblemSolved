#include <stdio.h>
#include <map>
#include <string.h>
#include <string>
#include <iostream>
int parent[1000010];
using namespace std;
int findParent (int n)
	{
	    if ( parent [n] < 0 )
	        return n;
	    return parent [n] = findParent(parent [n]);
	}
int main()
{
    string c,d,st[10000];
    int i,x,tcase,n,a,b,max;
    for(;;){
    scanf("%d %d",&tcase,&n);
    if (tcase==0 && n==0)
    break;
    int j=-1;
    while(tcase--)
    {
        cin>>st[++j];
    }
        x=1;
        map<string,int>s;
        memset(parent,-1,sizeof(parent));
        for(i=0,max=-2;i<n;i++)
        {
            cin>>c>>d;
             if (!s[c])
                s[c]=x++;
             if (!s[d])
                s[d]=x++;
            a=findParent(s[c]);
            b=findParent(s[d]);

	            if (a==b) {
	                max=parent[a]*-1;
	                continue;
	            }

	            if ( parent [a] < parent [b]) {
	                parent [a] += parent [b];
	                parent [b]=a;
	                 if(parent[a]*-1>max)
	                max=parent[a]*-1;
	            }
	            else {
	                parent [b] += parent [a];
	                parent [a] = b;
	                if(parent[b]*-1>max)
	                max=parent[b]*-1;
	            }
        }
    printf("%d\n\n",max);
    }
    return 0;
}
