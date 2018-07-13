#include<cstdio>
#include<iostream>

using namespace std;


int grundy(int n)
{
    if(n<2)return 0;
    if(n%2==0)return n/2;
    else return grundy(n/2);
}


int main()
{
    int tc,t=0;
    cin>>tc;
    while(tc--)
        {
            int num,inp,nimsum=0;
            cin>>num;
            for(int i=1;i<=num;i++)
               {
                   cin>>inp;
                   int k=grundy(inp);
                   printf("%d\n",k);
                   //cout<<k<<endl;
                   nimsum^=k;
               }

             if(nimsum)printf("Case %d: Alice\n",++t);
             else   printf("Case %d: Bob\n",++t);
        }
}
