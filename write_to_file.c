#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
int count,fd;
char buff[10];
write(1,"Enter Text: ",12);
count=read(0,buff,10);
fd=open("test",O_WRONLY);
write(fd,buff,count);
}
