#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char st[10000];
    int t;
    scanf("%d",&t);
    getchar();

    for(int i=0;i<t;i++)
    {
        char odd[5000]={'\n'},even[5000]={'\n'};
        scanf("%[^\n]%*c",st);
        int len = strlen(st);
        for(int j=0;j<len;j++)
        {
            if(j!=len)
            {
                if(j%2==1)
                {
                    odd[j/2]=st[j];
                }
                else
                {
                    even[j/2]=st[j];
                }
            }
        }
        printf("%s %s\n",even,odd);
    }
    return 0;
}
