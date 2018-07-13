#include<stdio.h>
#include<string.h>
#include<algorithm>
#include <iostream>
using namespace std;
int a[20100];
int main(){
    int T,K,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&K);
        for(int i=0; i<N; ++i)
            scanf("%d",&a[i]);
        sort(a,a+N);
        int ans = 1000000001;
        for(int i=0; i+K-1<N; ++i){
            if( ans > a[i+K-1] - a[i] )
                ans = a[i+K-1] - a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
