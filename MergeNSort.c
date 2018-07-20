//program merges two array and sort them using selection sort

#include<stdio.h>
#include<stdlib.h>

//method to swap to elements by reference
void swap(int *p,int *q)
{
	*p=*p+*q;
	*q=*p-*q;
	*p=*p-*q;
}

//selection sort
void sort(int *result,int size)
{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(result[i]>result[j])
			{
				swap(&result[i],&result[j]);
			}
		}
	}
}

int main()
{
	int size1,size2;
	printf("\nEnter size of first array - ");
	scanf("%d",&size1);
	if(size1<=0 || size1>10000)
	{
		printf("Invalid size");
		return 0;
	}
	printf("\nEnter size of second array - ");
	scanf("%d",&size2);
	if(size2<=0 || size2>10000)
	{
		printf("Invalid size");
		return 0;
	}
	int *input1=(int *)malloc(sizeof(int)*size1);
	int *input2=(int *)malloc(sizeof(int)*size2);
	int *result=(int *)malloc(sizeof(int)*(size1+size2));
	printf("\nEnter elements of first array - ");
	int i;
	for(i=0;i<size1;i++)
	{
		scanf("%d",&input1[i]);
		result[i]=input1[i];
	}
	printf("\nEnter elements of second array - ");
	for(i=0;i<size2;i++)
	{
		scanf("%d",&input2[i]);
		result[i+size1]=input2[i];
	}
	int size=0;
	sort(result,size1+size2);
	printf("\nSorted Array is - ");
	for(i=0;i<size1+size2;i++)
	{
		printf("%d ",result[i]);
	}
	return 0;
}
