# include <stdlib.h>
# include <stdio.h>



void outer()
{
	printf(" Outer func! \n ");
	void inner()
	{
		printf(" Inner func! \n ");
	}
}


int main(int argc , char *argv[])
{
	/*int printf(char *ptr , ...);
	printf(" Hello ! \n ");
	printf("World \n ");
	printf("Args : %d \n " , argc);
	for(int i = 0 ; i < argc ; i++)
		printf(" Argument : argv[%d] = %s \n " , i , argv[i]);*/
	//printf(" %s \n " , argv[1]);
	
	//char a = 'z';
	//char *const constant_pointer = &a;
	//printf(" %c \n " , *constant_pointer);
	//register int A = 18;
	//printf(" %d \n " , A);
	
	//outer();
      
	return 0;
}
