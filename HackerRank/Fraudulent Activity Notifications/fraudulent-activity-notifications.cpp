#include <deque>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits>
#include <iostream>
#include <stdio.h>
using namespace std;

int n,k;
deque<int> last_expenditure;

int getMedian() {
    int res, mid = k/2;
    if(k%2==1){
        return last_expenditure[mid]*2;
    }else{
        return last_expenditure[mid]+last_expenditure[mid+1];
    }
}

int main(){
    int expenditure[200001], cnt=0;

    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>expenditure[i];
        if(i < k)
            last_expenditure.insert(last_expenditure.begin()+i,expenditure[i]);
    }
    sort(last_expenditure.begin(),last_expenditure.end());

    for(int i=k; i<n; i++){
        int x = expenditure[i];
        int median = getMedian();
        if(median<=x) cnt++;

        auto last = lower_bound(last_expenditure.begin(),last_expenditure.end(),expenditure[i-k]);
        last_expenditure.erase(last);

        auto insert_pos = upper_bound(last_expenditure.begin(),last_expenditure.end(),x);
        last_expenditure.insert(insert_pos,x);
    }

    cout<<cnt<<'\n';

}
