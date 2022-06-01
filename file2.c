// wap to read a number from the user. print those many characters froma file starting from the 10th char.
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
int n, fd;
char buff[50];
printf("Enter a number\n");
scanf("%d", &n);

fd = open("f1",O_RDONLY);
lseek(fd,9,SEEK_SET);
read(fd,buff,n);
write(1,buff,n);
}
