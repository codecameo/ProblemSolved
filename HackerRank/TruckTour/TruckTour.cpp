#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int index = 0, fule = 0;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        int diff = x-y;
        fule+=diff;
        if(fule<0){
            fule = 0;
            index = i;
        }
    }
    cout<<index<<endl;
    return 0;
}


