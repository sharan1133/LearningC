# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


// Reorder linked list such that 
// Eg : 1->2->3->4
// Solution : 1->4->2->3


typedef struct Node {
	struct Node *next;
	int data;
}node;



void Insert(node **head , int data)
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
	if(head == NULL)
		printf("Nothing to be displayed!\n");
	else
	{
		node *temp = head;
		while(temp!=NULL)
		{
			printf(" %d " , temp->data);
			printf(" -> ");
			temp = temp->next;
		}
		printf("\n");
	}
}



void Reorder(node **head)
{
	if(*head == NULL)
		printf("Not enough elements!\n");
	else
	{

		// Find middle of List

		node *fast = *head;
		node *slow = *head;

		while((fast!=NULL) && (fast->next!=NULL))
		{
			fast = fast->next->next;
			slow = slow->next;
		}


		

		node *second = slow->next;
		slow->next = NULL;

		// Reverse List 
		
		node *prev = NULL;
		node *temp = NULL;
		while(second!=NULL)
		{
			temp = second->next;	
			second->next = prev;
			prev = second;
			second = temp;
		}


		// Reorder list 

		
		node *start = *head;
		node *end = prev;
		while(end!=NULL)
		{
			node *fr = start->next;
			node *lr = end->next;

			start->next = end;
			end->next = fr;

			//lr->next = NULL;

			start = fr;
			end= lr;
		}


	}



}









int main(void)
{
	node *head = NULL;
	Insert(&head , 10);
	Insert(&head , 7);
	Insert(&head , 5);
	Insert(&head , 3);
	Insert(&head , 1);
	Display(head);
	//printf("Hello World!\n");
	Reorder(&head);
	Display(head);
	return 0;
}
