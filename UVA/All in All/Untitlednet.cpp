#include <stdio.h>
#include <string.h>

int main()
{
    char line1[100000],line2[100000];
    int length1,length2,i,j,k;

    while(scanf("%s",line1)!=EOF)
        {
            scanf("%s",line2);
            length1=strlen(line1);
            length2=strlen(line2);
            if(length2<length1) printf("No\n");
            else
                {
                    j=0;
                    k=0;
                    for(i=0;i<length2;i++)
                        {
                            if(line2[i]==line1[j])
                                {
                                    j++;
                                    if(j==length1)
                                        {
                                            printf("Yes\n");
                                            k++;
                                            break;
                                        }
                                }
 #include<stdio.h>
#include<math.h>
int main()
{
long num,i,j,bin,paici,a,b,p,q,gc;
while(scanf("%ld",&num)==1)
{
if(num==0)    break;
gc=1;
for(i=3;i!=0;i+=2)
    {
    bin=1;
    paici=1;
    a=i;
    b=num-i;
    if(a>b) break;
    if(a%2!=0)
        {
        p=(int)sqrt(a);
        for(j=3;j<=p;j+=2)
            {
            if(a%j==0)
                {
                bin=0; break;
                }
            }
        if(bin==1)
            {
            if(b%2!=0)
                {
                q=(int)sqrt(b);
                for(j=3;j<=q;j+=2)
                    {
                    if(b%j==0)
                        {
                        paici=0;    break;
                        }
                    }
                if(paici==1)
                    {
                    printf("%ld = %ld + %ld\n",num,a,b);
                    gc=0;
                    break;
                    }
                }
            }
        }
    }
if(gc==1)
printf("Goldbach's conjecture is wrong.\n");
}
return 0;
}                       }
                    if(k==0) printf("No\n");
                }
        }
    return 0;
}
