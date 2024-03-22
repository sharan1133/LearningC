# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int main(void)
{
	pid_t curr = getpid();
	pid_t forked = fork();
	//system(" ps -f curr >> temp.txt ");
	
	char command[50];

	sprintf(command , "ps -fp %d >> temp.txt " , curr); 
	system(command);
	printf(" Current process ID : %d \n " , curr);
	printf(" Forked process ID : %d \n " , forked);
	
	return 0;
}
