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
	q=fork();
	if(q==0)
	{
		printf("I am the 2nd child having id %d\n",getpid());
		printf("2nd child's parent id is %d\n",getppid());
	}
	else
	{
		printf("I am the 1st child having id %d\n",getpid());
		printf("1st child's parent id is %d\n",getppid());
	}
}
else
{
//wait(); //to prevent orphan process
printf("I am parent having id %d\n",getpid());
printf("My child's id is %d\n",p);
}
printf("Common\n");
}
