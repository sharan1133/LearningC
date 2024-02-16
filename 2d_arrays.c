# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>



//void Display(int (*ptr)[] , int row , int col);
void Display(int row , int (*ptr)[] , int col);


int main(void)
{
	
        //int (*ptr)[3] = arr;

        int arr[3][3]  = {{ 300 , 301 , 302 }, 
		 {4 , 10 , 19},
		 {92 , 73 , 18}};	


	/*for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			printf(" %d   \n " , *(*(ptr + i) + j));
		}
	}*/
	//Display(arr, 3 , 3);
	Display(3 , arr , 3);
	return 0;
}


void Display(int row , int (*ptr)[row]  , int col)
{
	
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			printf("arr[%d][%d] = %d \n " , row , col , *(*(ptr + i) + j)); 
		}
	}
}
