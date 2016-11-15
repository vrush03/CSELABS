#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef struct node
{
	int data;
	struct node* left,*right;
	int h;
}TREE;
TREE* create()
{
	TREE* temp=new TREE();
	temp->left=temp->right=NULL;
	temp->h=1;
	return temp;
}
int height(TREE* root)
{
	if(!root)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
int getbal(TREE* root)
{
	if(!root)
		return 0;
	return height(root->left)-height(root->right);
}
TREE* rightRot(TREE* n1)
{
	TREE* p=n1->left;
	TREE* p2=p->right;
	p->right=n1;
	n1->left=p2;
	p->h=max(height(p->left),height(p->right))+1;
	n1->h=max(height(n1->left),height(n1->right)) +1;
	return p;
}

TREE* leftRot(TREE* n2)
{
	TREE* p1=n2->right;
	TREE* p2=p1->left;
	p1->left=n2;
	n2->right=p2;
	p1->h=max(height(p1->left),height(p1->right))+1;
	n2->h=max(height(n2->left),height(n2->right)) +1;
	return p1;
}
TREE* insert(TREE* root,int data)
{
	if(!root)
	{
		root=create();
		root->data=data;
		return root;
	}
	if(root->data>data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	root->h= max(height(root->left),height(root->right)) + 1;
	int bal=getbal(root);
	if(bal>1 && data<root->left->data)
	{
		return rightRot(root);
	}
	if(bal<-1 && data>root->right->data)
	{
		return leftRot(root);
	}
	if(bal>1 && data>root->left->data)
	{
		root->left=leftRot(root->left);
		return rightRot(root);
	}
	if(bal<-1 && data<root->right->data)
	{
		root->right=rightRot(root->right);
		return leftRot(root);
	}

	return root;
}
void inorder(TREE* root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int main(int argc, char const *argv[])
{
	TREE* root;
	int data;
	int ch;
	while(1)
	{
		cout<<"1.Enter 2.Display 3.Exit\n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter Data:\n";
			cin>>data;
			root=insert(root,data);
		}
		else if(ch==2)
			inorder(root);
		else
			break;
	}
	return 0;
} 