/* pass 2 arguments to the threads(name and roll no), t1 should add those arguments and t2 should subtract 
them */
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *var);
void *thread_function1(void *var);
struct args{
	char name[20];
	long int roll;
};
int i,j,n;
int main()
{
struct args arg;

printf("Enter name: \n");
scanf("%s",&arg.name);

printf("enter roll no\n");
scanf("%ld",&arg.roll);

pthread_t t1, t2; // thread declaration
pthread_create(&t1, NULL, thread_function, &arg);//thread is created
pthread_join(t1, NULL); /* process waits for thread to finish, comment this line to see the difference */

printf("Inside Main program\n");
}
void *thread_function(void *var) /*the work to be done by the thread is defined in this function */
{
struct args *arg = var;
printf("Name: %s\n", arg->name);
printf("Roll NO: %ld\n", arg->roll);
}

