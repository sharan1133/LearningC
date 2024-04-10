# ifndef LINKED_LIST 

# define LINKED_LIST


typedef struct Node {
	struct Node *next;
	int data;
}node;

void InsertAtBeginning(node **head , int data)
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


void InsertAtEnd(node **head , int data)
{
	node *temp = NULL; 
	temp->data = data;

	if(*head == NULL)
	{
		temp = (node*)malloc(sizeof(node));
		temp->next = NULL;
		*head = temp;
	}

	else
	{
		temp = *head;	
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		
		temp->next = (node*)malloc(sizeof(node));
		temp->next->next = NULL;

	}
}


void DeleteAtBeginning(node **head)

{
	if(*head == NULL)
		printf("Empty List! \n ");
	
	else if((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		node *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}


void DeleteAtEnd(node **head)
{
	if(*head == NULL)
		printf(" Empty List! \n ");
	
	else if((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
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


void Display(node *head)
{
	if(head == NULL)
		printf("Nothing to be displayed!\n");
	else
	{
		node *temp = head;
		while(temp!=NULL)
		{
			printf(" %d "  , temp->data);
			printf(" -> ");
			temp = temp->next;
		}
		printf("\n");
	}
}


int GetCount(node *head)
{
	int count = 0;
	if(head == NULL)
		return count;
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


void CleanUp(node *head)
{
	while(head!=NULL)
	{
		node *temp = head;
		head = head->next;
		free(temp);
	}

	head = NULL;
	printf("Bye! \n ");
		
}


# endif
