#include <stdio.h>
#include <stdlib.h>

int flag=0;
typedef struct node
{
	int val;
	struct node *left,*right;
}TREE;

TREE* create()
{
	TREE* temp=(TREE*)malloc(sizeof(TREE));
	temp->left=temp->right=NULL;	
	return temp;
}

TREE* insert(TREE* root,int val)
{
	if(root==NULL)
	{
		TREE* temp=create();
		temp->val=val;
		//temp->left=temp->right=NULL;
		root=temp;
		return root;	
	}
	TREE* curr=root;
	
	while(curr!=NULL)
	{
		if(curr->val==val)
		{
			printf("Present\n");
			break;
		}
		else if(root->val>val)
		{
			if(curr->left==NULL)
			{
				TREE* temp=create();
				curr->left=temp;				
				temp->val=val;
				break;
			}
			else
				curr=curr->left;
		}
		else
		{
				if(curr->right==NULL)
			{
				TREE* temp=create();
				curr->right=temp;				
				temp->val=val;
				break;
			}
			else
				curr=curr->right;	
		}		
	}	
	
	return root;
}

void inorder(TREE* root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\n",root->val);
		inorder(root->right);
	}
}

void preorder(TREE* root)
{
	if(root)
	{
		printf("%d\n",root->val);
		preorder(root->left);
		preorder(root->right);	
	}
}

void postorder(TREE* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->val);
	}
}
int main()
{
	TREE* root=NULL;
	int ch,dat;
	//int *flag=1;	
	while(1)
	{
		printf("1.Insert 2.Display 3.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	
				//flag=0;				
				printf("Enter value to enter:\n");
				scanf("%d",&dat);
				root=insert(root,dat);		
				break;	
			case 2:
				inorder(root);
				break;
			default:
				break;
		}
	}
	return 0;
}
						
		
