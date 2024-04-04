# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int fact(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return 	fact(n-1) * n;

}


int factorial(int n)
{
	printf("Hello World");
	int result = 1; 
	for(int i = n ; i > 0 ; i--)
	{
		result = result * i;	
	}
	return result;
}

int main(void)
{
	int result = factorial(5);
	int result2 = fact(5);
	printf(" %d \n " , result);
	printf(" %d \n " , result2);
	return 0;
}
