#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    const char* mem_name = "/my_shm";
    int size = sizeof(int);

    // 1. Open the existing memory
    int fd = shm_open(mem_name, O_RDONLY, 0666);

    // 2. Map it to a pointer
    int* shared_int = (int*)mmap(0, size, PROT_READ, MAP_SHARED, fd, 0);

    // 3. Read it
    std::cout << "Process B: Read " << *shared_int << " from shared memory!\n";

    // 4. Cleanup (Delete the shared memory from the system)
    shm_unlink(mem_name);
    
    return 0;
}
