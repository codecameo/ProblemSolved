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
    string c,d;
    int i,x,tcase,n,a,b;
    scanf("%d",&tcase);
    while(tcase--)
    {
        x=1;
        map<string,int>s;
        memset(parent,-1,sizeof(parent));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>c>>d;
             if (!s[c])
                s[c]=x++;
             if (!s[d])
                s[d]=x++;
            a=findParent(s[c]);
            //printf("%d %d\n",s[c],a);
            b=findParent(s[d]);
	          //  printf("%d %d\n",s[d],b);

	            if (a==b) {
	                printf ("%d\n", parent [a] * -1);
	                continue;
	            }

	            if ( parent [a] < parent [b]) {
	                parent [a] += parent [b];
	                parent [b]=a;
	                printf ("%d\n", parent [a] * -1);
	            }
	            else {
	                parent [b] += parent [a];
	                parent [a] = b;
	                printf ("%d\n", parent [b] * -1);
	            }

        }


    }
    return 0;
}
