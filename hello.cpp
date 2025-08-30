#include <iostream>
#include <unistd.h>

#include <mpi.h>

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    int world_size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    char hostname[128];
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        std::cerr << "Error getting hostname" << std::endl;
        return 1;
    }
    std::cout << "New hello from " << hostname << std::endl;

    MPI_Request req;
    char hostname_recv[128];
    MPI_Isend(hostname, sizeof(hostname), MPI_CHAR, (rank+1)%world_size, 0, MPI_COMM_WORLD, &req);
    MPI_Recv(hostname_recv, sizeof(hostname_recv), MPI_CHAR, rank==0?world_size-1:rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Wait(&req, MPI_STATUS_IGNORE);

    std::cout << "Received a message at " << hostname << " from " << hostname_recv << std::endl;

    MPI_Finalize();

    return 0;
}
