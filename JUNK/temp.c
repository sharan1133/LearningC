# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int main(void)
{
	int a = 100;
	int t = 200;
	int *b = &a;
	int **c = &b;

	//*c = &t;
	**c = 300;

	//printf(" Value from ptr B %d \n " , *b);
	//printf(" Address of B : %d \n "  , &b);
	//printf(" *c = %d \n "  , *c);
	//printf("  c = %d \n "  ,  c);
	//printf(" b = %d \n "   ,  b);
	//printf(" &a = %d \n "  , &a);
	printf(" a = %d \n "  , a);
	printf(" *b = %d \n " , *b);
	printf(" **c = %d \n" , **c);
	return 0;
}


// c ->  holds the address of B
// *c -> stores the address of the variable that B points to
// **c -> value of the variable that B points to
