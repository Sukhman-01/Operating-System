// print the 10th, 11th, 12th character from a test file
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
int fd,n;
char buff[10];
fd = open("test",O_RDONLY);
lseek(fd,10,SEEK_SET);
n=read(fd,buff,3);
write(1,buff,n);

}
