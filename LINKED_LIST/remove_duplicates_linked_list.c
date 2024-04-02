# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


// This program removes duplicates from a sorted linked list 


typedef struct Node {
	struct Node *next;
	int data;
}node;


void InsertNode(node **head , int data)
{
	if(*head == NULL)
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = NULL;
		*head = temp;
	}
	else
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = *head;
		*head = temp;
	}
}


void Display(node *head)
{
	node *temp = head;
	if(temp == NULL)
	{
		printf("Nothing to be displayed! \n ");
	}
	else
	{
		while(temp!=NULL)
		{
			printf(" %d " , temp->data);
			printf(" --> ");
			temp = temp->next;
		}
		printf("\n");
	}
}


void RemoveDuplicates(node **head)
{
	if((*head == NULL) || ((*head)->next == NULL))
	{
		printf("Not enough elements to perform this operation!\n");
	}
	else
	{
		node *temp = *head;
		while((temp!=NULL) && (temp->next!=NULL))
		{
			while((temp->next!=NULL) && (temp->data == temp->next->data))
			{
				node *remove = temp->next;
				temp->next = temp->next->next;
				free(remove);
			}
			temp = temp->next;
		}
	}
}




int main(void)
{
	//printf("Hello World! \n ");
	node *head = NULL;
	//InsertNode(&head , 1);
	//InsertNode(&head , 1);
	InsertNode(&head , 8);
	InsertNode(&head , 5);
	InsertNode(&head , 7);
	InsertNode(&head , 3);
	InsertNode(&head , 2);
	InsertNode(&head , 2);

	InsertNode(&head , 1);
	InsertNode(&head , 1);
	InsertNode(&head , 1);
		
	RemoveDuplicates(&head);	
	Display(head);
	return 0;
}
