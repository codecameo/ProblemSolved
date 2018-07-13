#include <stdio.h>
#include <string.h>

int ar[1001][31];
int object[1001],person[101],price[1001];
int n_of_o,n_of_p;
int p;

int dp(int o, int weight)
{
    if(o>=n_of_o) return 0;
    if(ar[o][weight]!=-1)
        {
            //printf("AAA\n");
            return ar[o][weight];
        }
    int cost1=0,cost2=0;
    //printf("object[o]:%d  person[p]:%d\n",object[o],person[p]);
    //printf("Capacity: %d Carrying: %d Current: %d\n",person[p],weight,object[o]);
    if(object[o]<=person[p]-weight)
        {
            cost1=price[o]+dp(o+1,weight+object[o]);
           //printf("cost1: %d\n",cost1);
        }
    //printf("cost1: %d\n",cost1);
    cost2=dp(o+1,weight);
    //printf("Cost 1: %d Cost 2: %d\n",cost1,cost2);
    if(cost1>cost2)
        {
            ar[o][weight]=cost1;
            //printf("returnig cost1: %d\n",cost1);
            return cost1;
        }
    ar[o][weight]=cost2;
    //printf("returning cost2: %d\n",cost2);
    return ar[o][weight];
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {

            scanf("%d",&n_of_o);
            for(j=0;j<n_of_o;j++)
                {
                    scanf("%d %d",&price[j],&object[j]);
                }
            scanf("%d",&n_of_p);
            for(j=0;j<n_of_p;j++)
                {
                    scanf("%d",&person[j]);
                }
            int total=0,temp;
            for(j=0;j<n_of_p;j++)
                {
                    p=j;
                     memset(ar,-1,sizeof(ar));
                    temp=dp(0,0);
                    printf("%d\n",temp);
                    total=total+temp;
                }
            printf("%d\n",total);
        }
    return 0;
}
