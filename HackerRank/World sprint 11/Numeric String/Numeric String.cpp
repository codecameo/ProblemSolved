#include <bits/stdc++.h>

using namespace std;

int getMagicNumber(string s, int k, int b, int m){
    int maxPow=1;
    int sum=0;
    int num;
    int res;
    for(int i=k-1;i>=0;i--){
        num= (s.at(i)-'0')*maxPow;
        num= num%m;
        sum+=num;
        if(i!=0){
            maxPow*=b;
            maxPow=maxPow%m;
        }
    }
    res=sum%m;
    //printf("MaxPos %d Num %d\n",maxPow,sum);
    int len = s.length();
    for(int i=k;i<len;i++){
        num = (s.at(i-k)-'0')*maxPow;
        sum-=(num%m);
        sum*=b;
        num = (s.at(i)-'0')%m;
        sum+=num;
        sum%=m;
        //printf("Num %d\n",sum);
        res+=sum;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    int k;
    int b;
    int m;
    cin >> k >> b >> m;
    int result = getMagicNumber(s, k, b, m);
    cout << result << endl;
    return 0;
}
