# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct Node 
{
	struct Node *next;
	int data;
}node;


void Insert(node **ptr , int value);
void Delete(node **ptr);
void Display(node *ptr);
void CleanUp(node *ptr);

int main(void)
{
	node *head = NULL;

	Insert(&head , 10);
	Insert(&head , 20);
	Insert(&head , 30);
	Insert(&head , 40);
	Insert(&head , 50);
	Display(head);
	Delete(&head);
	Display(head);
	Delete(&head);
	Display(head);
	Delete(&head);
	Display(head);
	Delete(&head);
	Display(head);
	Delete(&head);
	Display(head);
	CleanUp(head);
	head = NULL;
	return 0;
}


void Delete(node **ptr)
{
	if(*ptr == NULL)
	{
		printf("Nothing to be deleted! \n ");
	}

	else if((*ptr)->next == *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}


	else
	{
		node *temp = *ptr;
		while(temp->next->next!=*ptr)
		{
			temp = temp->next;
		}
		//free(temp->next);
		node *dump = temp->next;
		temp->next = *ptr;
		free(dump);
	}
}


void Insert(node **ptr , int value)
{
	if(*ptr == NULL)
	{
		node *temp = (node*)malloc(sizeof(node));	
		temp->data = value;
		temp->next = temp;
		*ptr = temp;
		//head = *ptr;
	}
	else
	{
		node *temp = *ptr;
		while(temp->next!=*ptr)
		{
			temp = temp->next;
		}
		node *new = (node*)malloc(sizeof(node));
	        new->next = temp->next;	
		new->data = value;
		temp->next = new;
		
	}
}


void Display(node *ptr)
{
	if(ptr == NULL)
	{
		printf("Nothing to be displayed! \n");
	}
	else
	{
		node *temp = ptr;
		do
		{
			printf(" %d " , temp->data);
			printf(" --> ");
			temp = temp->next;
		}while(temp!=ptr);
		printf("\n");
	}
}


void CleanUp(node *ptr)
{
	if(ptr == NULL)
	{
		printf("List already empty! \n ");
	}
	else
	{

		node *head = ptr;	
	 	node *temp = ptr->next;
	
		while(temp!=head)
	 	{
			node *dump = temp;
			temp = temp->next;
			free(dump);
		}

		free(head);
	}
}
