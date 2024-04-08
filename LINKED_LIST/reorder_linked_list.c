# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


// Reorder linked list such that 
// Eg : 1->2->3->4
// Solution : 1->4->2->3



typedef struct Node {
	struct Node *next;
	struct Node *prev;
	int data;
}node;



void Insert(node **head , int data)
{
	if(*head == NULL)
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
		*head = temp;
	}
	else
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
	}
}


void Display(node *head)
{
	if(head == NULL)
		printf("List is empty! Nothing to be displayed!\n");
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


void Reorder(node **head)
{
	if((*head == NULL) || ((*head)->next == NULL))
	{
		printf("Not enough elements to perform this operation! \n ");
	}
	else
	{
		node *temp = *head;
		node *temp2 = *head;

		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
	
		while()
		{
			node *tmp = temp->prev;	
			node *tmp2 = temp2->next;
			temp2->next = temp;
			temp->prev = temp2;
			temp->next = tmp2; 
			tmp->next = NULL;
			temp = tmp;
			temp2 = tmp2; 

		}

	}
}

int main(void)
{
	node *head = NULL;
	Insert(&head , 4);
	Insert(&head , 3);
	Insert(&head , 2);
	Insert(&head , 1);
	Display(head);
	Reorder(&head);
	printf("Hello World! \n ");
	return 0;
}
