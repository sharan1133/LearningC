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
void Sort();
//void SortUsingInsertion();
void CustomDisplay(node *ptr);
int GetCount();
void InsertAtFront(int value);
void InsertAtPos(int value , int pos , int count);
void DeleteAtPos(int pos);
void Delete();
void DeleteFromLast();
void Display();

int main(void)
{
       	
	Insert(15);
	Insert(2);
	Insert(11);
	Insert(20);
	Insert(4);
	Display();
	Sort();
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


void InsertAtPos(int value , int pos , int count)
{
    //int count = GetCount(); 
   
    if(count > 0)
    { 	if(pos == 0)
    	{
		InsertAtFront(value);
    	}
    	else if(pos == count+1) 
    	{
		Insert(value);
    	}
    	else if(0 < pos <= count)
    	{
             	node *temp = head;
		int counter = 0;
		while(counter!=pos-2)
		{
			temp = temp->next;
			counter++;
		}
		//printf(" %d \n " , temp->data);
		node *temp2 = (node*)malloc(sizeof(node));
		temp2->data = value;
		temp2->next = temp->next;
		temp->next = temp2;	        	
   	}
	else
	{
		printf(" Invalid position! \n ");
	}
   }
   else
   {
	   printf(" Invalid Value Entered! \n ");
   }
}


void DeleteAtPos(int pos)
{
	int count = GetCount();
	if(pos > count || pos < 0)
		printf(" Invalid position entered! \n ");
	else
	{
                if(head == NULL)
		   printf(" Cannot delete from empty list! \n");
	        else if(pos == 0 || pos == 1)
		    Delete();

		else
		{
			node *temp = head;
			int counter = 0;
			while(counter!=pos-2)
			{
				temp = temp->next;
				counter++;
			}
			node *temp2 = temp->next;
			temp->next = temp2->next;
			free(temp2);
		}
	}
}


void Sort()
{
	int count = GetCount();
	int arr[count];
	node *temp = head;
	for(int i = 0 ; i < count ; i++)
	{
		arr[i] = temp->data;
		temp->data = 0;
		temp = temp->next;
	}

	int swap;
	/*for(int i = 0 ; i < count-1 ; i++)
	{
		for(int j = i+1 ; j < count ; j++)
		{
			if(arr[i] > arr[j])
			{
				swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
			}
		}
	}*/


	for(int i = 1 ; i < count ; i++)
	{
		int key = arr[i];
		int j = i-1;

		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;

		}
		arr[j+1] = key;
	}
	
	node *temp2 = head;
	for(int i = 0 ; i < count ; i++)
	{
		temp2->data = arr[i];
		temp2 = temp2->next;
	}

}




