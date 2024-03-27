# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct 
{
	int arr[10];
	int count;
}Temp;


# define testmacro(a , b) \ 
            c = a+b; \
	    printf(" %d \n " , c); \


int main(void)
{
	int a  = 10;
	int b = 20;

	int c;

	testmacro(a , b);
	//int a = 10;
	//int *ptr = &a;
	//printf(" Size of int : %d \n " , sizeof(a));
	//printf(" Size of pointer to int : %d \n " , sizeof(ptr));

	//char var = 's';
	//char *tovar = &var;
	//printf(" Size of char : %d \n " , sizeof(var));
	//printf(" Size of pointer to char : %d \n " , sizeof(tovar));
	
	//Temp t1 = {0};
	//t1.count = 3;
	//Temp *ptrtot1 = &t1;
	//printf(" %d \n " , ptrtot1->count);
	//printf("Size of struct : %d \n " , sizeof(t1));
	//printf("Size of pointer to struct : %d \n " , sizeof(ptrtot1));
	//size_t temp = 1;
	//printf(" %zu \n " , temp);
	//printf(" %d \n " , sizeof(temp));

  	
	//int *alloc = malloc(sizeof(int));
	//int *alloc = calloc(10 , sizeof(int));
	//*alloc = 18;
	//alloc = realloc(alloc , 10 * sizeof(int));
	//printf(" %d \n "  , *alloc);
	//for(int i = 0 ; i < 10 ; i++)
		//alloc[i] = 70;
		//*(alloc + i) = 15;

        //for(int i = 0 ; i < 10 ; i++)
                //printf(" %d \n " , *(alloc + i));
	
	
	//int *alloc = malloc(sizeof(int) * 10);
	//int *alloc = calloc(10 , sizeof(int));
	//for(int i = 0 ; i < 10 ; i++)
		//printf( " %d \n "  , *(alloc + i));
	
	
	return 0;
}
