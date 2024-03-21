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


	df data1[3] = {{"hello" , 133 , 1.4} , 
			{"hello1" , 142 , 1.2},
			{"hello2" , 19 , 1.2}};

	printf(" %s \n " , data1[1].name);

	//printf(" Name   \t  ");
	//printf(" Age   \t  ");
	//printf(" Height  ");
	//printf(" \n ");
	/*for(int i = 0 ; i < 2 ; i++)
	{
		for(int j = 0 ; j < 1 ; j++)
			
		{
			printf(" %s \t " , data[i][j].name);
			printf(" %d \t " , data[i][j].age);
			printf(" %f \t " , data[i][j].height);

		}
		printf(" \n ");
	}*/
	return 0;
}
