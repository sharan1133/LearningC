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
	cols temp;
	
	//cols columns[3] = {"x" ,"y" ," z"};

}df;

int main(void)
{
	//cols temp = z;
	cols array[2] = {x , z};
	printf(" %d \n " , array[1]);
	return 0;
}
