#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int number[100001],n;

int main() {

    int tKase,subSum,minNum,contSum,tempSum;
    scanf("%d",&tKase);
    while(tKase--)
    {
        contSum=0;
        subSum=0;
        tempSum=0;
        minNum=-10001;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&number[i]);

            if(number[i]<0)
                minNum=max(minNum,number[i]);
            else
                subSum+=number[i];

            tempSum=tempSum+number[i];

            if(tempSum<0)
                tempSum=0;

            contSum = max(contSum,tempSum);

        }

        if(subSum==0 && minNum!=-10001)
        {
            contSum=minNum;
            subSum=minNum;
        }

        printf("%d %d\n",contSum,subSum);

    }
    return 0;
}
