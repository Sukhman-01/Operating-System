/* wap to create a thread. it prints from 0 to n, where n is passed from the main process to the thread. 
the main process also waits for the thread to finish first and then prints from 20-24 */

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<pthread.h>

void *display(void *n){
	printf("inside thread\n");
	int m = *((int *)n);
	for(int j=0;j<=m;j++){
	printf("%d\n", j);
	sleep(1);
	}
}

int main(){
int n;
printf("enter a number\n");
scanf("%d",&n);

pthread_t t1;
pthread_create(&t1, NULL, display, &n);
pthread_join(t1, NULL);

printf("In Main program\n");
for(int i=20;i<25;i++){
	printf("%d\n", i);
	sleep(1);
}
}
