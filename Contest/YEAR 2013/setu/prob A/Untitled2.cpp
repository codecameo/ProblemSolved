#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
        bool flag=false;
        for(int k=18;k>=0;k--)
        {
            if(n&1<<k)
            flag=true;
            if(flag==true)
            {
                n=n xor 1<<k;
            }
        }
        return n;
}

