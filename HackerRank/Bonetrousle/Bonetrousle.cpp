#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int b[100001];
long long int box,k,sticks;

long long int clearBox()
{
    long long int min = 0;
    for(long long int i=0; i<box; i++)
    {
        b[i]=i+1;
        min +=b[i];
    }
    return min;
}

void increase(long long int offset)
{
    for(long long int i=0; i<box; i++)
    {
        b[i]+=offset;
    }
}


bool getBoxNum(long long int offset)
{
    if(offset == 0)
        return true;

    long long int tempK = k;

    //printf("%d\n",tempK);

    for(long long int i = box-1; i >=0 && offset > 0; i--)
    {
        if(tempK - b[i] <= offset && tempK - b[i]>=0)
        {
            offset -= tempK - b[i];
            b[i]=tempK;
            tempK--;
        }
        else if(tempK - b[i]>=0)
        {
            b[i] += offset;
            return true;
        }
        else{
            return false;
        }
    }

    return offset==0;

}

int main() {

    int tKase;

    scanf("%d",&tKase);

    while(tKase--)
    {
        scanf("%d %d %d",&sticks,&k,&box);
        long long int minBox = clearBox();

        if(minBox > sticks)
        {
            printf("-1\n");
            continue;
        }

        long long int inc = (sticks-minBox)/box;
        long long int offset = (sticks-minBox)%box;


        printf("%d %d\n",inc,offset);

        if(b[box-1]+inc>k)
        {
            printf("-1\n");
            continue;
        }

        increase(inc);

        bool res = getBoxNum(offset);

        if(res && b[box-1] <= sticks)
        {
            for(long long int i=0; i<box;i++)
            {
                if(i>0)
                    printf(" ");
                printf("%d",b[i]);
            }
        }
        else
        {
            printf("-1");
        }
        printf("\n");

    }
    return 0;
}

