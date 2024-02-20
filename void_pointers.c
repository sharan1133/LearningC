# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


typedef struct Node
{
	void *next;
	int data;
}node;

int main(void)
{
	/*void *ptr;
	int a = 100;
	ptr = &a;
	printf(" %d \n "  , a);
	printf(" %d \n " , *(int*)ptr);*/
	
	/*node *ptr = (node*)malloc(sizeof(node));
	ptr->data = 100;
	ptr->next = (node*)malloc(sizeof(node));
	((node*)ptr->next)->data = 200;
	printf(" %d \n " , ptr->data);
	printf(" %d \n " , ((node*)ptr->next)->data);
        free(ptr->next);
        free(ptr);*/

	node *ptr = malloc(sizeof(node));
	ptr->data = 550;

	node *temp = malloc(sizeof(node));

	ptr->next = temp;
        ((node*)ptr->next)->data = 600;
	printf(" %d \n " , ptr->data);
	printf(" %d \n " , ((node*)ptr->next)->data);
	free(ptr);
	free(temp);
	return 0;
}
