# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

/// Check if a linked list is palindrome

typedef struct Node {
	int data;
	struct Node *next;
}node;


void Insert(node** head , int data)
{
	if((*head == NULL))
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
	node *temp = head;
	if(temp == NULL)
		printf("Nothing to be displayed! \n ");
	else
	{
		while(temp!=NULL)
		{
			printf(" %d " , temp->data);
			printf(" --> ");
			temp = temp->next;
		}
		printf("\n");
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

bool CheckPalindrome(node *head)
{
	node *temp = head;
	if((temp == NULL) || (temp->next == NULL))
	{
		printf("Not enough elements! \n ");
		return false;
	}
	int count = GetCount(head);

	int array[count];
	int size = sizeof(array)/sizeof(array[0]);

	int left = 0;
	int right = size-1;

	for(int i = 0 ; i < count ; i++)
	{
		array[i] = temp->data;
		temp = temp->next;
	}
	
	while(left <= right)
	{
		if(array[left]!=array[right])
			return false;
		else
		{
			left++;
			right--;
		}

	}
	return true;


}



int main(void)
{
	node *head = NULL;
	Insert(&head , 1);
	Insert(&head , 1);
	Insert(&head , 1);
	Display(head);
	bool result = CheckPalindrome(head);
	printf(" %d \n " , result);
	printf("Hello! \n ");
	return 0;
}
