# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>


int main(void)
{
	char str[11] = "Thisisastr";
	//printf(" %d \n " , strlen(str));
	int i = 0;
	char start;
        	
	while(start!='\0')
	{
		start = str[i];
		printf(" %c    " , start);
		i++;
		
	}
	printf("\n");

	for(int i = 0 ; i < strlen(str) ; i++)
		printf(" %c    " , str[i]);
	printf("\n");
	return 0;
}
