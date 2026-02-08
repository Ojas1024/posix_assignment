#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("data.txt", O_RDONLY);
    char *p = malloc(100);
    read(fd, p, 50);
    write(1, p, 50);
    int *x = NULL;
    *x = 5;
    return 0;
}
