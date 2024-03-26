# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>


int main(void)
{
	int status;
	
	wait(&status);
	pid_t forked = fork();
	printf(" %d \n " , status);
}
