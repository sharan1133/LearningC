# ifndef doubly_linked_list_h
# define doubly_linked_list_h


# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <assert.h>

typedef struct Node 
{
	struct Node *next;
	struct Node *prev;
	int data;
}node;

void InsertAtFront(node **head , int value);
void DeleteAtFront(node **head);
void Display(node *head);
void InsertAtLast(node **head , int value);
void DeleteAtLast(node **head);
int GetCount(node *head);
void InsertAtPos(node **head , int value , int pos);
void DeleteAtPos(node **head , int pos);
void CleanUp(node *head);


# endif

