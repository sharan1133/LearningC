# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>

int main(void)
{
	int* ptr = (int*)malloc(sizeof(int) * 11);
	int** ptr2 = (int**)calloc(5 , sizeof(int*));
	/*for(int i = 0 ; i < 11 ; i++)
		*(ptr + i) = 100 + i;
	for(int i = 0 ; i < 10 ; i++)
		printf(" %d  " , *(ptr+i));*/

	for(int i = 0 ; i < 5 ; i++)
	{
		*(ptr2 + i) = (int*)malloc(sizeof(int) * 3);
		for(int j = 0 ; j < 3 ; j++)
		{
			*(*(ptr2+i) + j) = 10;	
		}
	}


	for(int i = 0 ; i < 5 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			//*(*(ptr2+i) + j) = 10;	
			printf(" %d    " , *(*(ptr2+i) + j));  
		}
		printf("\n");
	}


	for(int i = 0 ; i < 5 ; i++)
	{
		
		int* temp = *(ptr2 + i);
		free(temp);
		
	}
	free(ptr2);
	printf("Clean Up complete!\n");

	printf("\n");
	return 0;
}
