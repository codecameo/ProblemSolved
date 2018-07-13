#include <stdio.h>
#include <string.h>

int main ()
{
    int a=0,b=0,i,k,j,l;
    char ch[1000000],mirr[10000];
    memset(ch,NULL,sizeof(ch));
    memset(mirr,NULL,sizeof(mirr));
 mirr['A']='A';
 mirr['E']='3';
 mirr['H']='H';
 mirr['I']='I';
 mirr['J']='L';
 mirr['L']='J';
 mirr['M']='M';
 mirr['O']='O';
 mirr['S']='2';
 mirr['T']='T';
 mirr['U']='U';
 mirr['V']='V';
 mirr['W']='W';
 mirr['X']='X';
 mirr['Y']='Y';
 mirr['Z']='5';
 mirr['1']='1';
 mirr['2']='S';
 mirr['3']='E';
 mirr['5']='Z';
 mirr['8']='8';
    while(scanf("%s",ch)!=EOF)
    {
        l=strlen(ch);
         for(i=0,a=0,j=l-1;i<=j;i++,j--)
        {
          if(ch[i]!=ch[j])
          {
              a=1;
              break;
          }
        }
        for(i=0,b=0,j=l-1;i<=j;i++,j--)
        {
          if(mirr[ch[i]]!=ch[j])
          {
              b=1;
              break;
          }
        }
        if(b==1 && a==0)
        printf("%s -- is a regular palindrome.\n",ch);
        else if(a==1 && b==1)
        printf("%s -- is not a palindrome.\n",ch);
        else if(a==1 && b==0)
        printf("%s -- is a mirrored string.\n",ch);
        else if(a==0 && b==0)
        printf("%s -- is a mirrored palindrome.\n",ch);
        printf("\n");

    }
    return 0;
}
