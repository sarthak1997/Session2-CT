//program to add element at specified index in an array

#include<stdio.h>
#include<stdlib.h>

/*
method uses a loop to traverse till the index at which the elements needs to be added and the after adding the new element shifts all the remaining element after it by one position 
*/
void insertAt(int *input,int num,int index,int size)
{
		int temp1=num,temp2,i;
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
}

int main()
{
	int size;
	printf("\nEnter size - ");
	scanf("%d",&size);
	//validation to check size by user
	if(size<=0)
	{
		printf("\nInvalid size\n");
		return 0;
	}
	int *input=(int *) malloc(sizeof(int)*size);
	printf("\nEnter input array - ");	
	int i;
	for(i=0;i<size;i++)
	{
		scanf("%d",&input[i]);
		
	}
	printf("\nEnter the number you want to insert - ");
	int num;
	scanf("%d",&num);
	printf("\nEnter the index at which you want to insert - ");
	int index;
	scanf("%d",&index);
	//validation to check range of index by user
	if(index<0 || index>size)
	{
		printf("\nIndex is out of range of the array\n");
		return 0;
	}	
	size++;
	input=(int *) realloc(input,sizeof(int)*size);	
	insertAt(input,num,index,size);
	printf("\nADDED\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",input[i]);
	}
	printf("\n");
	return 0;	
}
