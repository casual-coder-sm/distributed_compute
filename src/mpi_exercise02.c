#include <stdio.h>
#include "mpi.h"

int main(int argc, char **argv)
{
    int num_procs;
    int rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    {
        int a = 6.0;
        int b = 3.0;

        if(rank%3 == 0)
            printf("%d\n",a+b);
        else if(rank%3 == 1)
            printf("%d\n",a*b);
        else
            printf("%d\n",a>b?a:b);

    }
    MPI_Finalize();

    printf("end of MPI\n");
}
