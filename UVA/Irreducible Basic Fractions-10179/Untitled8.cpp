#include <stdio.h>


long long int phi(long long int i)
{
	long long int res;
	int j;

	if (i==1) return 1;

        res=i;
        if (i%2==0)
        {
		res-=res/2;
		do i/=2; while (i%2==0) ;
        }
	for (j=3; j*j<=i; j+=2)
	{
		if (i%j==0)
		{
			res-=res/j;
			do i/=j; while (i%j==0) ;
		}
	}
	if (i>1) res-=res/i;
	return res;
}
int main ()
{
    int k;
    long long int re,num;
    for(k=0;;k++)
    {
        scanf("%lld",&num);
        if(num==0)
        break;
        else
        //re=phi(num);
        printf("%lld\n",phi(num));
    }

return 0;
}
