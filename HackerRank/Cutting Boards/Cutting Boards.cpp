#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int tKase,m,n;
    long long vertical[100001], horizontal[100001];
    cin>> tKase;

    while(tKase--){
        int verSeg=1, horSeg=1, vIndex=0, hIndex=0;
        long long res=0;
        cin>>m>>n;
        for(int i=0;i<m-1;i++) cin>>vertical[i];
        for(int i=0;i<n-1;i++) cin>>horizontal[i];
        sort(vertical,vertical+(m-1),greater<int>());
        sort(horizontal,horizontal+(n-1),greater<int>());

        while(vIndex<m-1 || hIndex<n-1){
            res = res % 1000000007;
            //printf("VerNum -> %d HorNum -> %d vSeg -> %d hSeg -> %d Res -> %d\n",vertical[vIndex],horizontal[hIndex],verSeg,horSeg,res);
            if(vIndex>=m-1){
                res+= horizontal[hIndex]*verSeg;
                hIndex++;
                horSeg++;
                continue;
            }
            if(hIndex>=n-1){
                res+= vertical[vIndex]*horSeg;
                vIndex++;
                verSeg++;
                continue;
            }

            if(horizontal[hIndex] == vertical[vIndex]){
                if(horSeg<verSeg){
                    res+= vertical[vIndex]*horSeg;
                    vIndex++;
                    verSeg++;
                }else{
                    res+= horizontal[hIndex]*verSeg;
                    hIndex++;
                    horSeg++;
                }
            }else if(horizontal[hIndex] < vertical[vIndex]){
                res+= vertical[vIndex]*horSeg;
                vIndex++;
                verSeg++;
            }else if(horizontal[hIndex] > vertical[vIndex]){
                res+= horizontal[hIndex]*verSeg;
                hIndex++;
                horSeg++;
            }

        }
        cout<<res<<'\n';
    }


    return 0;
}

