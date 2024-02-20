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
void Reverse();
void CustomDisplay(node *ptr);
int GetCount();
void InsertAtFront(int value);
void Delete();
void DeleteFromLast();
void Display();

int main(void)
{
       	
	Insert(110);
        Display();
	Delete();
	Display();
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
	//printf("Head value from display func : %d \n" , head->data);
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


int GetCount()
{
	if(head == NULL)
	{
		return 0;
	}

	else
	{
		int count = 0;
		node *temp = head;
		while(temp!=NULL)
	       {
		       count++;
		       temp = temp->next;
	       }
	       return count;
	}
}


void CustomDisplay(node *ptr)
{
	if(ptr == NULL)
		printf("Nothing to be displayed!\n");
	else
	{
		while(ptr!=NULL)
		{
			printf("->");
			printf(" %d " , ptr->data);
			ptr = ptr->next;
		}
                printf("\n");
	}
}

void Reverse()
{
    int count = GetCount();
    node *temp = head;
    //printf("Head value from beginning of reverse func : %d \n" , head->data);
    while(temp!=NULL)
    {
 	    InsertAtFront(temp->data);	
	    temp = temp->next;
    }
    
    for(int i = 0 ; i < count ; i++)
    {
	DeleteFromLast();
    }

    

}
