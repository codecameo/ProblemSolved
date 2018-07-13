#include <stdio.h>
int prime[3401] ={2},top=1;
	void sieve();

	int main()
	{
	        sieve();
	        int n;
	        while(scanf("%d",&n)==1 && n)
	        {
	                int soln = n;
	                if(n==1)
	                {
	                        puts("0");
	                        continue;
	                }
	                for(int i=0;i<top && n >=prime[i];i++)
	                {
	                        if(n%prime[i] == 0)
	                        {
	                                while(n%prime[i]==0)
                                    n/=prime[i];
	                                soln/=prime[i];
	                                soln*=prime[i]-1;
                            }
	                }
	                if(n != 1) soln/=n, soln*=(n-1);
	                printf("%d\n",soln);
	        }
	}
	void sieve()
	{
	        for(int i=3; i*i <= 1000000000 ; i+=2)
	        {
	                int judge =1;
	                for(int j=2;j*j <= i ;j++)
	                {
	                        if(i%j == 0)
	                                judge =0;
	                }
	                if(judge)
	                        prime[top++] = i;
	        }
	}
