# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct  
{
	int age;
	char name[5];
}Student;

void printDetails(Student stu[] , int size);

int main(void)
{
	//struct Student stu;
	//Student stu;
	//stu.age = 10;
	Student students[5];
	for(int i = 0 ; i < 5 ; i++)
	{
		students[i].age = i+20;
		for(int j = 0 ; j < 5 ; j++)
		{
			students[i].name[j] = 'W';
		}
	}
	printDetails(students , 5);
	return 0;
}


void printDetails(Student stu[] , int size)
{
	for(int i = 0 ; i < size ; i++)
	{
		printf("Name : %s \n " , stu[i].name);
		printf("Age : %d \n" , stu[i].age);
	}
}
