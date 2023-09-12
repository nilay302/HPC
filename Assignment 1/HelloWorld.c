#include <omp.h>
#include <stdio.h>
void mssg()
{
    int n;
    n = omp_get_thread_num();
    printf("\n Hello World from no %d \n", n);
}
int main()
{
#pragma omp parallel num_threads(10)
    mssg();
    return 0;
}
