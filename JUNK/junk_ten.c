# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>


int main(void)
{
	char string[100] = "1.2..13.4..6.6...";

	int len = strlen(string);
	//printf(" %s \n " , string);
	printf(" Length of string : %d \n " , len);

	char word[3] = "4";
	
	int n = atoi(word);

	//printf(" %s \n "  , word);
	//printf(" %d \n " , n);	
	
	int values[7] = {0,0,0,0,0,0,0};

	//char Words[8] = {"0s" , "1s" , "2s" , "3s" , "4s" , "5s" ,"6s"};

	int sum = 0;
	for(int i = 0 ; i < len ; i++)
	{
		
		if(string[i]!='\0')
		{
			char temp[3];
			sprintf(temp , "%c" , string[i]);
			int value = atoi(temp);	
			values[value] += 1;
			sum += value;
		}
		else
		{
			printf(" Bye! \n ");
			break;
		}
	}

	printf(" The total is : %d \n "  , sum);
	for(int i = 0 ; i < 7 ; i++)
	{
		printf(" %d's  : %d \n " , i , values[i]); 
		//printf("   %d    "  , values[i]);
	}
	printf(" \n ");
	return 0;
}
