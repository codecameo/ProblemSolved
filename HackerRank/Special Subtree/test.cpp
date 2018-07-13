#include <stdio.h>

void print(int ar[6])
{
    for(int i=0;i<=5;i++)
        printf("%d ",ar[i]);
    printf("\n");
}

void jump(int x,int ar[6])
{
    if(x>5)
        return;

    ar[x]=x;
    print(ar);
    printf("%d\n",x);
    jump(x+1,ar);
    print(ar);
    printf("%d\n",x);
}

void change(int ar[])
{
    int ar2[6] = ar;
    ar[2]=12;
}

int main()
{
    int ar[6];

    print(ar);
    change(ar);
    print(ar);

return 0;
}
