# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


int main(void)
{
	void *ptr;
	int a = 100;
	ptr = &a;
	printf(" %d \n "  , a);
	printf(" %d \n " , *(int*)ptr);
	return 0;
}
