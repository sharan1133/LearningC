# include <stdio.h>
# include <stdlib.h>


# define ROW 3
# define COLUMN 3


int* Create2DArray(int row , int column)
{
	int no_of_elements = row * column;

	int *ptr = (int*)malloc(no_of_elements * sizeof(int));

	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < column ; j++)
		{
			//*(*(ptr + i) + j) = 0;
			ptr[i * column + j] = 0;
		}
	}

	return ptr;
}


int main(void)
{

	int *temp = Create2DArray(2 , 3);

	int array[ROW][COLUMN];

	for(int i = 0 ; i < ROW ; i++)
	{
		for(int j = 0 ; j < COLUMN ; j++)
		{
			*(*(array + i) + j) = 10 + i;
		}
	}

	
	for(int i = 0 ; i < 2 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			printf(" array[%d][%d] = %d \n " , i , j , temp[i * 3 + j]);
		}
	}

	return 0;
}
