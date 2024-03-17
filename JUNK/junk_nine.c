# include <stdio.h>
# include <stdlib.h>


# define ROW 3
# define COLUMN 2


void PrintArray(int *array)
{
	for(int i = 0 ; i < ROW ; i++)
	{
		for(int j = 0 ; j < COLUMN ; j++)
		{
			printf(" array[%d][%d] = %d \n " , i , j , array[i * COLUMN + j]);
		}
	}
}






int main(void)
{
	int elements = ROW * COLUMN;
	int *array = (int*)malloc(elements * sizeof(int));
	*(array + 4) = 29;
	*(array + 5) = 28;
	
	/*for(int i = 0 ; i < ROW ; i++)
	{
		for(int j = 0 ; j < COLUMN ; j++)
		{
			printf(" array[%d][%d] = %d \n " , i , j, array[i*COLUMN + j]);
		}
	}*/
	PrintArray(array);
	free(array);
	return 0;
}
