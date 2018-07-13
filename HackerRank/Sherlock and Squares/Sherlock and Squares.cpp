#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int kase,x,y,a,b;
    scanf("%d",&kase);
    while(kase--)
    {
        scanf("%d %d",&a,&b);
        x=ceil(sqrt(a));
        y=floor(sqrt(b));
        printf("%d\n",(y-x+1));
    }

    return 0;
}
