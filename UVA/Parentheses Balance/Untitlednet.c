#include<iostream>
#include<stack>

using namespace std;
int main()
{
 stack<char> st;
 char str[20000],ch;
 int i,l,n,s;
 scanf("%d%c",&n,&ch);
 while(n--)
 {
  gets(str);
  while(!st.empty())st.pop();
  for(l=0;str[l];l++);
  if(!l){printf("Yes\n");continue;}
  if(l&1){printf("No\n");continue;}
  for(i=0;i<l;i++)
  {
   switch(str[i])
   {
   case 40:
   case 91:
    st.push(str[i]);s=0;break;
   case 41:
   case 93:
    s=1;
                if(st.empty()){s=0;i=l;continue;}
    ch=st.top();
    if((ch=='('&&str[i]==')')||ch=='['&&str[i]==']')
    {
     st.pop();
     continue;
    }
    s=0;i=l;
    break;
   }
  }
  if(s)printf("Yes\n");
  else printf("No\n");
 }
 return 0;
}
