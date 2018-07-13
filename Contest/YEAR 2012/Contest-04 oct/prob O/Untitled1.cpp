#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
int main ()
{
    char ar[1000];
    string a[11];
    int num[11],i,max,kase=0,tcase;
    scanf("%d",&tcase);
    while(tcase--)
    {
        for(i=0,max=-1;i<10;i++){
        scanf("%s %d",ar,&num[i]);
        a[i]=ar;
        memset(ar,'0',sizeof(ar));
        if(num[i]>max)
        max=num[i];
        }
        printf("Case #%d:\n",++kase);
        for(i=0;i<10;i++){
        if(num[i]==max)
        cout << a[i] << endl;
        }
    }

    return 0;
}
