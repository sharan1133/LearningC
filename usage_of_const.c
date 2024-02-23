# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

int main(void)
{
	const int varA = 150;
	//const int *ptr = &varA;
	int* const ptr = &varA;	
	*ptr = *ptr + 700;
	const int varB = 800;
	//ptr = &varB;
	//*ptr = 151;
	printf(" %d \n " , *ptr);
	return 0;
}
