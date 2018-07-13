#include <iostream>
#include <stdio.h>
using namespace std;
int main ()
{
    int tcase,num,i,A,N,D,a;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d %d %d",&N,&A,&D);
        for(i=0,a=A,num=A;i<N-1;i++)
        {
            a+=D;
            num+=a;
        }
        cout << num << endl;
    }
    return 0;
}
