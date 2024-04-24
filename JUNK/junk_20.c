# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

# define CAPACITY 10
# define HASH hash = HashCode(key) % map->capacity

typedef struct Entry {
	char *key;
	int data;
	struct Entry *next;
}Entry;


typedef struct HashMap {
	Entry** buckets;
	int size;
	int capacity;
}HashMap;


int HashCode(char* key)
{
	int value = 0;
	for(int i = 0 ; key[i]!='\0' ; i++)
		value+=key[i];
	return value;
}

HashMap* Create()
{
	HashMap* map = (HashMap*)malloc(sizeof(HashMap));
	map->buckets = (Entry**)calloc(CAPACITY , sizeof(Entry*));
	map->size = 0;
	map->capacity = CAPACITY;
	return map;
}


void Put(HashMap* map , char* key , int data)
{
	int hash = 0;	
	HASH;
	
	if(map->buckets[hash] == NULL)
	{
		Entry* new = (Entry*)malloc(sizeof(Entry));
		new->key = (char*)malloc(strlen(key) + 1);
		strcpy(new->key , key);
		new->data = data;
		new->next = NULL;
		map->buckets[hash] = new;
		map->size++;
		return;
	}

	else
	{
		Entry* curr = map->buckets[hash];	
		
		while(curr!=NULL)
		{
			if(strcmp(curr->key , key) == 0)
			{
				printf("Key Already Exists!\n");
				return;
			}
			curr = curr->next;
		}
		
		Entry* new = (Entry*)malloc(sizeof(Entry));
		new->key = (char*)malloc(strlen(key) + 1);
		strcpy(new->key , key);
		new->data = data;
		new->next = map->buckets[hash];
		map->buckets[hash] = new;
		map->size++;
	}

}


int Get(HashMap* map , char* key)
{
	int hash = 0;
	HASH;
	Entry* curr = map->buckets[hash];
	
	if(curr == NULL)
		return -1;
	else
	{
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
}


int main(void)
{
	HashMap* Dict = Create();
	Put(Dict , "A" , 12);
	Put(Dict , "B" , 13);
	Put(Dict , "C" , 14);
	printf(" Dict[\"A\"] = %d \n "  , Get(Dict , "A"));
	printf(" Dict[\"B\"] = %d \n "  , Get(Dict , "B"));
	printf(" Dict[\"C\"] = %d \n "  , Get(Dict , "C"));



	return 0;
}
