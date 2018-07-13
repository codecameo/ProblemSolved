#include <stdio.h>
int main ()
{
    int i,j,k,val,a,b,c,cube;
    for(cube=6;cube<=200;cube++)
    {
        val=cube*cube*cube;
        for(i=2;i<cube;i++)
    {
        a=i*i*i;
        for(j=i;j<cube;j++)
       {
        b=j*j*j;
         for(k=j;k<cube;k++)
         {
             c=k*k*k;
             if(val==a+b+c)
             printf("Cube = %d, Triple = (%d,%d,%d)\n",cube,i,j,k);
         }
       }
    }

    }


    return 0;
}
