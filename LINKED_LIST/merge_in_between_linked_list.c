# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


typedef struct Node 
{
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
		node *temp = *head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = (node*)malloc(sizeof(node));
		temp->next->data = data;
		temp->next->next = NULL;
	}
}


void DeleteNode(node **head)
{
	if(*head == NULL)
	{
		printf(" Nothing to be deleted! \n ");
	}
	
	else if((*head)->next == NULL)
	{
		*head = NULL;
		free(*head);
	}
	else
	{
		node *temp = *head;
		while(temp->next->next!=NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}


void Display(node *head)
{
	if(head == NULL)
	{
		printf(" Nothing to be displayed! \n ");
	}
	else
	{
		node *temp = head;
		while(temp!=NULL)
		{
			printf(" %d " , temp->data);
			printf(" -> ");
			temp = temp->next;
		}
		printf(" \n ");
	}
}


int GetCount(node *head)
{
	int count = 0;
	if(head == NULL)
		return 0;
	else
	{
		node *temp = head;
		while(temp!=NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
}


void MergeInBetween(int a , int b , node **head , node **head2)
{
	int count = GetCount(*head);

	if(((b-a) <= 0) || ((b > count) && (a > count)) || ((b-a) > 1))
	{
		printf(" Invalid arguments provided! \n ");
	}
	else if((*head) == NULL || (*head)->next == NULL || *head2 == NULL)
	{
		printf(" Too few elements in the list! \n ");
	}
	
	else
	{
		int counter = 0;
		node *temp = *head;
		while(counter!=a-1)
		{
			temp = temp->next;
			counter++;
		}
		node *temp2 = temp->next;

		temp->next = *head2;

		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = temp2;
		
	}
}


int main(void)
{
	//node *head = (node*)malloc(sizeof(node));
	node *head = NULL;
	node *head2 = NULL;
	InsertNode(&head , 100);
	InsertNode(&head , 200);
	InsertNode(&head , 300);
	InsertNode(&head , 400);
	InsertNode(&head , 500);
	

	InsertNode(&head2 , 600);
	InsertNode(&head2 , 700);
	InsertNode(&head2 , 800);
	InsertNode(&head2 , 900);
	InsertNode(&head2 , 280);

	Display(head);
	Display(head2);


	MergeInBetween(3  , 4 , &head , &head2);

	printf(" \n ");
	printf(" \n ");
	Display(head);
	return 0;
}
