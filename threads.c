# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <pthread.h>



// pthread_create(ThreadID , Attributes , Starting routine , arguments)


void* start_routine(void* arg)
{
	printf("Thread t1 is here ! \n ");
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t t1;
	int arg = 1;
	int *ptr;
	pthread_create(&t1 , NULL , start_routine , &arg);
	pthread_join(t1 , (void**)&ptr);
	return 0;
}
