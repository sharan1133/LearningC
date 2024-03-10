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
	temp->next = (node*)malloc(sizeof(temp));
	printf(" %d \n " , sizeof(node));
	printf(" %d \n " , sizeof(temp));
	printf(" %d \n " , temp);
	printf(" %d \n " , temp+1);
	node *(temp+1) = (node*)malloc(sizeof(node));
	free(temp->next);
	free(temp);
	return 0;
}
