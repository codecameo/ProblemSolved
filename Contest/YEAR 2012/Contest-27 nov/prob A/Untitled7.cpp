#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
char arr[10010];
int len,r,k;
vector<char>result1,result2,result3,result4,result5,result6,taken(10010,0);
//int taken[10010]={0};
long long int ct;
void call(int x)
{
    //cout<<result1.size()<<endl;
    if(x)
    if(result1!=result3 && result1!=result4 && result1!=result5 && result1!=result6 && result1!=result2)
    return;
    if(result1==result2)
    {
       ct++;
       return;
    }
    for(int j=x;j<len;j++)
    {
        if(taken[j]==0)
        {
            taken[j]=1;
            result1.push_back(arr[j]);
            /*if(result1!=result3 && result1!=result4 && result1!=result5 && result1!=result6 && result1!=result2)
            {
                result1.pop_back();
                continue;
            }*/
            call(j+1);
            taken[j]=0; result1.pop_back();
        }
    }
}
int main()
{
    int i;
    result3.push_back('s');

    result4.push_back('s');
    result4.push_back('e');

    result5.push_back('s');
    result5.push_back('e');
    result5.push_back('v');

    result6.push_back('s');
    result6.push_back('e');
    result6.push_back('v');
    result6.push_back('e');

    result2.push_back('s');
    result2.push_back('e');
    result2.push_back('v');
    result2.push_back('e');
    result2.push_back('n');
        while(gets(arr)!=0){
            ct=0;
        len=strlen(arr);
        for(i=0;i<len;i++)
        arr[i]=tolower(arr[i]);
     k=-1;
    call(0);
    cout<<ct<<endl;
    taken.clear();
    //memset(taken,0,sizeof(taken));
    }
}
