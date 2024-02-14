# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

void VarArgsFunc(int num_args , ...);

int main(void)
{
   VarArgsFunc(5 , 10 , 20 , 30 , 40 , 50);
   return 0;
}


void VarArgsFunc(int num_args , ...)
{
	va_list args;

	va_start(args , num_args);

	for(int i = 0 ; i < num_args ; i++)
	{
		int value = va_arg(args , int);
		printf(" %d \n " , value); 
	}

	va_end(args);
}
