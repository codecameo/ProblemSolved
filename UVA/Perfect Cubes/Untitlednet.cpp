# include <stdio.h>
int main()
{
   int a,b,c,d,i,j,k,n,l,val,m;
   for(val=6;val<=200;val++)
   {
       a = val*val*val;
        for(i=2;i<val;i++)
       {
           b = i*i*i;
           for(j=i;j<val;j++)
           {
               c = j*j*j;
               for(k=j;k<val;k++)
               {
                   d = k*k*k;
                   if(a==(b+c+d))
                   {
                   printf("Cube = %d, Triple = (%d,%d,%d)\n",val,i,j,k);
                   break;
                   }

               }
           }
       }
   }
    return 0;
}
