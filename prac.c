# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>


# define CAPACITY 10


typedef struct Data
{
	char* key;
	int data;
	struct Data *next;
}Data;


typedef struct HashMap
{
	int size;		
	int capacity;
	Data** buckets;
}HashMap;


int hashcode(char* key)
{
	int value = 0;
	for(int i = 0 ; key[i]!='\0' ; i++)
		value += key[i];
	return value;
}


HashMap* CreateHashMap()
{
	HashMap* map = (HashMap*)malloc(sizeof(HashMap));		
	map->buckets = (Data**)calloc(10 , sizeof(Data*));  
	map->capacity = CAPACITY;
	map->size = 0;
	return map;
}


void Put(HashMap* map , char* key , int data)
{
	int hash = hashcode(key) % map->capacity;
	Data* temp = (Data*)malloc(sizeof(Data));
	temp->key = (char*)malloc(strlen(key) + 1);
	strcpy(temp->key , key);
	temp->data = data;
	temp->next = NULL;

	if(map->buckets[hash] == NULL)
		map->buckets[hash] = temp;
	else
	{
		Data* curr = map->buckets[hash];
		while(curr->next!=NULL)
		{
			curr = curr->next;	
		}
		curr->next = temp;
	}
	map->size++;
}


int Get(HashMap* map , char* key)
{
	int hash = hashcode(key) % map->capacity;
	Data* curr = map->buckets[hash];
	
	while(curr!=NULL)
	{	
		if(strcmp(curr->key, key) == 0)
		{
			return curr->data; 
		}
		curr = curr->next;
		
	}
}

int main(void)
{
	HashMap* dict = CreateHashMap();
	Put(dict , "Sharan" , 100);
	printf(" dict[\"Sharan\"] = %d \n " , Get(dict , "Sharan")); 
	return 0;
}
