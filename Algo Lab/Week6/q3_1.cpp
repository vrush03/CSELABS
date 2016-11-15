#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct tnode
{
  int data;
  struct tnode *lchild;
  struct tnode *rchild;
}TNode;

TNode *getTNode()
{
  TNode *newnode = (TNode *) malloc (sizeof(TNode));
  newnode->rchild = newnode->lchild = NULL;
  return newnode;
}
int height(TNode *rt)
{
	if(rt==NULL)
		return 0;
	return 1 + max(height(rt->lchild), height(rt->rchild));
}

int diameter(TNode *rt)
{
	if(rt==NULL)
		return 0;
	int lheight = height(rt->lchild);
  	int rheight = height(rt->rchild);
  	int ldiameter = diameter(rt->lchild);
  	int rdiameter = diameter(rt->rchild);
 
 return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}
void insert (TNode **rt, int item)
{
  int ch;
  TNode *t = *rt;
  TNode *present = NULL;
  TNode *newnode;
  if (*rt == NULL)
    {
      *rt = getTNode();
      (*rt)->data = item;
      return;
    }
  do
    {
      printf("1 to insert to left, 2 to insert to right: ");
      scanf("%d", &ch);
      present = t;
      if (ch == 1)
		t= t->lchild;
      else
		t = t->rchild;
      if (t == NULL)
	{
	  newnode = getTNode();
	  newnode->data = item;
	  (ch == 1)?(present->lchild=newnode):(present->rchild=newnode);
	  return;
	}
    }while (1);
}
void inorder(TNode* root)
{
	if(root)
	{
		inorder(root->lchild);
		cout<<root->data<<" ";
		inorder(root->rchild);
	}
}
int main(int argc, char const *argv[])
{
	int ch;
	int data;
	TNode* root=NULL;
	while(1)
	{
		cout<<"1.Insert 2.Display 3.Exit\n";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter data:\n";
			cin>>data;
			insert(&root,data);
			//cout<<root->data;
			//continue;
		}
		else if(ch==2)
		{
			inorder(root);
			printf("\n");
		}
		else
			break;
	}
	cout<<"Diameter of the Tree is:\n";
	cout<<diameter(root)<<endl;
	cout<<"Height of the Tree is:\n";
	cout<<height(root)<<endl;

	return 0;
}
