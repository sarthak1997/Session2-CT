#include<stdio.h>

#define HASH_CELL_SIZE 100
#define HASH_TABLE_SIZE 100
#define SIZE 5

struct cell{
	long long int number;
	int count;
};

struct hash_cell{
	struct cell chains[HASH_CELL_SIZE];
};

long long int a=35,b=9,prime=1000000007;

long long int getHash(long long int num)
{
	return ((a*num+b)%prime)%HASH_TABLE_SIZE;
}

void addHashCell(struct hash_cell *HashTable,long long int hashVal,long long int num)
{
	int i;
	for(i=0;i<HASH_CELL_SIZE;i++)
	{

		if(HashTable[hashVal].chains[i].count==0)
			break;
		else if(HashTable[hashVal].chains[i].number==num)
			break;
	}
	HashTable[hashVal].chains[i].number=num;
	HashTable[hashVal].chains[i].count+=1;
	//printf("\n%d, %d, %d, %d\n",hashVal,i,HashTable[hashVal].chains[i].number,HashTable[hashVal].chains[i].count);
}

int checkCount(struct hash_cell *HashTable,long long int hashVal,long long int num)
{
	int i;
	for(i=0;i<HASH_CELL_SIZE;i++)
	{
		if(HashTable[hashVal].chains[i].number==num)
			break;
	}
	if(HashTable[hashVal].chains[i].count==1)
		return 1;
	else
		return 0;
}

void init(struct hash_cell *HashTable)
{
	int i,j;
	for(i=0;i<HASH_TABLE_SIZE;i++)
	{
		for(j=0;j<HASH_CELL_SIZE;j++)
		{
			HashTable[i].chains[j].count=0;
		}
	}
}

int main()
{
	long long int input[SIZE];
	int i=0;
	//printf("\n--\n");
	for(i=0;i<SIZE;i++)
	{
		scanf("%lld",&input[i]);
	}
	struct hash_cell Hash_Table[HASH_TABLE_SIZE];
	init(Hash_Table);
	long long int hashVal;
	for(i=0;i<SIZE;i++)
	{
		hashVal=getHash(input[i]);
		addHashCell(Hash_Table,hashVal,input[i]);
	}
	for(i=0;i<SIZE;i++)
	{
		hashVal=getHash(input[i]);
		if(checkCount(Hash_Table,hashVal,input[i]))
		{
			printf("%lld ",input[i]);
		}
	}
	printf("\n");
	return 0;
}
