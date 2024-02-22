# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


void AddTwoNumberByRef(int *a , int *b , int *c)
{
	*c = *a + *b;
}


int AddTwoNumberByCall(int a , int b)
{
	//c = a + b;
	a = a+3;
	b = b+6;
	printf(" Value of a inside call by value func : %d \n " , a);
	printf(" Value of b inside call by value func : %d \n " , b);
	return a+b;
}


int main(void)
{
	int number = 2000;
	int number2 = 4000;
	int result;
	//AddTwoNumberByRef(&number , &number2 , &result);
	result = AddTwoNumberByCall(number , number2);
	printf(" Value of a outside call by value func : %d \n " , number);
	printf(" Value of b outside call by value func : %d \n " , number2);	
	printf(" %d \n " , result);

	return 0;
}
