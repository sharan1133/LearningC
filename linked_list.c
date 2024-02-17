# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>


typedef struct Node
{
	struct Node* next;
	int data;
}node;

node *head = NULL;

void Insert(int value);
//void Reverse();
void InsertAtFront(int value);
void Delete();
void DeleteFromLast();
void Display();

int main(void)
{
	//head = (node*)malloc(sizeof(node));
	//head->data = 100;
	//head->next = NULL;
	Insert(103);
	InsertAtFront(104);
	InsertAtFront(105);
	Display();
	//Delete();
	//Display();
	//DeleteFromLast();
        	
	//Insert(110);
	//Insert(111);
	//Insert(112);
	//Insert(113);
	//DeleteFromLast();
        //Display();
	//Delete();
	//Display();

	//DeleteFromLast();
	//Display();

	free(head);
	return 0;
}



void InsertAtFront(int value)
{
    if(head == NULL)
    {
	    head = (node*)malloc(sizeof(node));
	    head->data = value;
	    head->next = NULL;
    }
    else
    {
	    node *temp = (node*)malloc(sizeof(node));
	    temp->data = value;
	    temp->next = head;
            //head = head->next;
	    head = temp;
          
    }
}



void Insert(int value)
{
	if(head == NULL)
	{
		head = (node*)malloc(sizeof(node));
		head->data = value;
		head->next = NULL;
	}
	else
	{
		node *temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = (node*)malloc(sizeof(node));
		temp->next->data = value;
		temp->next->next = NULL;
	}
}





void Display()
{
	node *temp = head;
	if(temp == NULL)
	{
		printf("Empty List! \n");
	}
	else
	{
	      while(temp!=NULL)
	   {
		printf(" %d " , temp->data);
		printf("->");
		temp = temp->next;
	   }  
	      printf(" \n ");
        }
}

void Delete()
{
	node *temp = head;
	head = head -> next;
	free(temp);
}

void DeleteFromLast()
{
   	node *temp = head;
	while(temp->next->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	free(temp->next);
}
