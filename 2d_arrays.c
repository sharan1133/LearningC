# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


void Display(int** array , int row , int col);

int main(void)
{
	int array[10][10];

	for(int  i = 0 ; i < 10 ; i++)
	{
		for(int j = 0 ; j < 10 ; j++)
		{
			array[i][j] = 20+i+j;
		}
	}
	Display(array , 10 , 10);
	return 0;
}


void Display(int** array, int row , int col)
{
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			printf("arr[%d][%d] = %d \n " , row , col , array[row][col]); 
		}
	}
}
