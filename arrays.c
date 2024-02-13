# include <stdio.h>
# include <stdlib.h>

# define NUM 10

void printArray(int arr[], int size);
int* CreateArray(int size);
int* ResizeArray(int arr[] , int size);

int main(int argc , char* argv[])
{
	
	int* arr = CreateArray(5);
	printArray(arr , 5);
	arr = ResizeArray(arr , 10);
	printArray(arr , 10);
	free(arr);
       	return 0;
}


int* CreateArray(int size)
{
	int* Array = calloc(size , sizeof(int));
	return Array;

}


void printArray(int arr[], int size)
{
	for(int i = 0 ; i < size ; i++)
		printf(" %d " , *(arr+i));
	printf("\n");
}

int* ResizeArray(int arr[] , int size)
{
     int* Array = realloc(arr , size * sizeof(int));
     return Array;
}
