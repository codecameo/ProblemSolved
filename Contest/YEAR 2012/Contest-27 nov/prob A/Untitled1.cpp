#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;


long long dp[105];
char ch[10005];

int main()
{

      long long a,b,c,d,e,l,z;
      while((scanf("%s",ch))==1)
      {
          //ch=tolower(ch);
            l=strlen(ch);
            for(a=0;a<l;a++)
            {
                  if(ch[a]=='e' || ch[a]=='E')
                  {
                        dp[2]+=dp[1];
                        dp[4]+=dp[3];
                  }
                  if(ch[a]=='S' || ch[a]=='s')
                  {
                        dp[1]++;
                  }
                  if(ch[a]=='V' || ch[a]=='v')
                  {
                        dp[3]+=dp[2];
                  }
                  if(ch[a]=='N' || ch[a]=='n')
                  {
                        dp[5]+=dp[4];
                  }
                 // cout<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<" "<<dp[4]<<" "<<dp[5]<<endl;
            }
            cout<<dp[5]<<endl;
            dp[1]=dp[2]=dp[3]=dp[4]=dp[5]=0;
      }

}
