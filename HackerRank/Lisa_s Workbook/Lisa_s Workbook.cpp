#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,k,chapter[101],page=0,problems,cnt=0,high,low;

    scanf("%d %d",&n,&k);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&problems);
        int x= problems/k;
        int y = problems%k;
        low=0;
        high=k;

        for(int j=0;j<x;j++)
        {
            page++;
            if(page>low && page <=high)
            {
                //printf("%d\n",page);
                cnt++;
            }
            low=high;
            high=high+k;
        }
        if(y>0)
        {
            page++;
            high=problems;
            if(page>low && page <=high)
            {
                //printf("%d\n",page);
                cnt++;
            }
        }
    }

    printf("%d\n",cnt);

    return 0;
}

