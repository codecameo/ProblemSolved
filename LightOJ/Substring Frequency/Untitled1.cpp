#include <stdio.h>
#include <string.h>
void F(char pt,int l)
{
    int i,j;
    f[0]=f[1]=0;
    for(i=2;i<=l;i++)
    {
        j=f[i-1];
        for(;;)
        {
            if(pt[j+1]==pt[i])
            {

                break;
            }
        }
    }

}
int main()
{


    return 0;
}
