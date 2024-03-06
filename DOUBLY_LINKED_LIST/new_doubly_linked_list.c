# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <assert.h>

typedef struct Node 
{
	struct Node *next;
	struct Node *prev;
	int data;
}node;


void InsertAtFront(node **head , int value)
{
	if(*head == NULL)
	{
		node *temp = (node*)malloc(sizeof(node));	
		temp->data = value;
		temp->next = NULL;
		temp->prev = NULL;
		*head = temp;
	}
	else
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = value;
		temp->next = *head;
		temp->prev = NULL;
		(*head)->prev = temp;
		*head = temp;
	}
}


void DeleteAtFront(node **head)
{
	if(*head == NULL)
		printf("List is empty! \n ");
	else
	{
		node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
	

void Display(node *head)
{
	if(head == NULL)
		printf("List is empty! Nothing to be displayed! \n");
	else
	{
		node *temp = head;
		while(temp!=NULL)
		{
			printf("  %d  " , temp->data); 
			printf(" --> ");
			temp = temp->next;
		}
		printf("\n");
	}
}


void InsertAtLast(node **head , int value)
{
	if(*head == NULL)
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = value;
		temp->next = NULL;
		temp->prev = NULL;
		*head = temp;
	}
	else
	{
		//node *temp = (node*)malloc(sizeof(node));
		node *temp = *head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = (node*)malloc(sizeof(node));
		temp->next->data = value;
		temp->next->prev = temp;
		temp->next->next = NULL;

	}
}


void DeleteAtLast(node **head)
{
	if(*head == NULL)
		printf("List is Empty!Nothing to be deleted!\n");
	
	else if(((*head)->next == NULL) && ((*head)->prev == NULL))
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




void InsertAtPos(node **head , int value , int pos)
{
	int count = GetCount(*head);

	if(pos > count || pos < 0)
		printf(" Invalid position entered! \n ");
	else
	{
		if((pos == 0) || (pos == 1))
		{
			//node *temp = *head;
			InsertAtFront(&(*head), value);
		}
		else
		{
			node *temp = *head;
			int check = 0;
			while((temp->next!=NULL) && (check!=pos-2))
			{
				check++;	
				temp = temp->next;
			}
			node *temp2 = temp->next;
			temp->next = (node*)malloc(sizeof(node));
			temp->next->data = value;
			temp->next->next = temp2;
			temp->next->prev = temp;
		}
	}
}



void DeleteAtPos(node **head , int pos)
{
	int count = GetCount(*head);
	if(pos > count || pos < 0)
		printf(" Invalid position entered! \n ");
	else
	{
		if((pos == 0) || (pos == 1))
			DeleteAtFront(&(*head));
		else if(pos == count)
			DeleteAtLast(&(*head));
		else
		{
			int check = 0;
			node *temp = *head;
			
			/*do 
			{
				check++;
				temp = temp->next;
			}while((temp->next!=NULL) && (check!=pos-2)); */

			while((temp->next!=NULL) && (check!=pos-2))
			{
				check++;
				temp = temp->next;
			}

			node *temp2 = temp->next;
			temp->next = temp2->next;
			temp->next->prev = temp;
			free(temp2);

		}
	}
}


void CleanUp(node *head)
{
	if(head == NULL)
		printf("Exiting func! \n ");
	else
	{
		node *temp = head;
		while(temp!=NULL)
		{
			node *temp2 = temp;
			temp = temp->next;
			free(temp2);
		}
		printf("CleanUp Done \n ");
	}
}


/*int main(void)
{
	node *head = NULL;
	InsertAtLast(&head , 10);
	InsertAtLast(&head , 20);
	InsertAtLast(&head , 30);
	//InsertAtLast(&head , 40);
	//InsertAtLast(&head , 50);
	Display(head);
	InsertAtPos(&head , 68 , 2); 
	Display(head);
	InsertAtPos(&head , 75 , 4);
	Display(head);
	printf("Deleting element at pos : 2 \n ");
	DeleteAtPos(&head ,2);
	Display(head);
	printf("Deleting element at pos :1 \n ");
	DeleteAtPos(&head , 1);
	Display(head);
	DeleteAtLast(&head);
	Display(head);
	DeleteAtLast(&head);
	Display(head);
	DeleteAtLast(&head);
	Display(head);
	DeleteAtLast(&head);
	Display(head);
	DeleteAtLast(&head);
	Display(head);
	free(head); 
	//CleanUp(head);
	return 0;
}*/
