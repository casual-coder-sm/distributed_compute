#include <omp.h>
#include <stdio.h>

static long num_steps = 100000;
double step;

int main()
{
    int total_num_threds;
    double exec_start_time, exec_time;
    double pi, sum = 0.0;

    omp_set_num_threads(4);
    total_num_threds = omp_get_num_threads();
    // printf("Number of Threads = %d\n", total_num_threds);
    exec_start_time = omp_get_wtime();

    step = 1.0 / (double)num_steps;

#pragma omp parallel
    {
        long int i, num_sub_steps;
        double x, sub_sum = 0.0;
        int thread_id;
        total_num_threds = omp_get_num_threads();
        // printf("Number of Threads = %d\n", total_num_threds);

        thread_id = omp_get_thread_num();
        // printf("Inside thread ID  = %d\n", thread_id);

        num_sub_steps = num_steps / total_num_threds;
        i = thread_id * num_sub_steps;
        // printf("Start %d = %ld\n",thread_id,i);

        for (; i < (thread_id + 1) * num_sub_steps; i++)
        {
            x = (i + 0.5) * step;
            sub_sum = sub_sum + 4.0 / (1.0 + x * x);
        }
        sum += sub_sum;
    }
    pi = step * sum;
    exec_time = omp_get_wtime() - exec_start_time;
    printf("Executiont Time =%f\n", exec_time);
    total_num_threds = omp_get_num_threads();
    // printf("Number of Threads = %d\n", total_num_threds);
    printf("Sum = %f\n", pi);
}