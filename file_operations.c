# include <stdio.h>
# include <stdlib.h>
# include <string.h>
//# include <File.h>

// strcspn(line , "\n")
// char* fgets(char* str , int n , FILE* stream)
// fprintf(ptr , "Line to be written");

int main(void)
{
	printf("Hello World!\n");
	FILE *ptr;

	char buffer[110];

	ptr = fopen("./JUNK/random.txt" , "r");


	if(ptr == NULL)
	{
		printf("Error in opening file!\n");
		return 1;
	}
	else
	{
		while(fgets(buffer , sizeof(buffer) , ptr)!=NULL)
		{
			buffer[strcspn(buffer , "\n")] = '\0';
			printf(" %s \n " , buffer);
		}
	}


	fclose(ptr);

	return 0;
}
