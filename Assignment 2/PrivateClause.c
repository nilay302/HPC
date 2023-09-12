#include <omp.h>
#include <stdio.h>

int main() {
    int sum = 0;
    int N = 100;

    #pragma omp parallel for private(sum)
    for (int i = 0; i < N; i++) {
        sum += i;
        printf("Thread no: %d, sum: %d\n", omp_get_thread_num(),sum);
    }

    printf("Sum within parallel region: %d\n", sum);
    return 0;
}
