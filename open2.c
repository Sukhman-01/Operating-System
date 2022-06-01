#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <fcntl.h>
int main()
{
	char buff[20];
	int n,fd;
	fd = open("f1",O_RDONLY);
	lseek(fd,15,SEEK_SET);
	n = read(fd,buff,6);
	fd = open("f4",O_WRONLY);
	write(fd,buff,n);
}
