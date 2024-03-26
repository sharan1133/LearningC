# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int main(void)
{
	pid_t curr = getpid();
	pid_t forked = fork();
	//system(" ps -f curr >> temp.txt ");
	printf(" %d \n "  , stderr);	
	char command[50];
	//char command2[50];
	sprintf(command , "ps -fp %d >> temp.txt " , curr); 
	//sprintf(command2 , "ps -fp %d >> temp.txt " , forked);
	system(command);
	//system(command2);
	printf(" Current process ID : %d \n " , curr);
	printf(" Forked process ID : %d \n " , forked);
	
	return 0;
}
