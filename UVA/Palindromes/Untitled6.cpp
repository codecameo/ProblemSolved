#include <stdio.h>
#include <string.h>
int palin(char ch[],int l)
{
  int c,i,j;
    for(i=0,c=0,j=l-1;i<j;i++,j--)
        {
          if(ch[i]!=ch[j])
          {
              c=1;
              break;
          }
        }
   return c;
}

int mir(char ch[],int l)
{
    int i;
    for(i=0;i<l;)
    {
        if(ch[i]=='A'||ch[i]=='E'||ch[i]=='H'||ch[i]=='I'||ch[i]=='J'||ch[i]=='L'||ch[i]=='M'
           ||ch[i]=='O'||ch[i]=='S'||ch[i]=='T'||ch[i]=='U'||ch[i]=='V'||ch[i]=='W'||ch[i]=='X'
           ||ch[i]=='Y'||ch[i]=='Z'||ch[i]=='1'||ch[i]=='2'||ch[i]=='3'||ch[i]=='5'||ch[i]=='8')
           i++;
        else
        return 1;
    }
    //printf("%d\n",i);
    return 0;
}

int main ()
{
    int i,k,j,l1,a,b;
    char ch1[1000000];
    for(k=0;;k++)
    {
        gets(ch1);
        l1=strlen(ch1);
        a=palin(ch1,l1);
        b=mir(ch1,l1);
        if(a==0 && b==1)
        printf("%s -- is a regular palindrome.\n",ch1);
        else if(a==1 && b==1)
        printf("%s -- is not a palindrome.\n",ch1);
        else if(a==1 && b==0)
        printf("%s -- is a mirrored string.\n",ch1);
        else if(a==0 && b==0)
        printf("%s -- is a mirrored palindrome.\n",ch1);

    }
    return 0;
}
