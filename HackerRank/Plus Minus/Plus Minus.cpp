#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n,positiveCount=0,negitiveCount=0,zeroCount=0;
    scanf("%d",&n);
    int num;
    for(int arr_i = 0; arr_i < n; arr_i++){

        scanf("%d",&num);
        if(num<0)
           negitiveCount++;
        else if(num==0)
            zeroCount++;
        else
            positiveCount++;
    }
    printf("%.6lf\n",(positiveCount*1.0)/(n*1.0));
    printf("%.6lf\n",(negitiveCount*1.0)/(n*1.0));
    printf("%.6lf\n",(zeroCount*1.0)/(n*1.0));


    return 0;
}
