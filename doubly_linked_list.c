# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct Node
{
	struct Node *next;
	struct Node *prev;
	int data;
}node;

//behavior implemented is from the front

void Insert(int value);
void Delete();
void Display();


node *head = NULL;

int main(void)
{
	Insert(10);
	Insert(20);
	Insert(30);
	Insert(40);
	Insert(50);
	Display();
	Delete();
	Display();
	Delete();
	Display();
	Delete();
	Display();
	Delete();
	Display();
	Delete();
	Display();
	return 0;
}


void Insert(int value)
{
	if(head == NULL)
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = value;
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
	}
	else
	{
		node *temp = (node*)malloc(sizeof(node));
                temp->data = value;
		temp->next = head;
		temp->prev = NULL;
		head = temp;
        }
}


void Delete()
{
	if(head == NULL)
	{
		printf(" Cannot delete from Empty List! \n ");
	}
	else if(head->prev == NULL && head->next ==NULL)
	{
		head = NULL;
	}
	else
	{
		node *temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
	}
}



void Display()
{
	if(head == NULL)
	{
		printf(" Empty List! Nothing to be displayed! \n ");
	}
	else
	{
		node *temp = head;
		while(temp!=NULL)
		{
			//printf(" -> ");
			printf(" %d " , temp->data);
			printf(" -> ");
			temp = temp->next;
		}
		printf("\n");
	}
}
