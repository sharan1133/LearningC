# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>

int main(void)
{
	unsigned char bytes[6] = {};

	bytes[0] = 0b01001000;
	bytes[1] = 0x65;
	bytes[2] = 108;
	bytes[3] = 0154;
	bytes[4] = 'o';
	bytes[5] = 0;
	
	printf("Idx Dec Hex Oct C Bin\n");
	printf("--- --- --- --- - ---\n");
	for(int i = 0 ; i < sizeof(bytes)/sizeof(bytes[0]) ; i++)
	{
		printf("[%2u] %3u %2x %3o %c " , i , bytes[i] , bytes[i] , bytes[i] , bytes[i]);

		for(int b = 7 ; b>=0 ; b--)
		{
			int bit = (bytes[i] >> b) & 0b00000001;
			printf("%u" , bit);
		}
		printf("\n");
	}

	printf(" %s \n " , bytes);

	return 0;
}
