# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct Node 
{
	struct Node *next;
	int data;
}node;



int main(void)
{
	node* NODES[10];
	for(int i = 0 ; i < 10 ; i++)
	{
		NODES[i] = (node*)malloc(sizeof(node));
		NODES[i]->data = i+570;
		//temp->data = i+100;
	}

	for(int i = 0 ; i < 10 ; i++)
	{
		printf(" %d \n " , NODES[i]->dat);
	}
	printf(" Hello World! \n ");
	return 0;
}
