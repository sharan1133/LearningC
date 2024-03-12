# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct Node 
{
	struct Node *next;
	int data;
}node;


int Run(char** argv[])
{
	FILE *makefile = fopen("Makefile" , "w");

	if(makefile == NULL)
	{
		printf("Error opening makefile. \n ");
		return 1;
	}

	fprintf(makefile , "SRC = %s.c\nEXEC = %s\n\n" , *(*(argv+0)) ,*(*(argv+0)));
	 fprintf(makefile, "all: $(EXEC)\n\tgcc $(SRC) -o $(EXEC)\n\n$(EXEC): $(SRC)\n");

	 fclose(makefile);
}



int main(int argc , char* argv[])
{
		printf(" %s \n " , argv[0]);
		printf("Hi \n ");
		//system(" echo 'Hello World' 'World Hello' ");
		//system(" mkdir tempfolder && echo 'Folder created'");
		//system("rmdir tempfolder && echo 'Folder removed' ");
		int result = Run(&argv);
	
		printf(" %d \n " , result);
		return 0;
}
