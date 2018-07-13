#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calculateClique(int m) {
    int res1,res2;

    int temp = 1+8*m;
    //printf("res %d\n",res);
    temp = sqrt(temp);
    //printf("res %d\n",res);
    res1=temp+1;
    res1=res1/2;

    res2 = temp-1;
    res2=res2/2;

    temp = res1*(res1-1)/2;


    printf("res %d %d\n",res1,temp);

    if(temp <= m)
        return res1;
    return res2;

    //printf("res %d\n",res);
}
int main(){

    int m,n,tKase,res;
    scanf("%d",&tKase);
    while(tKase--) {
        scanf("%d %d",&n,&m);
        //int res = calculateClique(m);

        res = n/2;

        if(n%2>0)
            res++;

        //printf("res %d\n",res);

        res = m/res;

        //printf("res %d\n",res);

        printf("%d\n",res+1);
    }


    return 0;
}
