#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int buffsize = 1000;

void    mygetline(int fd, char *buff)
{
    read(fd, buff, buffsize);
}


char *makeBuffer(void)
{
    char *buffer;
    buffer = (char *)malloc(sizeof(char) * buffsize);
    if(!buffer)
        return (0);
    return (buffer);
}

void    writeLine(char *s)
{
    int i;
    
    i = 0;
    if(!s)
        return ;
    while (s[i] != '\0' && s[i])
    {
        write (1, &s[i], 1);
        i++;
    }
    free(s);
}
 
int main()
{
    int fd = open("ok.txt",O_RDONLY);
    char *buff;
    buff = makeBuffer();
    mygetline(fd, buff);
    writeLine(buff);
}
