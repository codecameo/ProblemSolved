#include <stdio.h>
#include <string.h>
int main ()

{

    int testCase;
    scanf ("%d", &testCase);
    char input [100];
    int totalAmount = 0;
    int inputAmount;
    while ( testCase-- )
    {
        scanf ("%s",input);
        if ( strcmp (input,"donate") == 0 )
         {
            scanf ("%d",&inputAmount);
            totalAmount += inputAmount;
         }
         else if(strcmp (input,"report") == 0)
         {
            printf ("%d\n",totalAmount);
         }
    }

    return 0;
}
