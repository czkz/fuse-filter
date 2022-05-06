/*bin/true && exec tcc -run "$0" "$@";*/
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>

size_t get_size(int fd) {
    struct stat statbuf;
    fstat(fd, &statbuf);
    return statbuf.st_size;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    size_t size = get_size(fd);
    char* mmapped = (char*) mmap(0, size, PROT_READ, MAP_SHARED, fd, 0);
    write(STDOUT_FILENO, mmapped, size);
    return errno;
}
