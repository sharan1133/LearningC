# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

#define COUNT 10; 

typedef struct Entry {
	char *key;
	int data;
	struct Entry *next;
}Entry;


typedef struct HashMap
{
	Entry** buckets;	
	int size;
	int capacity;

}HashMap;


int hashcode(char *key)
{
	int value = 0;
	for(int i = 0 ; key[i]!='\0' ; i++)
		value += key[i];
	return value;
}


HashMap* CreateHashMap()
{
	HashMap *map = (HashMap*)malloc(sizeof(HashMap));
	map->capacity = COUNT;
	map->size = 0;
	map->buckets = (Entry**)calloc(map->capacity , sizeof(Entry*));
	return map;
}


void Put(HashMap *map , char *key , int data)
{
	int index = hashcode(key) % map->capacity;
	Entry *newEntry = (Entry*)malloc(sizeof(Entry));
	newEntry->key = (char*)malloc(strlen(key)+ 1);
	strcpy(newEntry->key , key);
	newEntry->data= data;
	newEntry->next = NULL;


	if(map->buckets[index] == NULL)
		map->buckets[index] = newEntry;

	else
	{
		Entry *curr = map->buckets[index];	
		while(curr->next!=NULL)
		{
			curr = curr->next;
		}
		curr->next = newEntry;
	}
	map->size++;
}



int Get(HashMap *map , char *key)
{
	int index = hashcode(key) % map->capacity;
	printf(" hash : %d \n "  , index); 
			 
	Entry* curr = map->buckets[index];

	while(curr!=NULL)
	{
		if(strcmp(curr->key , key) == 0)
		{
			return curr->data;
		}
		curr = curr->next;
	}

	return -1;


}



int main(void)
{
	HashMap *temp = CreateHashMap();
	Put(temp , "Sharan" , 123);
	Put(temp , "A" , 998);
	printf("Sharan -> %d \n " , Get(temp , "Sharan"));
	printf("Abc-> %d \n " , Get(temp , "A"));
	return 0;
}
