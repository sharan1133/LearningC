# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

# define CAPACITY 10
# define HASH hash = GetHashCode(key) % map->capacity


typedef struct Entry {
	char* key;
	int data;
	struct Entry* next;
}Entry;


typedef struct HashMap{
	Entry** buckets;
	int size;
	int capacity;
}HashMap;


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
	map->buckets = (Entry**)calloc(10 , sizeof(Entry*));
	map->size = 0;
	map->capacity = CAPACITY;
	return map;
}


void Push(HashMap* map , char* key , int data)
{
	int hash = 0;
	HASH;

	if(map->buckets[hash] == NULL)
	{
		Entry* new = (Entry*)malloc(sizeof(Entry));
		new->data = data;
		new->key = (char*)malloc(strlen(key));
		strcpy(new->key , key);
		new->next = NULL;
		map->buckets[hash] = new;
	}

	else
	{
		Entry* curr = map->buckets[hash];

		while(curr!=NULL)
		{
			if(strcmp(curr->key , key) == 0)
			{
				printf("Key exists!\n");
				return;
			}
			curr = curr->next;
		}
		Entry* new = (Entry*)malloc(sizeof(Entry));
		new->data = data;
		new->key = (char*)malloc(strlen(key));
		strcpy(new->key , key);
		new->next = map->buckets[hash];
		map->buckets[hash] = new;


	}
	map->size++;
}


int Pop(HashMap* map , char* key)
{
	int hash = 0;
	HASH;
	if(map->buckets[hash] == NULL)
	{
		printf("Key doesn't exist!\n");
		return -1;
	}
	else
	{
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
}


void CleanUP(HashMap* map)
{
	for(int i = 0 ; i < map->capacity ; i++)
	{
		Entry* curr = map->buckets[i];
		while(curr!=NULL)
		{
			Entry* temp = curr;
			curr = curr->next;
			free(temp->key);
			free(temp);
		}

	}
	free(map->buckets);
	free(map);
	printf("Clean Up Complete!\n");
}


int main(void)
{
	HashMap* map = Create();
	Push(map , "K1" , 80);
	printf(" %d \n Bye!! \n" , Pop(map , "K1")); 
	CleanUP(map);
	return 0;
}
