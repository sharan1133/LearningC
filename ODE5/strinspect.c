// Given a string as cmd line argument print each byte as ascii , hex and binary
// Add this to PATH so that this can be used as a tool


 # include <stdio.h>
 # include <stdlib.h>
 # include <stdbool.h>
 # include <string.h>


int main(int argc , char* argv[])
{
	//char* temp[] = {"hello" , "hello2" , "hello3"}; 
	//printf("%s \n" , argv[1]);
	//printf("%c \n" , *(*(argv+1)+1));


	size_t size = strlen(argv[1]);
	for(int i = 0 ; i < size ; i++) 
	{
		printf(" Ascii : %c \n " , *(*(argv+1)+i));
		printf(" Hex : %x \n "  , *(*(argv+1)+i));
		printf(" Binary : ");	
		for(int b = 7 ; b >=0 ; b--)
		{
			int bit = (*(*(argv+1)+i) >> b) & 0b00000001;
			printf("%u" , bit);
		}
		printf("\n");
	
	}

	return 0;
}

