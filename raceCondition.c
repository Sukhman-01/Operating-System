/* Program to demonstrate Race Condition. 
	1. create 2 threads t1 and t2.
	2. 
	3. 
*/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *fun1();
void *fun2();
int shared = 1;//shared variable

int main()
{
	pthread_t t1, t2; // thread declaration
	pthread_create(&t1, NULL, fun1, NULL);//thread is created
	pthread_create(&t2, NULL, fun2, NULL);
	pthread_join(t1, NULL); /* process waits for thread to finish, comment this line to see the difference */
	pthread_join(t2, NULL);
	printf("final value of shared is %d\n",shared);//prints the updated value of shared variable
}

void *fun1()
{
	int x;
	x = shared;// t1 reads the value of shared variable
	printf("t1 reads the value of shared variable as %d\n",x);
	x++;//t1 increments its value
	printf("Local updation of variable x by t1: %d\n",x);
	sleep(1); // t1 is pre-empted by t2
	shared = x; // t1 updates the value of shared variable
	printf("value of shared variable updated by t1 is: %d\n",shared);
}

void *fun2()
{
	int y;
	y = shared;
	printf("t2 reads the value of shared variable as %d\n",y);
	y--; // t2 decrements its value
	printf("Local updation of variable y by t2: %d\n",y);
	sleep(1); // t2 is preempted by t1 
	shared = y;// t2 updates the value of shared variable
	printf("value of shared variable updated by t2 is: %d\n", shared);
}
