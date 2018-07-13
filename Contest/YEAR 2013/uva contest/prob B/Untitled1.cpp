#include <stdio.h>
int main(){
int i,j,k,l,a,b;
double x;
for(i=1;i<=2000;i++){
printf("hhd\n");
for(j=1;j<=2000;j++)
for(k=2;k<=2000;k++){//printf("hd\n");
a=i+j+k;
b=i*j*k;
//l=a/(b-1);//
x=(1.0*a)/((1.0*b)-1.0);//printf("%d %d %lf\n",a,b,x);
l=a/(b-1);// ai line er jonno cruse kore........
if(x==l)
printf("%d %d %d %d\n",i,j,k,l);
//printf("hhd\n");
}}
return 0;
}
