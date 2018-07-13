#include <iostream>

#include <stdio.h>

#include <string.h>

#include <algorithm>

using namespace std;



int main() {

    int N, cd_length, track[25];

    while (scanf("%d %d", &cd_length, &N) != EOF && cd_length && N) {

        for (int i = 0; i < N; i++)

            scanf("%d", track + i);

        int optimum_mask = 0, optimum_sum = 0;

        for (int mask = 0, sum = 0; mask < (1 << N); sum = 0, mask++) {

            for (int i = 0; i < N; i++)

                sum += ((1 << i) & mask) ? track[i] : 0;

            if (sum > optimum_sum && sum <= cd_length)

                optimum_sum = sum, optimum_mask = mask;

        }

        for (int i = 0; i<N; i++)

            if((1<<i) & optimum_mask)

            printf("%d ", track[i]);



        printf("sum:%d\n", optimum_sum);

    }

    return 0;

}
