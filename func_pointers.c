# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


void temp();

int main(void)
{
	//printf("%p \n " , &temp);
	void (*ptr)() = &temp;
	ptr();
	//printf(" %s \n " , *ptr);
	return 0;
}


void temp()
{
	printf("temporary func!\n");
}
