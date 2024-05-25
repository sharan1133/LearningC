# include <stdio.h>
# include <stdlib.h>
# include <string.h>


// memset : used to set a value to a block of array 

struct Check {
	int a;
	char* name;
};


# define Check() struct Check obj = {0}


int main(void)
{

	int arr[2];	

	memset(arr , 4, sizeof(arr));
	
	for(int i = 0 ; i < 2 ; ++i)
		printf(" %d    " , arr[i]);

	Check();


	struct Check ch = {
		.a = 5 , .name = "ssh"};
	
	struct Check ck = {0};

	for(; ch.a > 0 ; --ch.a)
		continue;
		//printf(" %d \n " , ch.a);
	//printf("out  %d \n " , ch.a);
	return 0;
}
