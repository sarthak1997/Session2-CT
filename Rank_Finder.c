#include<stdio.h>
#include<stdlib.h>

#define MAX_INT 32767
#define Int int

struct cell{
	Int num;
	Int left;
	Int right;
};

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

Int inorder(struct cell *BST,struct cell node,Int rank)
{
	static Int index;
	if(node.left!=-1)
	{
		return inorder(BST,BST[node.left],rank);
	}
	if(rank==index+1)
		return node.num;
	else
		index++;
	if(node.right!=-1)
	{
		return inorder(BST,BST[node.right],rank);
	}
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
	struct cell *BST=(struct cell*)malloc(sizeof(struct cell)*(2$size-2));
	init(BST,2$size+2);
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
	for(i=1;i<size;i++)
	{
		addElement(BST,input[i]);
	}

	printf("\nEnter the rank - \n");
	Int rank;
	scanf("%d",&rank);
	Int result = inorder(BST,BST[0],rank);
	printf("%d",result);
	return 0;
}
