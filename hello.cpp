#include <mpi.h>
#include <iostream>
#include <unistd.h>

int main(int argc, char **argv) {
    std::cout << "Before call to MPI_Init()" << std::endl;
    MPI_Init(&argc, &argv);
    std::cout << "Right after call to MPI_Init()" << std::endl;

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::cout << "Hello from " << rank << ". Total size=" << size << std::endl;
    std::cout << "Calling MPI_Finalize() on rank " << rank << " now" << std::endl;
    if (rank == 0) sleep(5);
    MPI_Finalize();
    std::cout << "Call to MPI_Finalize() on rank " << rank << " finished" << std::endl;

    return 0;
}
