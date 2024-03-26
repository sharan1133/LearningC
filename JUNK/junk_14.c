# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int main(void)
{
	//printf(" %d \n " , stderr);
	pid_t forked = fork();
	int status;
	wait(&status);
	if(forked < 0)
		printf(" Error : %d \n " , stderr);
	else if(forked == 0)
	{
		pid_t x = getpid();
		printf(" PID inside forked block : %d \n " , x);
		printf("Forked process is executing code within this block \n");
		printf(" %d \n " , status);
	}
	else
	{
		pid_t y = getpid();
		printf(" PID inside parent block : %d \n " , y);
		printf("Don't know! \n");
	}
	return 0;
}
