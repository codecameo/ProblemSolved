#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t;
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n,n5=0,n3=0,initNum=0;
        scanf("%d",&n);

        while(initNum <= n)
        {
            if((n-initNum)%3==0)
            {
                n3=initNum;
                n5=n-initNum;
                break;
            }
            initNum=initNum+5;
        }
        if(n5==0 && n3==0)
        {
            printf("-1");
        }
        else
        {
            for(int i=0;i<n5;i++)
            {
                printf("5");
            }
            for(int i=0;i<n3;i++)
            {
                printf("3");
            }
        }
        printf("\n");
    }
    return 0;
}
