#include <stdio.h>
#include <time.h>
#include<omp.h>
#define n 100000
//sort ascending
void sort(int nums[])
{
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}
//sort descending
void sortDesc(int nums[])
{
    int i, j;
    for (i = 0; i < n; i++)
    {

        for (j = i + 1; j < n; j++)
        {
            if (nums[i] < nums[j])
            {
                int a = nums[i];
                nums[i] = nums[j];
                nums[j] = a;
            }
        }
    }
}

int main()
{
    int nums1[n], nums2[n];
    for (int i = 0; i < n; i++)
    {
        nums1[i] = i*2;
    }
    for (int i = 0; i < n; i++)
    {
        nums2[i] = i*2;
    }
    double stime = omp_get_wtime();
    sort(nums1);
    sortDesc(nums2);  
    long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + (nums1[i] * nums2[i]);
    }
    double etime = omp_get_wtime();
    double time = etime - stime;
    printf("sum = %ld\n", sum);
    printf("Time taken (seq): %f\n", time);
    return 0;
}
