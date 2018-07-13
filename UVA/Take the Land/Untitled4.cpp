#include <stdio.h>
int mt [105][105];
int main ()
{
    int m, i,j,k,l,n,min,count,ct;
    while ( scanf ("%d %d", &m, &n) ) {
        if (m==0 && n==0) break;

        int input;

        for ( i = 0; i < m; i++ ) {
            for (j=0;j<n;j++) {
                scanf ("%d",&input);
                mt[i][j] =input;
            }
        }
        int max =0;
        for(i=0;i<m;i++){
         for(j=0;j<n;j++)
         {
             if(mt[i][j]==0){
             for(k=i,ct=0,min=n;k<m;k++)
             {
                 if(mt[k][j]==1)
                 break;
                 ct++;
                 for(l=j+1;l-j<min && mt[k][l]==0 && l<n;l++)
                 {

                 }
                 count=l-j;
                 if(min>count){
                 if(max<(min*(ct-1))){
                 max=(min*(ct-1));
                 }
                 min=count;
                 }
             }
             if(max<(min*ct))
             max=(min*ct);
          }
         }
        }
        printf("%d\n",max);

    }

    return 0;
}
