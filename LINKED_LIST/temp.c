# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./HEADERFILES/linked_list.h"



/*typedef struct Node {
	struct Node *next;
	int data;
}node; */ 







int main(void)
{
	node *head = NULL;
	InsertAtBeginning(&head , 10);
	InsertAtBeginning(&head , 8);
	InsertAtBeginning(&head , 6);
	InsertAtBeginning(&head , 4);
	InsertAtBeginning(&head , 2);
	Display(head);


	DeleteAtBeginning(&head);
	DeleteAtBeginning(&head);
	Display(head);

	DeleteAtEnd(&head);
	DeleteAtEnd(&head);

	Display(head);

	DeleteAtBeginning(&head);

	Display(head);

	CleanUp(head);
	return 0;
}
