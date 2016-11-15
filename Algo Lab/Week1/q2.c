#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node* next;
	struct node* below;
}NODE;
	
NODE* create()
{
	NODE* temp=(NODE*)malloc(sizeof(NODE));
	temp->next=temp->below;	
	return temp;
}

NODE* addBNode(NODE* head,int val)
{
	NODE* temp=create();
	temp->val=val;		
	if(!head)
	{
		head=temp;	
	}
	else
	{
		NODE* curr=head;
		while(curr->below!=NULL)
			curr=curr->below;
		curr->below=temp;
	}
	return head;
}
NODE* createNodes(NODE* head,int numberOfNodes)
{
	int count=0;
	while(count<numberOfNodes)
	{
		head=addBNode(head,count);	
		count++;
	}
	return head;
}

NODE* addLNode(NODE* head,int val)
{
	NODE* temp=create();
	temp->val=val;
	if(!head)
	{
		head=temp;	
	}
	else
	{
		NODE* curr=head;
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=temp;
	}
	return head;
}
NODE* createListNode(NODE* head,int a,int b)
{

	int counter=0,counter2=0;
	NODE* curr=head;
	while(counter<a)
	{	
		curr=curr->below;
		counter++;
	}	
		head=addLNode(curr,b);
	return head;		
}

void Display(NODE* head,int m)
{
	NODE* curr=head,*curr2;
	int i=0;
	/*while(i<m)
		{
			curr=curr->below;
			//printf("%d ",curr->val);
			i++;
		}	
	NODE* curr2=curr;
	while(curr2!=NULL)
	{
		printf("%d ",curr2->val);
		//printf("Hello");		
		curr2=curr2->next;
	}*/
	for(curr=head;curr!=NULL;curr=curr->below)
	{
		for(curr2=curr;curr2!=NULL;curr2=curr2->next)
			printf("%d ",curr2->val);
		printf("\n");
	}
}

int main()
{
	int a,b;
	int n,m;
	printf("Enter Number of Nodes:\n");
	scanf("%d",&n);
	NODE* head=NULL;
	head=createNodes(head,n);
	int ch;	
	while(1)
	{
		printf("1.Insert 2.Display 3.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter The vertex from where edge begins:\n");
			scanf("%d",&a);
			printf("Enter The vertex to where edge ends:\n");
			scanf("%d",&b);
			head=createListNode(head,a,b);
		}
		else if(ch==2)
		{
			scanf("%d",&m);
			Display(head,m);
		}
		else
			break;
	}
			
	return 0;	
}
