//program to print only unique elements present in an array.
//this program takes 2.844s for 10million random inputs.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<inttypes.h>

#define ENABLE_DEBUGGING

#define HASH_CELL_SIZE 1000
#define HASH_TABLE_SIZE 1000
#define SIZE 10

//cell for storing values with count
struct cell{
	long long int number;
	long long int count;
};
//hash_cell with array of chains to handle collision
struct hash_cell{
	struct cell chains[HASH_CELL_SIZE];
};

long long int a=35,b=9,prime=1000000007;

//linear hash function
long long int getHash(long long int num)
{
	return ((a*num+b)%prime)%HASH_TABLE_SIZE;
}

/*

methods checks count for empty cells and checks num for already present cell in a particular hash cell array of chains

*/
void addHashCell(struct hash_cell *HashTable,long long int hashVal,long long int num)
{
	long long int i;
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
/*

method looks for count of every element wrt its hash cell chain and checks its uniqueness by count

*/


long long int checkCount(struct hash_cell *HashTable,long long int hashVal,long long int num)
{
	long long int i;
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

//initialize count to 0 to check empty cells later
void init(struct hash_cell *HashTable)
{
	printf("\ninside init\n");
	long long int i,j;
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
	long long int *input=(long long int*)malloc(sizeof(long long int)*SIZE);
	//printf("input created\n");
	long long int i=0;
	//printf("\n--\n");
	for(i=0;i<SIZE;i++)
	{
		scanf("%lld",&input[i]);
		//input[i]=rand();
	}
	struct hash_cell *Hash_Table=(struct hash_cell*)malloc(sizeof(struct hash_cell)*HASH_TABLE_SIZE);
	printf("\nHash created\n");
	init(Hash_Table);
	printf("\nInitialized\n");
		
	//finding timestamp in ms before processing the input
	#ifdef ENABLE_DEBUGGING
	long long int ms;
	time_t s;
	struct timespec spec;
	clock_gettime(CLOCK_REALTIME,&spec);
	s=spec.tv_sec;
	ms= (spec.tv_nsec / 1.0e06);
	printf("Time before execution - %"PRIdMAX".%03lld\n",(intmax_t)s,ms);
	#endif 

	long long int hashVal;
	//making of hash table from input
	for(i=0;i<SIZE;i++)
	{
		hashVal=getHash(input[i]);
		addHashCell(Hash_Table,hashVal,input[i]);
	}
	//printing the output
	int flag=1;
	for(i=0;i<SIZE;i++)
	{
		hashVal=getHash(input[i]);
		if(checkCount(Hash_Table,hashVal,input[i]))
		{
			printf("%lld ",input[i]);
			flag=0;
		}
	}
	if(flag)
	{
		printf("\nNo Unique elements\n");
	}
	printf("\n");

	//finding timestamp in ms after processing the input
	clock_gettime(CLOCK_REALTIME,&spec);
	s=spec.tv_sec;
	ms= (spec.tv_nsec / 1.0e06);
	printf("Time after Execution - %"PRIdMAX".%03lld",(intmax_t)s,ms);

	//deallocating the memory
	free(input);
	free(Hash_Table);
	


	return 0;
}
