# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

# define CAPACITY 10

# define Ins Insert(dictionary , key , value)

# define getvalue printf("dictionary[\"%s\"] = %d "  , key , Get(dictionary, key));
 

# define N printf("\n")

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


int GetHashCode(char *key)
{
	int result = 0;
	for(int i = 0 ; key[i]!='\0' ; i++)
	{
		result+=key[i];
	}
	return result;
}


HashMap* CreateNewHashMap()
{
	HashMap* map = (HashMap*)malloc(sizeof(HashMap));
	map->buckets = (Entry**)calloc(CAPACITY , sizeof(Entry*));
	map->size = 0;
	map->capacity = CAPACITY;
	return map;
}


void Insert(HashMap* map , char* key , int data)
{
	int hash = GetHashCode(key) % map->capacity;
	Entry* new = (Entry*)malloc(sizeof(Entry));
	new->key = malloc(strlen(key) + 1);
	strcpy(new->key , key);
	new->data = data;
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


int main(void)
{
	HashMap* dictionary = CreateNewHashMap();
	Insert(dictionary , "One" , 1);
	Insert(dictionary , "Two" , 2);
	Insert(dictionary , "Three", 3);
	printf("dictionary[\"One\"] = %d "  , Get(dictionary, "One"));
	N;
	printf("dictionary[\"Two\"] = %d "  , Get(dictionary, "Two"));
	N;
	printf("dictionary[\"Three\"] = %d "  , Get(dictionary, "Three"));
	N;
	char* key  = "Four";
	int value = 4;
	Ins;
	getvalue;
	N;

	return 0;
}

