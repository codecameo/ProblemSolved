#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int city[100001], pillars[100001]={-1};

int main() {
    int k,n,count = 0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>city[i];
        if(city[i]==1){
            pillars[count]=i;
            count++;

        }
    }

    if(pillars[0] == -1 || pillars[0]>=k || (n-pillars[count-1]-1) >= k){
        cout<<-1<<'\n';
        return 0;
    }

    int preIndex = 0, pillarCount = 1, gap = -1, temp, scale = 2*k-1;

    for(int i=0;i<count;i++){
        if(pillars[i]>=k){
            break;
        }
        preIndex=i;
    }

    for(int i=preIndex+1;i<count;i++){
        temp = pillars[i]-pillars[preIndex];
        //printf("i -> (%d,%d) preIndex -> (%d,%d) temp -> %d scale %d\n",i,pillars[i],preIndex,pillars[preIndex],temp,scale);
        if(temp > scale){
            if(gap == -1){
                pillarCount = -1;
                break;
            }
            gap = -1;
            pillarCount++;
            preIndex= i-1;
            i--;
        }else{
            gap = temp;
        }

        if(i == count-1){
            if((n-pillars[preIndex]-1) >= k){
                if(n-1-pillars[i] >= k){
                    pillarCount=-1;
                    break;
                }
                pillarCount++;
            }
        }
    }

    cout<<pillarCount<<'\n';

    return 0;
}
