#include<stdio.h>
#include<stdlib.h>

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

/*int insertionSort(int *result,int *input,int size1)
{
	int i,size=0;
	for(i=0;i<size1;i++)
	{
		
	}
}*/

void swap(int *p,int *q)
{
	*p=*p+*q;
	*q=*p-*q;
	*p=*p-*q;
}

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
	printf("\nEnter size of second array - ");
	scanf("%d",&size2);
	int *input1=(int *)malloc(sizeof(int)*size1);
	int *input2=(int *)malloc(sizeof(int)*size2);
	int *result=(int *)malloc(sizeof(int)*(size1+size2));
	printf("Enter elements of first array - ");
	int i;
	for(i=0;i<size1;i++)
	{
		scanf("%d",&input1[i]);
		result[i]=input1[i];
	}
	printf("Enter elements of second array - ");
	for(i=0;i<size2;i++)
	{
		scanf("%d",&input2[i]);
		result[i+size1]=input2[i];
	}
	int size=0;
	sort(result,size1+size2);
	printf("Sorted Array is - ");
	for(i=0;i<size1+size2;i++)
	{
		printf("%d ",result[i]);
	}
	return 0;
}
