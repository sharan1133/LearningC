# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>


#define CAPACITY 45

typedef struct Entry {
	char* key;
	int value;
	struct Entry *next;
}Entry;


typedef struct HashMap {
	Entry** buckets;
	int size;
	int capacity;

}HashMap;


int HashCode(char* key)
{
	int hash = 0;
	for(int i = 0 ; key[i]!='\0' ; i++)
		hash += key[i];
	return hash;
}


HashMap* createHashMap()
{
	HashMap *map = (HashMap*)malloc(sizeof(HashMap));
	map->buckets = (Entry**)calloc(CAPACITY , sizeof(Entry*));
	map->size = 0;
	map->capacity = CAPACITY;
	return map;
	
}


void put(HashMap *map , char* key , int value)
{
	int index = HashCode(key) % map->capacity;
	Entry* newEntry = (Entry*)malloc(sizeof(Entry));
	newEntry->key = (char*)malloc(strlen(key) + 1);
	strcpy(newEntry->key , key);
	newEntry->value = value;
	newEntry->next = NULL;


	if(map->buckets[index] == NULL)
		map->buckets[index] = newEntry;
	else
	{
		Entry* curr = map->buckets[index];
		while(curr->next!=NULL)
		{
			curr = curr->next;
		}
		curr->next = newEntry;
	}
	map->size++;

	
}


int get(HashMap *map , char *key)
{
	int index = HashCode(key) % map->capacity;
	Entry* current = map->buckets[index];

	while(current!=NULL)
	{
		if(strcmp(current->key , key) == 0)
		{
			return current->value;
		}
		
		
		current = current->next;
		
	}	

	return -1;
}




int main(void)
{
	HashMap *map = createHashMap(); 
	put(map , "One" , 1);	
	put(map , "Two" , 2);
	put(map , "Three" , 3);
	printf(" Value for Key : One is = %d \n " , get(map , "One")); 	
	//printf("Hello World!\n");
	return 0;
}
