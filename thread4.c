/* pass 2 arguments to the threads, t1 should add those arguments and t2 should subtract them */
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *var);
void *thread_function1(void *var);
struct args{
	int a;
	int b;
};
int i,j,n;
int main()
{
struct args arg;

printf("Enter 2 numbers to pass to threads: \n");
scanf("%d %d",&arg.a, &arg.b);
pthread_t t1, t2; // thread declaration
pthread_create(&t1, NULL, thread_function, &arg);//thread is created
pthread_create(&t2, NULL, thread_function1, &arg);

pthread_join(t1, NULL); /* process waits for thread to finish, comment this line to see the difference */
pthread_join(t2,NULL);
printf("Inside Main program\n");
}
void *thread_function(void *var) /*the work to be done by the thread is defined in this function */
{
struct args *arg = var;
printf("inside thread\n");
printf("addition: %d\n", arg->a + arg->b);
}

void *thread_function1(void *var)
{
struct args *arg = var;
printf("inside thread 2\n");
printf("subtraction: %d\n", arg->a - arg->b);
}

/* Note: to compile any program which involves creation of thread(s) use 
pthread library (lpthread) suppose the above program is named "Thread.c", 
then to compile write 
$ gcc Thread.c -lpthread
To run the command remains same
$ ./a.out */

