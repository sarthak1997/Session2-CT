#include<stdio.h>
#include<stdlib.h>

#define MAX_INT 32767
#define Int int

struct cell{
	Int num;
	Int left;
	Int right;
};
/*
int leftChild(int i)
{
	return 2*i+1;
}

int rightChild(int i)
{
	return 2*i+2;
}

void addElement(struct cell *BST,Int num)
{
	int i=0;
	while(1)
	{
		if(num>BST[i].num)
		{
			if(BST[i].right==-1)
			{
				printf("\nRightAdded %d\n",BST[i].num);
				BST[rightChild(i)].num=num;
				BST[i].right=rightChild(i);
				break;
			}
			else
				i=BST[i].right;
		}
		else if(num<BST[i].num)
		{
			if(BST[i].left==-1)
			{
				printf("\nLeft Added %d\n",BST[i].num);
				BST[leftChild(i)].num=num;
				BST[i].left=leftChild(i);
				break;
			}
			else
				i=BST[i].left;
		}
	}
}*/

Int addElement(struct cell *BST,Int num,Int index,Int size)
{
	BST[index].num=num;
	Int i;
	for(i=0;i<size;)
	{
		if(num>BST[i].num)
		{
			if(BST[i].right==-1)
			{
	//			printf("\nAddedRight %d %d\n",BST[i].num,num);
				BST[i].right=index;
				return 1;
			}
			else
				i=BST[i].right;
		}
		else if(num<BST[i].num)
		{
			if(BST[i].left==-1)
			{
	//			printf("\nAdded Left %d %d\n",BST[i].num,num);	
				BST[i].left=index;
				return 1;
			}
			else
				i=BST[i].left;
		}
		else
			return 0;
		//printf("\nI=%d\n",i);
	}
}

void init(struct cell *BST,Int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		BST[i].right=-1;
		BST[i].left=-1;
	}
}

int a;

void inorder(struct cell *BST,struct cell node,Int rank)
{
	static Int index=0;
	//printf("\na=%d\n",a);
	if(index==-1)
		return;
	if(node.right!=-1)
	{
		
		inorder(BST,BST[node.right],rank);
	}
	//printf("\n%d - %d\n",node.num,index);
	if(rank==index+1)
	{
		a = node.num;
		index=-1;
		return;
	}
	else if(index!=-1)
		index++;
	if(node.left!=-1)
	{
		inorder(BST,BST[node.left],rank);
	}
	//printf("\na=%d\n",a);
}

int main()
{
	Int size;
	printf("Enter the size of the array - ");
	scanf("%d",&size);
	if(size>MAX_INT || size<0)
	{
		printf("Size can't be greater than %d or smaller than 0",MAX_INT);
		return 0;
	}
	Int *input=(Int*)malloc(sizeof(Int)*size);
	Int i;
	struct cell *BST=(struct cell*)malloc(sizeof(struct cell)*size);
	init(BST,size);
	printf("\nEnter array elements\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&input[i]);
		if(input[i]>MAX_INT)
		{
			printf("Input can't be greater than %d",MAX_INT);
			return 0;
		}
	}
	BST[0].num=input[0];
	Int BST_size=1;
	for(i=1;i<size;i++)
	{
		BST_size+=addElement(BST,input[i],i,size);
	}

	printf("\nEnter the rank -");
	Int rank;
	scanf("%d",&rank);
	while(1)
	{
		if(rank<=BST_size && rank>0)
			break;
		else
		{
			printf("\nRank you entered does fit according to the input. Enter again - ");
			fflush(stdin);
			scanf("%d",&rank);
		}
	}
	inorder(BST,BST[0],rank);
	printf("\nRESULT = %d\n",a);
	return 0;
}
