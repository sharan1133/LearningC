# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


/*typedef struct Block
{
		
}*/


typedef struct Node 
{
	struct Node *next;
	int data;
	int data2;
	float j;
}node;


int main(void)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->j = 27272.52;
	temp->data = 8;
	temp->data2 = 821;
	temp->next = (node*)malloc(sizeof(node));
	//printf(" Size of Node : %d \n " , sizeof(node));
	//printf(" %d \n " , sizeof(temp));
	//printf(" %d \n " , temp+1);
	node *temp2 = temp+1; 

	//printf(" %d \n " , temp);
	//printf(" %d \n " , temp2);
	//printf(" %d \n " , temp->next);
	

	printf(" Size of temp : %d \n " , sizeof(temp));
	printf(" Size of temp2 : %d \n " , sizeof(temp2));
	printf(" Size of temp->next : %d \n " , sizeof(temp->next));



	free(temp->next);
	free(temp);
	return 0;
}
