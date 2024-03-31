# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct Node 
{
	struct Node *next;
	int data;
}node;

void InsertAtEnd(node **head , int value)
{
	if(*head  == NULL)
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = value;
		temp->next = NULL;
		*head  = temp;
	}
	else
	{
		node *temp = *head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = (node*)malloc(sizeof(node));
		temp->next->data = value;
		temp->next->next = NULL;
	}
}

void Insert(node **head , int value)
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
	if(head == NULL)
		printf("Empty List! \n ");
	else
	{
		node *temp = head;
		while(temp!=NULL)
		{
			printf(" %d "  , temp->data);
			printf(" --> ");
			temp = temp->next;
		}
		printf(" \n ");
	}
}


int GetCount(node *head)
{
	if(head == NULL)
		return 0;
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

void SortList(node **head)
{
	if(*head == NULL)
		printf(" Empty List! \n ");
	else if((*head)->next == NULL)
		printf(" Cannot sort when only one element is present!");
	else
	{
		int count = GetCount(*head);	
		
		node *temp = *head;
		int arr[count];	

		for(int i = 0 ; i < count ; i++)
		{
			arr[i] = temp->data;
			temp->data = 0;
			temp = temp->next;
		}

		for(int i = 1 ; i < count ; i++)
		{
			int key = arr[i];
			int j = i-1;

			while(j>=0 && arr[j] > key)
			{
				arr[j+1] = arr[j];
				j = j-1;
			}
			arr[j+1] = key;	
		}		

		node *temp2 = *head;
		for(int i = 0 ; i < count ; i++)
		{
			temp2->data = arr[i];
			temp2 = temp2->next;
		}
		//Display(*head);
	}

}


node* MergeSortedLists(node **first , node **second)
{
	if((*first == NULL) && (*second == NULL))
		printf(" Invalid Input! ");
	
	else if((*first == NULL) || (*second == NULL))
	{
		printf(" One of your provided lists are empty! Do not waste my time! \n ");
	}
	else
	{

	node *new = NULL; 
	node *list1 = *first;
	node *list2 = *second;
	while((list1)!=NULL && ((list2)!=NULL))
	{
		if((list1->data) < (list2->data))
		{
			InsertAtEnd(&new , list1->data);
			list1 = list1->next;
		}
		else if((list1->data) == (list2->data))
		{
			InsertAtEnd(&new , list1->data);
			list1 = list1->next;
			list2 = list2->next;
		}
		else
		{
			Insert(&new , list2->data);
			list2 = list2->next;
		}
	}

	if(list1!=NULL || list2!=NULL)
	{
		if(list1!=NULL)
		{
			while(list1!=NULL)
			{
				InsertAtEnd(&new , list1->data);
				list1 = list1->next;
			}
		}
		
		else
		{
			while(list2!=NULL)
			{
				InsertAtEnd(&new , list2->data);
				list2 = list2->next;
			}
		}
		
	}
	return new;
      }
}

int main(void)
{
	node *head = NULL; 
	InsertAtEnd(&head , 10);
	InsertAtEnd(&head , 20);
	InsertAtEnd(&head , 30);
	//InsertAtEnd(&head , 40);
	//InsertAtEnd(&head , 1);
	//InsertAtEnd(&head , 98);
	Display(head);
	//printf(" \n");
	printf(" List after sorting! \n ");
	printf(" \n ");
	SortList(&head);
	Display(head);
	printf(" \n ");
	printf(" \n ");
	printf(" Creating second list!! \n ");
	printf(" \n ");
	printf(" \n ");
	//printf(" Count of elements is : %d \n " , GetCount(head));
	node *secondlist = NULL; 
	Insert(&secondlist , 65);
	InsertAtEnd(&secondlist , 73);
	Insert(&secondlist , 81);
	//Insert(&secondlist , 64);
	//Insert(&secondlist , 3);
	//Insert(&secondlist , 856);
	Display(secondlist);
	printf(" \n");
	printf(" List after sorting! \n ");
	printf(" \n ");
	SortList(&secondlist);
	Display(secondlist);	
	printf(" \n \n ");
	printf(" Displaying merged list! \n ");
	node *check = MergeSortedLists(&head , &secondlist);
	Display(check);
	return 0;
}
