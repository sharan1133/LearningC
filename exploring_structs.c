# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

struct Item 
{
	int a;
	int b;
};


int main(void)
{
	struct Item s1 = {0}; 
	printf( " %d \n " , s1.a);
	printf("  %d \n " , s1.b);
	return 0;
}
