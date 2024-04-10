# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


typedef struct Node {
	struct Node *next;
	int data;
}node;



void Insert(node **head , int data)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	
	if(*head == NULL)
	{
		temp->next = NULL;
		*head = temp;
	}

	else
	{
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


node* RotateList(node **head , int k)
{
	if(*head == NULL)
		printf("Not enough elements for this operation!\n");
	else
	{
		int length  = 1;
		node *temp = *head;
		

		while(temp->next!=NULL)
		{
			length++;
			temp = temp->next;
		}

		//printf(" %d \n " , length);

		k = k % length;

		if(k == 0)
			return *head;
		else
		{
			node *curr = *head;
			for(int i = 0 ; i < length - k - 1 ; i++)
			{
				curr = curr->next;
			}

			node *newHead = curr->next;
			curr->next = NULL;

			temp->next = *head;
			return newHead;
		}
	}



}


int main(void)
{
	node *head = NULL;
	Insert(&head , 5);
	Insert(&head , 4);
	Insert(&head , 3);
	Insert(&head , 2);
	Insert(&head , 1);
	Display(head);
	node *new = RotateList(&head , 9);
	Display(new);
	//printf("Hello World!\n");
	return 0;
}
