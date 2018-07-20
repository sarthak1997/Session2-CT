//program to find the nth rank element in array such that greater element has higher rank

#include<stdio.h>
#include<stdlib.h>

#define MAX_INT 32767
#define Int int

//node for a BST
struct cell{
	Int num;
	Int left;
	Int right;
};

/*

method to handle addition of element in BST such that addition is made within in an array of defined size i.e number of elements of input and not of 2^n+2

*/
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

//initialize to check for null pointer later
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
//method that traverse BST in reverse of inorder to find the rank as it basically arranges the elements in descending order.
void revinorder(struct cell *BST,struct cell node,Int rank)
{
	static Int index=0;
	//printf("\na=%d\n",a);
	if(index==-1)
		return;
	if(node.right!=-1)
	{
		
		revinorder(BST,BST[node.right],rank);
	}
	//printf("\n%d - %d\n",node.num,index);

	//checking the index visited with the rank in the descending order of elements
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
		revinorder(BST,BST[node.left],rank);
	}
	//printf("\na=%d\n",a);
}

int main()
{
	Int size;
	printf("Enter the size of the array - ");
	scanf("%d",&size);
	//size validation
	if(size<=0)
	{
		printf("\nInvalid Size\n");
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
	}
	//defining root of BST
	BST[0].num=input[0];
	Int BST_size=1;
	//adding elements with maintaining BST size
	for(i=1;i<size;i++)
	{
		BST_size+=addElement(BST,input[i],i,size);
	}

	printf("\nEnter the rank -");
	Int rank;
	scanf("%d",&rank);
	//rank validation and prompting user to enter until valid rank
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
	revinorder(BST,BST[0],rank);
	printf("\nRESULT = %d\n",a);
	return 0;
}
