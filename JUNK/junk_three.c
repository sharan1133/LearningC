# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


typedef struct Node 
{
	struct Node *next;
	int data;
	//int array[10];
	struct Node* storage[10];
	//struct Node structures[10];
}node;



int main(void)
{
		node *temp = (node*)malloc(sizeof(node));
		for(int i = 0 ; i < 10 ; i++)
		{
			temp->storage[i] = (node*)malloc(sizeof(node));
			temp->storage[i]->data = 750;
			temp->storage[i]->next = NULL;
			printf(" temp->storage[%d]->data = %d \n "  , i  , temp->storage[i]->data); 
		}
			
		return 0;
}
