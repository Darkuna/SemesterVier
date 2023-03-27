#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 8
#define N 700000000

struct args{
    int id[NUM_THREADS];
    int thread_counts[NUM_THREADS];
    int work_per_thread;
};

void *approx(void* input){
    struct args *args = (struct args *) input;

    int id;
    //zählt von vorne bis keine Null kommt. dadurch erhalte ich meine ID
    for (int i = 0; i < NUM_THREADS; ++i) {
        if (args->id[i] != 0) {
            id = args->id[i];
            args->id[i] = 0;
            break;
        }
    }
    //printf("I am Thread %d\n", id);

    int count = 0;

    double random_x = 0.0;
    double random_y = 0.0;

    //srand(1234);
    for (int i = 0; i < args->work_per_thread; ++i){
        random_x = rand()/ ((double) RAND_MAX);
        random_y = rand()/ ((double) RAND_MAX);

        if (pow(random_x, 2) + pow(random_y, 2) <= 1){
            count += 1;
        }
    }

    ((struct args*)input)->thread_counts[id] = count;
    pthread_exit(NULL);
}

int main() {
    struct args *arguments = (struct args *)malloc(sizeof(struct args));
    arguments->work_per_thread = N/NUM_THREADS;

    pthread_t threads[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++){
        arguments->id[i] = i;
        if(pthread_create(&(threads[i]), NULL, &approx, arguments) != 0){
            printf("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    int sum_of_thread_counts = 0;

    for(int i = 0; i < NUM_THREADS; ++i){
        sum_of_thread_counts += arguments->thread_counts[i];
    }

    double approx = 4.0 * sum_of_thread_counts / N;
    printf("N: %d, I: %d, Pi: %f\n", N, sum_of_thread_counts, approx);
}
