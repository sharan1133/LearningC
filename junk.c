# include <stdlib.h>
# include <stdio.h>

int main(int argc , char *argv[])
{
	int printf(char *ptr , ...);
	printf(" Hello ! \n ");
	printf("World \n ");
	printf("Args : %d \n " , argc);
	for(int i = 0 ; i < argc ; i++)
		printf(" Argument : argv[%d] = %s \n " , i , argv[i]);
	//printf(" %s \n " , argv[1]);

	return 0;
}
