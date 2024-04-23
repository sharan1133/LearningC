# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

# define CAPACITY 10
# define N printf("\n")
# define HASH hash = GetHashCode(key) % map->capacity




typedef struct Node {
	int data;
	struct Node *next;
}node;


typedef struct Entry {
	char* key;
	int data;
	struct Entry *next;
}Entry;


typedef struct HashMap {
	Entry** buckets;
	int size;
	int capacity;
}HashMap;


int Get(HashMap* map , char* key);

int GetHashCode(char* key)
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

}


void Put(HashMap* map , char* key , int value)
{
	if(Get(map , key) == -1)
	{
	int hash = 0;	
	HASH;
	//int hash = GetHashCode(key) % map->capacity;
	Entry* new = (Entry*)malloc(sizeof(Entry));	
	//new->key = strdup(key);
	new->key = (char*)malloc(strlen(key) + 1);
	strcpy(new->key , key);
	new->data = value;
	new->next = NULL;
	
	if(map->buckets[hash] == NULL)
		map->buckets[hash] = new;
	else
	{
		Entry* curr = map->buckets[hash];
		while(curr->next!=NULL)
		{
			curr = curr->next;	
		}
		curr->next = new;
	}
	map->size++;
	}
	else
	{
		printf("Key Already Exists!\n");
	}
}


int Get(HashMap* map , char* key)
{
	int hash = 0;
	HASH;
	//int hash = GetHashCode(key) % map->capacity;
	
	Entry* curr = map->buckets[hash];
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


void remove_entry(HashMap* map , char* key)
{
	int hash = hash_code(key) % map->capacity;
	Entry* entry = map->buckets[hash];
	Entry* prev = NULL;

	while(entry!=NULL)
	{
		if(strcmp(entry->key , key) == 0)
		{
			if(prev == NULL)
			{
				map->buckets[hash] = entry->next;
			}
			else
			{
				prev->next = entry->next;
			}
			free(entry->key);
			free(entry);
			map->size--;
			return;
		}
		prev = entry;
		entry = entry->next;
	}
}


int main(void)
{
	HashMap* D = Create();
	Put(D , "One" , 111);
	Put(D , "One" , 222);
	//Put(D , "Three" , 333);
	//printf(" D[\"One\"] = %d " , Get(D , "One"));	
	//N;
	//printf(" D[\"Two\"] = %d " , Get(D , "Two"));
	//N;
	//printf(" D[\"Three\"] = %d " , Get(D , "Three"));

		
	//printf("Hello");
	N;
	return 0;
}
