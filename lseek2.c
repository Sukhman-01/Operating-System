// print 10 chars from test then skip 5 then print 10
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
int fd,n;
char buff[20];
fd = open("test",O_RDONLY);
n=read(fd,buff,10);
write(1,buff,n);
lseek(fd,5,SEEK_CUR); // reposition from current position
n=read(fd,buff,10);
printf("\n");
write(1,buff,n);
lseek(fd,-6,SEEK_END);
n=read(fd,buff,5);
printf("\n");
write(1,buff,5);
}
