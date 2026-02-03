#include <iostream>
#include <fcntl.h>    // For O_CREAT, O_RDWR
#include <sys/mman.h> // For shm_open, mmap
#include <unistd.h>   // For ftruncate

int main() {
    const char* mem_name = "/my_shm";
    int size = sizeof(int);

    // 1. Create a shared memory "file"
    int fd = shm_open(mem_name, O_CREAT | O_RDWR, 0666);
    
    // 2. Set the size (enough for one integer)
    ftruncate(fd, size);

    // 3. Map it to a pointer
    int* shared_int = (int*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    // 4. Write to it
    *shared_int = 99; 
    std::cout << "Process A: Wrote 99 to shared memory.\n";

    return 0; // The memory stays alive in the OS
}
