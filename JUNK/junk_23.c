# include <stdio.h>
# include <stdlib.h>
# include <string.h>


# define CAPACITY 15
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
		new->data = data;
		new->key = (char*)malloc(strlen(key) + 1);
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
				printf("Key Already Exists!Bye!\n");
				return;
			}
			curr = curr->next;

		}
		Entry* new = (Entry*)malloc(sizeof(Entry));
		new->data = data;
		new->key = (char*)malloc(strlen(key) + 1);
		strcpy(new->key , key);
		new->next = map->buckets[hash];
		map->buckets[hash] = new;
	}
	map->size++;
}


int Get(HashMap* map , char* key)
{
	int hash = 0;
	HASH;

	if(map->buckets[hash] == NULL)
	{
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




int main(void)
{
	HashMap* map = Create();	
	Put(map , "Key1" , 40);
	Put(map , "Key2" , 41);
	Put(map , "Key3" , 43);
	printf(" map[\"Key1\"] = %d \n " , Get(map , "Key1"));
	printf(" map[\"Key2\"] = %d \n " , Get(map , "Key2"));
	printf(" map[\"Key3\"] = %d \n " , Get(map , "Key3"));


	return 0;
}
