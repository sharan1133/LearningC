# include <stdio.h>
# include <stdlib.h>


int Void()
{
	//printf("Hello\n");
	return 19.282917;
}

int main(void)
{
	//int value = Void();


		

	void *ptr = malloc(20);
	(*(int*)ptr) = 10;
	int *new_ptr  = ((int*)ptr) + 1;	
	
	(*(int*)new_ptr) = 20;

	int *new_ptr_2 = ((int*)ptr) + 2;

	int *new_ptr_3 = ((int*)ptr) + 3;

	int *new_ptr_4 = ((int*)ptr) + 4;

	int *new_ptr_5 = ((int*)ptr) + 5;
	printf(" %d \n " , new_ptr);
	printf(" %d \n " , new_ptr+1);
	printf(" %d \n " , new_ptr+2);
	printf(" %d \n " , new_ptr+3);
	printf(" %d \n " , new_ptr+4);
	printf(" %d \n " , new_ptr+5);
	//printf(" Size of pointer variable : %d \n " , sizeof(ptr));
	//printf(" Address of pointer variable : %d \n " , &ptr);

	//printf(" Address of variable pointer variable points to : %d \n " , ptr);
	//printf(" %d \n " , new_ptr);
	//printf(" Value stored in address pointer variable points to : %d \n " , *(int*)ptr);
	//printf(" Size of value stored in allocated space : %d \n " , sizeof(*(int*)ptr));		
	
	////printf(" %d \n "  , value);
	////printf("Hello");
	return 0;
}
