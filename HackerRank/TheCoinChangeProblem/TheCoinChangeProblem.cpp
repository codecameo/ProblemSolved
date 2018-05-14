#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    long long int table[251]={0};
    int n,m,coins[51];

    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d",&coins[i]);
    }
    table[0]=1;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(table[j]!=0)
            {
                int index=j+coins[i];
                if(index<=n)
                    table[index]+=table[j];
            }
        }
    }

    printf("%lld\n",table[n]);
    return 0;
}
