# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>


int main(void)
{
	int status;
	
	//wait(&status);
	printf(" Forked process starts : \n ");
	pid_t forked = fork();
	
	if(forked == 0)
	{
	   printf(" forked : %d \n " , forked);
	   exit(0);
	}
	wait(&status);
	printf(" Status : %d \n " , status);
}
