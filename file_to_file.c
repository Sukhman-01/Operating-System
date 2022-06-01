#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
char buff[20];
int n,fd;
fd = open("test",O_RDONLY);
n = read(fd,buff,20);
fd = open("test2",O_WRONLY);
write(fd,buff,n);
}
