#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <array>
using namespace std;

map<int,int> m,temp;
int n;
int cnt=0, cnt2=0, sort_num[100001];

int main() {
    array<int,100001> num;
    array<int,100001> temp_num;

    cin>>n;

    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        sort_num[i]=num[i];
        m[num[i]]=i;
    }

    temp = m;
    temp_num = num;

    sort(sort_num,sort_num+n);

    for(int i=0; i<n; i++){
        int nm = sort_num[n-i-1];
        int index = m[nm];
        if(nm == num[i]){
            continue;
        }

        cnt++;
        int temp = num[i];
        num[i]=nm;
        num[index]=temp;

        m[nm] = i;
        m[temp] = index;
    }

    m=temp;
    num=temp_num;

    for(int i=0; i<n; i++){
        int nm = sort_num[i];
        int index = m[nm];
        //printf("(%d %d) ",nm,temp_num[i]);
        if(nm == num[i]){
            continue;
        }

        cnt2++;
        int temp = num[i];
        num[i]=nm;
        num[index]=temp;

        m[nm] = i;
        m[temp] = index;
    }

    printf("%d\n",min(cnt,cnt2));

    return 0;
}
