/* program to create 2 threads t1 and t2. thread prints 0-4 while the main program 
prints 20-24 */

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *arg);
int i,j;
int main()
{
pthread_t t1, t2; // thread declaration
pthread_create(&t1, NULL, thread_function, NULL);//thread is created
pthread_create(&t2, NULL, thread_function1, NULL);

pthread_join(t1, NULL); /* process waits for thread to finish, comment this line to see the difference */
pthread_join(t2, NULL);
printf("Inside Main program\n");
for(j=20;j<25;j++)
{
printf("%d\n",j);
sleep(1);
}
}
void *thread_function(void *arg) /*the work to be done by the thread is 
defined in this function */
{
printf("inside thread 1 \n");
for(i=0;i<5;i++)
{
printf("%d\n",i);
sleep(1);
}
}

void *thread_function1(void *arg)
{
printf("inside thread 2\n");
sleep(1);
}

/* Note: to compile any program which involves creation of thread(s) use 
pthread library (lpthread) suppose the above program is named "Thread.c", 
then to compile write 
$ gcc Thread.c -lpthread
To run the command remains same
$ ./a.out */
