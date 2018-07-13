#include <iostream>
#include <assert.h>

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
uint64_t nCrModp(uint64_t n, uint64_t r, uint64_t p)
{
    assert(r <= n);
    if (r > n-r) r = n-r;
    if (r == 0) return 1;
    if(n/p - (n-r)/p > r/p) return 0;

    uint64_t result = 1; //intermediary results may overflow 32 bits

    for (uint64_t i = n, x = 1; i > r; --i, ++x) {
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

int main() {
    uint64_t smallPrime = 17;
    uint64_t medNum = 3001;
    uint64_t halfMedNum = medNum >> 1;
    std::cout << nCrModp(medNum, halfMedNum, smallPrime) << std::endl;

    uint64_t bigPrime = 1000000007; // 2^32-5 is largest prime < 2^32
    uint64_t bigNum = 100000;
    uint64_t halfBigNum = 2;
    std::cout << nCrModp(bigNum, halfBigNum, bigPrime) << std::endl;
}
