# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


typedef enum Values 
{
	A,
	B,
	D,
	C
}VAL;


int main(void)
{
	VAL val = B;
	printf(" %d \n " , val);
	return 0;

}

