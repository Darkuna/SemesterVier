#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000000

int main() {
    int i = 0;

    double random_x = 0.0;
    double random_y = 0.0;

    srand(17);
    for (int count = 0; count < N; ++count){
        random_x = rand()/ ((double) RAND_MAX);
        random_y = rand()/ ((double) RAND_MAX);

        if (pow(random_x, 2) + pow(random_y, 2) <= 1){
            i += 1;
        }
    }


    double approx = 4.0 * i / N;
    printf("N: %d, I: %d, Pi: %f", N, i, approx);
}
