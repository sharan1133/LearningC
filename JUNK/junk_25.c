# include <stdio.h>
# include <stdlib.h>
# include <string.h>


# define CAPACITY 10 

typedef struct item{
	int data;
	char *key;
	struct item *next;
}item;

typedef struct HashMap{
	item** buckets; 
	int size;
	int capacity;
}HashMap;


int GetHashKey(char *key)
{
	int val = 0;
	for(int i = 0 ; key[i]!='\0' ; i++)
		val+=key[i];
	return val;
}


HashMap* CreateHashMap()
{
	HashMap* map = (HashMap*)malloc(sizeof(HashMap));
	map->buckets = (item**)calloc(10, sizeof(item*));
	map->capacity = CAPACITY;
	map->size = 0;
	return map;
}


void Push(HashMap* map , char* key , int data)
{
	int hash = GetHashKey(key) % map->capacity;
	
	if(map->buckets[hash] == NULL)
	{
		item* new = (item*)malloc(sizeof(item));
		new->data = data;
		new->key = (char*)malloc(strlen(key));
		strcpy(new->key, key);
		new->next = NULL;
		map->buckets[hash] = new;

		
	}
	else
	{
		item* curr  = map->buckets[hash];

		while(curr!=NULL)
		{
			if(strcmp(curr->key , key) == 0)
			{
				printf("Key Already exists!\n");
				return;
			}
			curr = curr->next;
		}
		item* new = (item*)malloc(sizeof(item));
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
	int hash  = GetHashKey(key) % map->capacity;

	if(map->buckets[hash] == NULL)
	{
		printf("Key non existent!\n");
		return -1;
	}
	else
	{
		item* curr  = map->buckets[hash];
		
		while(curr!=NULL)
		{
			if(strcmp(curr->key , key)== 0)
			{
				return curr->data;
			}
			curr  = curr->next;
		}
		printf("Key doesn't exist!\n");
		return -1;

	}
}


int main(void)
{
	HashMap* map = CreateHashMap(); 
	Push(map , "one" , 10);
	Push(map , "one" , 10);

	//printf(" %d \n " , Pop(map , "one"));
	//printf(" %d \n " , Pop(map , "twp"));
	return 0;
}



