# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

# define CAPACITY 10

# define N printf("\n")


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


int GetHashCode(char *key)
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


void Put(HashMap* map , char* key , int value)
{
	int hash = GetHashCode(key) % map->capacity;
	Entry* new = (Entry*)malloc(sizeof(Entry));
	new->key = malloc(strlen(key) + 1);
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


int Get(HashMap* map , char* key)
{
	int hash = GetHashCode(key) % map->capacity;
	Entry* temp = map->buckets[hash];

	while(temp!=NULL)
	{
		if(strcmp(temp->key , key) == 0)
		{
			return temp->data;
		}
		temp = temp->next;
	}
	return -1;

}


int main(void)
{

	HashMap* dict = Create();
	Put(dict , "Temp1" , 15);
	Put(dict , "Temp2" , 17);
	Put(dict , "Temp3" , 29);
	printf(" dict[\"Temp1\"] = %d " , Get(dict , "Temp1"));
	N;
	printf(" dict[\"Temp2\"] = %d " , Get(dict , "Temp2"));
	N;
	printf(" dict[\"Temp3\"] = %d " , Get(dict , "Temp3"));
	N;


	//N;
	return 0;
}

