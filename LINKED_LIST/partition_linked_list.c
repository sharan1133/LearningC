# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "HEADERFILES/linked_list.h"


// Given the head of a linked list and a value x partition it such that all nodes less than x come before nodes greater than or equal to x 



node* PartitionedList(node **head , int x)
{
	if(*head == NULL)
		printf("Not enough elements for this operation!\n");
	else
	{
		node *left = NULL;
		node *right = NULL;
		node *temp = *head;

		while(temp!=NULL)
		{
			if(temp->data < x)
				InsertAtEnd(&left ,  temp->data);	
			else
				InsertAtEnd(&right , temp->data);
			temp = temp->next;
		}

		//Display(left);
		//Display(right);

				

		node *temp2 = left;
		while(temp2->next!=NULL)
		{
			temp2 = temp2->next;
		}


		temp2->next = right;
		return left;


	}
}









int main(void)
{
	node *head = NULL;
	InsertAtEnd(&head , 1);
	InsertAtEnd(&head , 4);
	InsertAtEnd(&head , 3);
	InsertAtEnd(&head , 2);
	InsertAtEnd(&head , 5);
	InsertAtEnd(&head , 2);
	Display(head);
	node *new = PartitionedList(&head , 3);
	Display(new);
	//int c = GetCount(head);
	//printf("Count : %d \n " , c);
	//printf("Hello World!\n");
}
