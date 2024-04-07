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


void IsPalindrome(node** head)
{
	if(*head == NULL)
		printf("Empty List!\n");
	else
	{
		node *fast = *head;
		node *slow = *head;
		
		while((fast!=NULL) && (fast->next!=NULL))
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//printf(" Fast : %d \n "  , fast->data); 
		//printf(" Slow : %d \n "  , slow->data);

		// Reverse second half
		
		node *prev = NULL;
	
		while(slow!=NULL)
	  	{
			node *temp = slow->next;
			slow->next = prev;
			prev = slow;
			slow = temp;
		}


		node *left  = *head;
		node *right = prev;

		while(right!=NULL)
		{
			if(left->data != right->data)
			{
				printf(" Not palindrome!\n ");
				return;
			}
			else
			{
				left = left->next;	
				right = right->next;
			}
		}
		printf(" Is a palindrome! \n ");
				
	}
}




int main(void)
{
	node *head = NULL;
	//Insert(&head , 8);
	Insert(&head , 2);
	Insert(&head , 1);
	Insert(&head , 2);
	Insert(&head , 1);
	Insert(&head , 4);
	Display(head);
	//bool result = CheckPalindrome(head);
	//printf(" %d \n " , result);
	IsPalindrome(&head);
	//printf("Hello! \n ");
	free(head);
	return 0;
}
