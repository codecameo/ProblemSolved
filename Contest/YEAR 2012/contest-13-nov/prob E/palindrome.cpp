#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
void strev(char st[]){
char st1[100];
int l=strlen(st),i,j;
for(i=l-1,j=0;i>=0;i--){
st1[j++]=st[i];
}
st1[j]=NULL;
strcpy(st,st1);
}
int main()
{
int len,c;
char input[25],out[100];

cout << "Please enter a string: ";
scanf("%s",input);
len=strlen(input);
cout<<len<<endl;
strcpy(out,input);
strev(out);
c=strcmp(input,out);
if (c==0)
{
cout << input << " is a palindrome"<<endl;
}
else
cout<<"sorry it is not palindrome";
return 0;
}
