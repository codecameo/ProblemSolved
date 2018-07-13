#include <stdio.h>
#include<iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define MAX 10000010
using namespace std;
bool table[MAX];
int prime[1000000];
vector<int>v[100];
void seive()
{
table[0]=table[1]=true;
int i,j;
for(i=4;i<=MAX;i+=2) table[i]=true;
for(i=3;i*i<=MAX;i+=2)
if(table[i]==0)
for(j=i*i;j<=MAX;j+=i)
{
    table[j]=true;
   // v[j].push_back(i);
}
prime[0]=2;
for(i=3,j=0;i<=MAX;i+=2)
if(table[i]==false) prime[++j]=i;
}
int main ()
{
    int tcase,num[100000],n,k,i,j;
    seive();
  scanf("%d",&tcase);
  while(tcase--)
  {
    scanf("%d %d",&n,&k);
      for(i=0;i<k;i++)
      {
          scanf("%d",&num[i]);
      }
      sort(num,num+k);
      for(i=0;i<k;i++)
      {
          for(j=0;j<v[n].size();j++)
          {
              if(j)
              printf(" ");
              if(num[i]==v[n][j])
              printf("%d");
              if(num[i]<v[n][j])
              break;
          }
      }

  }
    return 0;
}
