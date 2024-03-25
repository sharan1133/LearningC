# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


typedef union Fields 
{
	int age;
	int temp;
	char name[11];
	float height;
}field;


int main(void)
{
	field temp = {0};
	//temp.name = "xyz";
	
	temp.age = 12;
	temp.height = 7.9;

	printf(" %d \n " , temp.age);
	printf(" %f \n " , temp.height);

	snprintf(temp.name ,  sizeof(temp.name) , "xyzxyzx");
	printf(" %s \n " , temp.name);
	return 0;
}
