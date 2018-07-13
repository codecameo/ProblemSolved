
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* time = (char *)malloc(10240 * sizeof(char));
    scanf("%s",time);
    int timeFormat = ((time[0]-'0')*10)+(time[1]-'0');

    if(time[8]=='A')
    {
        timeFormat=timeFormat%12;
        time[1]=(timeFormat%10)+'0';
        time[0]=(timeFormat/10)+'0';
    }
    else
    {
        if(timeFormat!=12)
        timeFormat=(timeFormat+12)%24;
        time[1]=(timeFormat%10)+'0';
        time[0]=(timeFormat/10)+'0';
    }

    printf("%c%c%c%c%c%c%c%c\n",time[0],time[1],time[2],time[3],time[4],time[5],time[6],time[7]);
    return 0;
}
