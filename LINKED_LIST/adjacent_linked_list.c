# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

// Swap adjacent nodes 
// i.e : 1->2->3->4 == 2 -> 1 -> 4 -> 3


typedef struct Node {
	struct Node *next;
	int data;
}node;


void Insert(node **head , int data)
{
	node *temp = (node*)malloc(sizeof(node));
	if(*head == NULL)
	{
		temp->data = data;
		temp->next = NULL;
		*head = temp; 
	}
	else
	{
		temp->data = data;
		temp->next = *head;
		*head = temp;
	}
}




void Display(node *head)
{
	if(head == NULL)
		printf("Nothing to be displayed! \n ");
	else
	{
		node *temp = head;
		while(temp!=NULL)
		{
			printf(" %d ", temp->data);
			printf(" -> ");
			temp = temp->next;
		}
		printf("\n");
	}
}


/*node* SwapNodes(node *head)
{
	if((head == NULL) || head->next == NULL)
		printf(" Not enough elements to perform this operation!\n");
	else
	{
		node *temp = head;
		node *dummy = head;
		//dummy->data = 0;	

		while((temp!=NULL) && (temp->next!=NULL))
		{
			//node *tmp1 = temp->next;
			node *tmp2 = temp->next->next;
			node *tmp1 = temp->next;

			//temp->next = tmp2;		
			//tmp1->next= temp;
			//dummy->next = tmp1;
			

			dummy->next = tmp1;
			tmp1->next = temp;
			temp->next = tmp2;
			//dummy->next = tmp1;

			
			dummy = temp;
			temp = tmp2; 
			//dummy = temp->next; 
			
		}
		return dummy;
		
	}
}*/


node* SwapNodes(node *head)
{
	if((head == NULL) || head->next == NULL)
		printf(" Not enough elements to perform this operation!\n");
	else
	{
		node *temp = head;
		node *dummy = NULL;

		while((temp!=NULL) && (temp->next!=NULL))
		{
			node *tmp2 = temp->next->next;
			node *tmp1 = temp->next;

			if (dummy != NULL)
				dummy->next = tmp1;
			else
				head = tmp1;

			tmp1->next = temp;
			temp->next = tmp2;

			dummy = temp;
			temp = tmp2;
		}
		return head;
	}
}




int main(void)
{
	node *head = NULL;	
	Insert(&head , 10);
	Insert(&head , 8);
	Insert(&head , 6);
	Insert(&head , 4);
	Insert(&head , 2);
	Insert(&head , 1);
	Display(head);
	node *swap = SwapNodes(head);
	Display(swap);
	//printf("Hello World!\n");
	return 0;
}
