# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../DOUBLY_LINKED_LIST/doubly_linked_list_h.h"



void get_original_number_back(int number , int k , int truncation)
{
	// k - number of digits 
	double power = pow(10 , k - truncation);
	printf(" %d \n " , number % (int)power);
}



int main(void)

{

	node *new = NULL;
	InsertAtLast(&new , 10);
	InsertAtLast(&new , 20);
	InsertAtLast(&new , 30);
	InsertAtLast(&new , 40);
	InsertAtLast(&new , 50);
	Display(new);
	InsertAtPos(&new , 1 , GetCount(new));
	Display(new);
	//InsertAtPos(&new , 1 , 2);
	//Display(new);
	
	//get_original_number_back(86523 , 5 , 0);
	
	return 0;
}
