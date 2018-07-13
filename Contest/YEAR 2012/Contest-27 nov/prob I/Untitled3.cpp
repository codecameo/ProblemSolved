#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
char arr[20];
int len,r,h;
vector<char>result1;
int taken[20]={0};
map<vector<char>,bool>m;
/*void call()
{
    if(result1.size()==r  && m[result1]!=1)
    {
       m[result1]=1;
       for(int i=0;i<r;i++)
       printf("%c",result1[i]);
        printf("\n");
        return;
    }
    for(int j=0;j<r;j++)
    {
        if(taken[j]==0)
        {
            taken[j]=1;
            result1.push_back(arr[j]);
            call();
            taken[j]=0; result1.pop_back();
        }
       //while(arr[j]==arr[j+1])j++;
    }
}*/
int main()
{
     int tcase,i;
     cin>>tcase;
     while(tcase--){
         cin>>r>>h;
         for(i=0;i<r;i++){
          arr[i]='0';
         }
         for(i=r-h;i<r;i++){
          arr[i]='1';
         }
         //puts(arr);
         do
        {
            for (int i =0; i <r; i++)
                printf("%c",arr[i]);
            printf("\n");
        } while (next_permutation(&arr[0],&arr[r]));
        if(tcase)printf("\n");
    }
         //puts(arr);
       /*call();
      memset(taken,0,sizeof(taken));
      m.clear();*/
     }

