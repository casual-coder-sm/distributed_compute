#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char **argv)
{
    int num_procs;
    int rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    {
       int randNum = 0;
       int seed = 1;
       if(rank == 1)
       {
            randNum = rand_r(&seed);
            printf("Process %d drew the number %d\n",rank,randNum);
            MPI_Send(&randNum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
       }
       else if (rank == 0)
       {
            printf("Process %d before receiving has the number %d\n", rank, randNum);
            MPI_Recv(&randNum, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Process %d received the number %d\n", rank, randNum);
       }
    }
    MPI_Finalize();

    printf("end of MPI\n");
}
