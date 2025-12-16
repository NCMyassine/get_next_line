#include"get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int i = 0;
    int fd = open("txt.txt", O_RDONLY);
    char *str = get_next_line(fd);
    while (str != NULL)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
    close(fd);
}