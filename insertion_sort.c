# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


int main(int argc , char* argv[])
{
	int arr[] = { 100 , 1 , 62 , 0 , 76 , 999 , 42 , 10 , 60 , 104};

	int size = (sizeof(arr) / sizeof(arr[0]));
	for(int i = 1 ; i < size ; i++)
	{
		int key = arr[i];
		int j = i-1;

		while(j>=0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;

		}
		arr[j+1] = key;
	}

	for(int i = 0 ;i < size ; i++)
		printf( " %d    " , arr[i]);
	printf(" \n " );
	return 0;
}
