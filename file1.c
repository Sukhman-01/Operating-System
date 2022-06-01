//Write a program to read 20 characters from one file and copy those into another file
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <fcntl.h>

int main()
{
	char buff[30];
	int n,fd;
	fd = open("f1",O_RDONLY);
	n = read(fd,buff,20);
	fd = open("f4",O_WRONLY);
	write(fd,buff,n);
}
