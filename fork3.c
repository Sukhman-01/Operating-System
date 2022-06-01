#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main()
{
pid_t p;
int n,fd;
char buff[50];
printf("before fork\n");
p=fork();
if(p==0)
{
//printf("I am child having id %d\n",getpid());
fd=open("share.txt",O_RDWR|O_CREAT,0765);
printf("File created");
}
else{
//printf("My child's id is %d\n",p);
//printf("I am parent having id %d\n",getpid());

wait(NULL);
fd = open("share.txt",O_WRONLY);
n=read(0,buff,50);
write(fd,buff,n);
}
printf("Common\n");
}
