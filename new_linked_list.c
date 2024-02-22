# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct Node
{
	struct Node *next;
	int data;
}node;



node* CreateNode(void)
{
	node *temp = NULL;
	return temp; 
}



void Insert(node **ptrttohead , int value)
{
	if(*ptrttohead == NULL)
	{
		*ptrttohead = (node*)malloc(sizeof(node));

		(*ptrttohead)->data = value;
		(*ptrttohead)->next = NULL;

	}
	else
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = value;
		temp->next = *ptrttohead;
		*ptrttohead = temp;
	}
}

void Display(node **ptrttohead)
{
	if(*ptrttohead == NULL)
		printf(" Nothing to be displayed! \n");
	else
	{
		node *temp = *ptrttohead;
		while(temp!=NULL)
		{
			printf(" %d " , temp->data);
			printf(" -> ");
			temp = temp->next;
		}
		printf(" \n ");
	}
}


void Delete(node **ptrttohead)
{
	if(*ptrttohead == NULL)
		printf(" Nothing to be deleted! \n ");
	else
	{
		node *temp = *ptrttohead;
		*ptrttohead = (*ptrttohead)->next;
		free(temp);
	}
}

void CleanUp(node *head)
{
	while(head!=NULL)
	{
		node *temp = head;
		head = head->next;
		free(temp);
	}
}

int main(void)
{
	node *head = NULL;
	Insert(&head , 10);
	Insert(&head , 20);
	Insert(&head , 30);
	Display(&head);
	Delete(&head);
	Display(&head);
	Delete(&head);
	Display(&head);
	Delete(&head);
	Display(&head);
	CleanUp(head);
	return 0;
}

