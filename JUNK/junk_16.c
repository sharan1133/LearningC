# include <stdio.h>
# include <stdlib.h>

int sum(int x , int y)
{
	return x + y;
}

int sum2(int a , int g)
{
	return a + g;
}

int main(void)
{
	int (*funcptr)(int,int); 
	int a = 10;
	void *pt = &a;
	void *ptr = sum;
	//printf(" %d \n " , sum);
	//printf(" %d \n " , &sum);
	//printf(" %d \n " , *(int*)((int , int)*)ptr(10 + 20));
	printf(" %d \n " , funcptr(20 , 201));
	return 0;
}
