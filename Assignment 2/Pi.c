#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int num_points = 1000000;  // Number of random points to generate
    int points_inside_circle = 0;  // Counter for points inside the circle

    // Seed for random number generator
    unsigned int seed = 12345;

    // Set the number of threads for parallelism
    int num_threads = 4;
    omp_set_num_threads(num_threads);

    #pragma omp parallel
    {
        unsigned int thread_seed = seed + omp_get_thread_num();

        // Generate and check random points
        #pragma omp for reduction(+:points_inside_circle)
        for (int i = 0; i < num_points; i++) {
            double x = (double)rand_r(&thread_seed) / RAND_MAX;
            double y = (double)rand_r(&thread_seed) / RAND_MAX;

            if (x * x + y * y <= 1.0) {
                points_inside_circle++;
            }
        }
    }

    double pi_estimate = 4.0 * points_inside_circle / num_points;

    printf("Estimated value of pi: %lf\n", pi_estimate);

    return 0;
}
