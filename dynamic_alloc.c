# include <stdio.h>
# include <stdlib.h>


int main(void)
{
	int* array = malloc(sizeof(int)*10);
        
	//int* array2 = calloc(15 , sizeof(int));

	for(int i = 0 ; i < 10 ; i++)
		*(array + i) = 100 + i;

	/*for(int i = 0 ; i < 10 ; i++)
		printf(" %d \n " , *(array + i));*/
        array = realloc(array , 20 * (sizeof(int)));
	for(int i = 0 ; i < 20 ; i++)
		printf(" %d \n" , *(array + i));

	//free(array2);
	free(array);
	return 0;
}
