#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t p,q;
printf("before fork\n");
p=fork();
if(p==0)
{
//sleep(2);
printf("I am child having id %d\n",getpid());
printf("My parent's id is %d\n",getppid());
	
	q=fork();
	if(q==0)
	{
	sleep(2);
	printf("I am 2nd child having id %d\n",getpid());
	printf("2nd childs parent id %d\n",getppid());
	}
}
else{
printf("My child's id is %d\n",p);
printf("I am parent having id %d\n",getpid());
}
printf("Common\n");
}
