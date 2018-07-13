#include <string.h>
#include <stdio.h>
using namespace std;
int f[1000100];
char a[1000100],b[1000100],c[1000100];

void preKMP(){
    int m = strlen(b),k;
    f[0] = -1;
    for (int i = 1; i<=m; i++){
        k = f[i-1];
        while (k>=0)
        {
            if (b[k]==b[i-1])   break;
            else    k = f[k];
        }
        f[i] = k + 1;
    }
}

int KMP(){
    int m = strlen(b);
    int n = strlen(a);
    int cnt = 0;
    preKMP();
    int i = 0;
    int k = 0;
    i=0;

    while (i<n){
        if (k==-1){
            i++;
            k = 0;
        }
        else if (a[i]==b[k]){
            i++;
            k++;
            if (k==m)
                return m*2-i;
        }
        else    k=f[k];
    }
    return -1;
}

int main(){
    int N;
    scanf("%d",&N);
    scanf("%s %s",c,b);
    strcpy(a,c);
    strcat(a,c);
    int y = KMP();
    if(y==strlen(b))    y=0;
    printf("%d\n",y);
}
