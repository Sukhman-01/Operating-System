//parent with 2 child processes
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
pid_t p,q;
p=fork();
if(p==0)
{
	printf("I am 1st child with id %d\n",getpid());
	printf("1st child's parent id %d\n",getppid());
	
	q=fork();
	if(q==0)
	{
		printf("I am the 2nd child having id %d\n",getpid());
		printf("2nd child's parent id is %d\n",getppid());
	}
	else
	{
		wait(NULL);
		printf("I am parent with id %d\n",getpid());
	}
}
printf("Common\n");
}
