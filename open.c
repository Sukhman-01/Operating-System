#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <fcntl.h>
int main()
{
	char buff[20];
	int n,fd;
	fd = open("test",O_RDONLY); //O_RDONLY, O_WRONLY, O_RDWR
	printf("File descriptor of test file is %d", fd);
	n = read(fd,buff,20);
	write(1,buff,n);
}
