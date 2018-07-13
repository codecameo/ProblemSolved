#include <stdio.h>
#include <string.h>

int main(){
 bool first=true;
   char letter[1010];
   int i,a;
for (i=0;i<=1010;i++) letter[1010]='\0';
   while (gets(letter)){
      int ch[128]={0},max=0,nk=strlen(letter);

   for (i=0;i<nk;i++){
         ch[letter[i]]++;
         if (max<ch[letter[i]]) max = ch[letter[i]];
      }
   if(first) first=false;
   else printf("\n");
   for (i=1;i<=max;i++)
         for (a=127;a>=32;a--)
            if (ch[a]==i)
               printf("%d %d\n",a,i);

      for (i=0;i<=1010;i++) letter[1010]='\0';
   }

   return 0;
}
