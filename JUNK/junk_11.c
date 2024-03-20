# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


typedef enum COLUMNS
{
	x,
	y,
	z
}cols;




typedef struct DataFrame
{
	cols temp[3] = {x , y , z};
	int arrayj
	
	//cols columns[3] = {"x" ,"y" ," z"};

}df;

int main(void)
{
	//cols temp = z;
	//cols array[2] = {x , z};
	//printf(" %c \n " , array[1]);
	//printf(" %d \n " , array[1]);
	
	cols temp = y;
	printf(" %d \n " , temp);
	return 0;
}
