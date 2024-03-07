# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../LINKED_LIST/doubly_linked_list_h.h"


# define DELETEATPOS( new , num) \
	DeleteAtPos(&new , num); \
	Display(new);

# define INSERTLAST(new , value) \
	InsertAtLast(&new , value); \
	Display(new);


# define INSERTATPOS(new , value , pos) \
	InsertAtPos(&new , value , pos); \
	Display(new);

# define INSERTFRONT(new , value) \
	InsertAtFront(&new , value); \
	Display(new);


# define COUNT GetCount(new)

void get_original_number_back(int number , int k , int truncation)
{
	// k - number of digits 
	double power = pow(10 , k - truncation);
	printf(" %d \n " , number % (int)power);
}



int main(void)

{
	

	node *new = NULL;
	INSERTFRONT(new , 10);
	INSERTFRONT(new , 20);
	INSERTLAST(new , 50);
	INSERTLAST(new , 60);
	INSERTATPOS(new , 7620 , COUNT);
	printf(" number of elements : %d \n " , COUNT);
	return 0;
}
