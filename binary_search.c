# include <stdio.h>
# include <stdlib.h>




void FindElement(int array[] , int element , int start , int end)
{
	//int start = 0;
	
	while(start <= end)
	{
		int mid = (start + end) / 2;
		
		if(array[mid] == element)
		{
			printf("Element %d found at Pos %d \n " , element , mid);
			break;
		}
		else if(array[mid] > element)
			end = mid-1;
			//return FindElement(array , element , start , mid-1);	
		else

			start = mid + 1;
			//return FindElement(array , element , mid+1 , start);	
	}
}








int main(void)
{
	int array[] = {10  , 20  , 30 , 40 , 50};
	int size = sizeof(array)/sizeof(array[0]);
	FindElement(array , 50 , 0 , size-1);
	return 0;
}
