#include <stdio.h>
#include <string.h>

int leap_year_or_not(char year[])
{
    int length=strlen(year),i,digit4=0,check_4,check_100,check_400,digit100=0,digit400=0;

    for(i=0;i<length;i++)
        {
            digit4=year[i]-'0'+digit4*10;
            digit4=digit4%4;
            digit100=year[i]-'0'+digit100*10;
            digit100=digit100%100;
            digit400=year[i]-'0'+digit400*10;
            digit400=digit400%400;
        }
    if(digit4==0) check_4=1;
    else check_4=0;
    if(digit100!=0) check_100=1;
    else check_100=0;
    if(digit400==0) check_400=1;
    else check_400=0;
    if((check_4==1 && check_100==1) || (check_400==1)) return 1;
    else return 0;
}

int huluculu_or_not(char year[])
{
    int length=strlen(year),i,digit15=0;

    for(i=0;i<length;i++)
        {
            digit15=year[i]-'0'+digit15*10;
            digit15=digit15%15;
        }
    if(digit15==0) return 1;
    else return 0;
}

int bulukulu_or_not(char year[])
{
    int length=strlen(year),i,digit55=0;

    for(i=0;i<length;i++)
        {
            digit55=year[i]-'0'+digit55*10;
            digit55=digit55%55;
        }
    if(digit55==0) return 1;
    else return 0;
}

int main()
{
    int c,s=0;
    char year[100000];

    while(gets(year))
        {
            c=0;
            if(s!=0) printf("\n");
            if(leap_year_or_not(year)==1)
                {
                    printf("This is leap year.\n");
                    c++;
                }
            if(huluculu_or_not(year)==1)
                {
                    printf("This is huluculu festival year.\n");
                    c++;
                }
            if(bulukulu_or_not(year)==1)
                {
                    printf("This is bulukulu festival year.\n");
                    c++;
                }
            if(c==0) printf("This is an ordinary year.\n");
            s++;
        }
    return 0;
