#include<stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c))
	{
	    if(a==0 && b==0 && c==0)
	    break;
		if((b-a)==(c-b))
		{
		    cout<<"AP"<<" "<<c+c-b<<endl;
		    //printf("AP %d\n",c+c-b);
		}
		else
		{
		    cout<<"GP"<<" "<<c*c/b<<endl;
		    //printf("GP %d\n",c*c/b);
		}
	}
  return 0;
}
