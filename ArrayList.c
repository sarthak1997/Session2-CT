#include<stdio.h>
#include<stdlib.h>

#define MAX_INT 32767

int main()
{
	int size;
	printf("Enter size");
	scanf("%d",&size);
	if(size>MAX_INT)
	{
		printf("Size cannot be bigger than %d",MAX_INT);
		return 0;
	}
	int *input=(int *) malloc(sizeof(int)*size);
	printf("\nEnter input array - \n");	
	int i;
	for(i=0;i<size;i++)
	{
		scanf("%d",&input[i]);
		if(input[i]>MAX_INT)
		{
			printf("Input cannot be greater than %d",MAX_INT);
			return 0;
		}
	}
	printf("\nEnter the number you want to insert - \n");
	int num;
	scanf("%d",&num);
	if(num>MAX_INT)
	{
		printf("Input cannot be greater than %d",MAX_INT);
		return 0;
	}
	printf("\nEnter the index at which you want to insert - \n");
	int index;
	scanf("%d",&index);
	if(index>size+1)
	{
		printf("Your input makes the index out of bound");
		return 0;
	}
	size++;
	input=(int *) realloc(input,sizeof(int)*size);
	int temp1=num,temp2;
	for(i=0;i<size;i++)
	{
		if(i<index-1)
			continue;
		else
		{
			temp2=input[i];
			input[i]=temp1;
			temp1=temp2;
		}
	}
	printf("\nADDED\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",input[i]);
	}
	return 0;	
}
