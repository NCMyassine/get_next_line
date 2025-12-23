#include"get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int fd = open("txt.txt", O_RDONLY);
    int fd1 = open("yas.txt", O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd1);
    printf("%s", str);
    free(str);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = get_next_line(fd1);
    printf("%s", str);
    free(str);
    close(fd);
    close(fd1);
}