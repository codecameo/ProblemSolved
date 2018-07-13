#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,min_len=1001,temp_min,cnt;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
        cin >> arr[arr_i];
        min_len = min(min_len,arr[arr_i]);
    }
    printf("%d\n",n);

    while(true)
    {
        cnt=0;
        temp_min=1001;
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]-min_len;
            if(arr[i]>0)
            {
                temp_min=min(temp_min,arr[i]);
                cnt++;
            }

        }
        if(cnt==0)
            break;
        min_len=temp_min;
        cout<<cnt<<endl;
    }



    return 0;
}
