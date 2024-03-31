# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>


typedef struct Node {
	struct Node *next;
	int data;
}node;


void Insert(node** head , int value)
{
	if(*head == NULL)
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = value;
		temp->next = NULL;
		*head = temp;
	}
	else
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = value;
		temp->next = *head;
		*head = temp;
	}
	
}


void Display(node *head)
{
	node *temp = head;
	if(temp == NULL)
		printf("Nothing to be displayed! \n ");
	else
	{
		while(temp!=NULL)
		{
			printf("  %d  " , temp->data); 
			printf(" --> ");
			temp = temp->next;
		}
		printf(" \n ");
	}
}


node* MiddleNodePtr(node** head)
{
	node *fast = *head;
	node *slow = *head;

	while((fast!=NULL) && (fast->next!=NULL))
	{
		fast = fast->next->next; 
		slow = slow->next;
	}
	printf(" Middle Element : %d \n " , slow->data);
	return slow;

}


int main(void)
{
	node *head = NULL;	
	Insert(&head , 20);
	Insert(&head , 30);
	Insert(&head , 40);
	Insert(&head , 15);
	Insert(&head , 28298);
	Insert(&head , 17);
	//Insert(&head , 44637);
	Display(head);
	node *middle = MiddleNodePtr(&head);
	return 0;
}
