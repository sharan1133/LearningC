# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct DataFrame
{
	char name[10];
	int age;
	float height;
}df;


int main(void)
{
	df data[2][1] = {{"abc" , 10 , 1.2},
		{"xyz" , 11 , 1.3}};
	//printf(" %s \n "  , data[1][0].name);
	//printf(" %s \n " , data.name);

	
	//printf(" %s \n "  , data[0][0].name);


	printf(" Name   \t  ");
	printf(" Age   \t  ");
	printf(" Height  ");
	printf(" \n ");
	for(int i = 0 ; i < 2 ; i++)
	{
		for(int j = 0 ; j < 1 ; j++)
			
		{
			printf(" %s \t " , data[i][j].name);
			printf(" %d \t " , data[i][j].age);
			printf(" %f \t " , data[i][j].height);

		}
		printf(" \n ");
	}
	return 0;
}
