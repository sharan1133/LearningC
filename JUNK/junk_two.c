# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


typedef struct Employee
{
	char name[30];
	int age;
}emp;

typedef struct Details 
{
	int id;
	emp employee;
	//struct Temp t6;
}details;


int main(void)
{
	details temp;
	temp.employee.age = 1000;
	//temp.employee.name = "John";
	char name[10] = "sharan";
	//name[10] = "sharan";
	for(int i = 0 ; i < 7 ; i++)
		temp.employee.name[i] = name[i];
	printf(" %d \n " , temp.employee.age);
	printf(" %s \n " , temp.employee.name);
	return 0;
}
