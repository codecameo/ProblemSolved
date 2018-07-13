#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 10001000
#define LL long long
using namespace std;

bool mark [N];
vector <LL> primeList;
vector <LL> primeFactors;
bool isNegative;

bool isPrime (LL p)
{
    if ( p < 2 || p % 2 == 0 ) return false;

    int len = sqrt (p * 1.0);

    for ( int i = 3; i <= len; i += 2 ) {
        if ( p % i == 0 ) return false;
    }

    return true;
}

void sieve ()
{
    memset (mark, true, sizeof (mark));

    mark [0] = mark [1] = false;

    for ( int i = 4; i < N; i += 2 ) mark [i] = false;

    for ( int i = 3; i * i <= N; i += 2 ) {
        if ( mark [i] ) {
            for ( int j = i * i; j < N; j += 2 * i ) mark [j] = false;
        }
    }

    primeList.clear ();
    primeList.push_back (2);

    for ( int i = 3; i < N; i += 2 ) {
        if ( mark [i] ) primeList.push_back (i);
    }

    //printf ("%d\n", primeList.size ());
}

LL findPrimeFactors (LL n)
{
    int ind = 0;
    LL tmp = n;
    primeFactors.clear ();

    while ( primeList [ind] * primeList [ind] <= n ) {
        while ( tmp % primeList [ind] == 0 ) {
            tmp /= primeList [ind];
            primeFactors.push_back (primeList [ind]);
        }
        ind++;
    }

    if ( tmp > 1 )
        primeFactors.push_back (tmp);

    sort (primeFactors.begin (), primeFactors.end ());

    if ( isNegative ) return primeFactors [primeFactors.size() - 1];

    if ( primeFactors [0] == primeFactors [primeFactors.size () - 1] ) return -1;
    return primeFactors [primeFactors.size() - 1];
}

int main ()
{
    sieve ();

    LL n;

    while ( cin >> n && n ) {
        if ( n < 0 ) { n *= -1; isNegative = true; }

        if ( n < 4 || (n < N && mark [n]) || isPrime (n) ) { printf ("-1\n"); continue; }

        cout << findPrimeFactors (n) << endl;

        isNegative = false;

    }
	return 0;
}
