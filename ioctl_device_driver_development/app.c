#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define HELLO_CMD _IO('a','a')

int main()
{
    int fd = open("/dev/helloioctl", O_RDWR);
    ioctl(fd, HELLO_CMD);
    close(fd);
    return 0;
}
