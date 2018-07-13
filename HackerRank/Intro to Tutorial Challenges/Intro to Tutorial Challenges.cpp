#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,num,ar[1001],low,high,mid;

    scanf("%d %d",&num,&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }

    low=0;
    high=n-1;

    while(low<=high)
    {
        mid=(low+high)/2;
        //printf("index: %d\n",mid);
        if(ar[mid]==num)
        {
            printf("%d\n",mid);
            break;
        }
        else if(ar[mid]>num)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    return 0;
}

