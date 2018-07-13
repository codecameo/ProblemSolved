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
        int n,height=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            if(i%2==1)
                height=height*2;
            else
                height++;
        }
        printf("%d\n",height);

    }
    return 0;
}

