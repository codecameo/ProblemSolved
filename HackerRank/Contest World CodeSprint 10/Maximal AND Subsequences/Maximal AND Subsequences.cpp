#include <bits/stdc++.h>

using namespace std;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

vector<int64_t> numberSet[100001];

// p MUST be prime and less than 2^63
uint64_t inverseModp(uint64_t a, uint64_t p) {
    assert(p < (1ull << 63));
    assert(a < p);
    assert(a != 0);
    uint64_t ex = p-2, result = 1;
    while (ex > 0) {
        if (ex % 2 == 1) {
            result = (result*a) % p;
        }
        a = (a*a) % p;
        ex /= 2;
    }
    return result;
}

// p MUST be prime
uint32_t nCrModp(uint32_t n, uint32_t r, uint32_t p)
{
    assert(r <= n);
    if (r > n-r) r = n-r;
    if (r == 0) return 1;
    if(n/p - (n-r)/p > r/p) return 0;

    uint64_t result = 1; //intermediary results may overflow 32 bits

    for (uint32_t i = n, x = 1; i > r; --i, ++x) {
        if( i % p != 0) {
            result *= i % p;
            result %= p;
        }
        if( x % p != 0) {
            result *= inverseModp(x % p, p);
            result %= p;
        }
    }
    return result;
}

void addToSet(int64_t num){
    int64_t one = 1;
    for(int i=0;i<64;i++){
        int64_t bit = num & (one << i);
        if(bit!=0){
            numberSet[i].push_back(num);
        }
    }
    //print();
}

vector<int64_t> instersection(vector<int64_t> &v1, vector<int64_t> &v2){

    vector<int64_t> v3;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

    return v3;
}

void intersectSet(int index){

    //printf("Index %d\n",index);

    for(int i=63;i>=0;i--){
        if(i==index)continue;
        numberSet[i]=instersection(numberSet[i],numberSet[index]);
    }
    //print();
}

int main() {
    int n;
    int k;
    cin>>n>>k;
    vector<int64_t> a(n);
    for(int i = 0; i < n; i++){
       cin >> a[i];
       addToSet(a[i]);
    }

    int len=0, index;
    for(int i=63;i>=0;i--){
        if(numberSet[i].size()>=k) {
            len = numberSet[i].size();
            index = i;
            intersectSet(i);
        }
    }

    int64_t res = 0;

    for (int i=0;i<k && len>=k;i++){
        if(i == 0){
            res = numberSet[index][i];
            continue;
        }
        res = res & numberSet[index][i];
    }

    if(len<k)
        len = n;

    int64_t ans;
    uint32_t mod = 1000000007;

    ans = nCrModp(len, k, mod);

    cout << res <<endl;
    cout << ans <<endl;


    return 0;
}
