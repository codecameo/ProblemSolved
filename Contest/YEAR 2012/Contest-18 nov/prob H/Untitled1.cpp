#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    int cow, car, m;
    while (scanf("%d %d %d", &cow, &car, &m)){
          printf("%.5f\n", double(car*(car-1) + cow*car) / ((cow+car)*(cow+car-m-1)));
    }
    return 0;
}

