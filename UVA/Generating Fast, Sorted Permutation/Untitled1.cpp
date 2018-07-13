#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
char arr[40];
int len;
bool flag;
map<vector<char>,int>m;
vector<char>result1,result2;
int taken[200]={0};
void call(int x)
{
    //if(flag==true)
    //return;
    if(result1.size()==len)
    {
        result2=result1;
        //sort(result2.begin(),result2.end());
        if (m.find(result2)->second==1)
      //   flag=true;
        // if(flag==true)
         return;
         m.insert ( pair<vector<char>,int>(result2,1));
       for(int i=0;i<len;i++)
       printf("%c",result2[i]);
        printf("\n");
        return;
    }
    for(int j=0;j<len;j++)
    {
        //printf("1. %c %d\n",arr[i],i);
        if(taken[j]==0)
        {
            //printf("2.%c\n",arr[i]);
            taken[j]=1;
            result1.push_back(arr[j]);
            call(j+1);
            taken[j]=0; result1.pop_back();
        }
        //while(arr[j]==arr[j+1])j++;
    }
}
int main()
{
    int tcase;
    cin>>tcase;
    getchar();
    while(tcase--){
        m.clear();
        gets(arr);
        len=strlen(arr);
        sort(arr,arr+len);
    call(0);
    printf("\n");
    memset(arr,NULL,sizeof(arr));
    memset(taken,0,sizeof(taken));
    }
}
