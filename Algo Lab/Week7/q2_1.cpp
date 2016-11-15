#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	struct node **child;
	int leaf;
	int n;
	int keys[3];
}Node;

Node* create()
{
	Node* temp=new Node();
	temp->leaf=0;
	temp->0;
	temp->child = (Node**)malloc(4*sizeof(Node*));
	return temp;
}
Node* split(Node* par,int pos)
{
	Node* right=par->c[pos];
	Node* left=create();
	left->n=right->n=1;
	left->leaf=right->leaf;
	left->child[0]=right->child[0];
	left->child[1]=right->child[1];
	right->child[0]=right->child[2];
	right->child[1]=right->child[3];
	right->child[2]=NULL;
	right->child[3]=NULL;
	left->keys[0] = right->keys[0];
   	right->keys[0] = right->keys[2];
   	for(int i = 2;i>pos;i--)
        par->keys[i] = par->keys[i-1];
   	for(int i = 3;i>pos;i--)
        par->child[i] = par->child[i-1];
   par->c[pos] = left;
   par->c[pos+1] = right;
   par->keys[pos] = right->keys[1];
   par->n++;
   par->Leaf = 0;
}

int insert(Node* root,int data)
{
    int i,pos;
    if(root->Leaf == 1)
    {
        for(i = 0;i<root->n && data>root->keys[i];i++);
        i--;
        pos = i;
        for(i = 2;i>pos+1;i--)
        root->keys[i] = root->keys[i-1];
        root->keys[pos+1] = data;
        root->n++;
        if(root->n >= 3)return 1;
        return 0;
    }
    for(i = 0;i<root->n && data>root->keys[i];i++);
    if(insert(root->c[i],data))
    {
		split(root,i);
		if(root->n==3)
		return 1;
	}
    return 0;
}

void InsertTree(Node**root, int key)
{
    Node *n1,*temp = *root;
    if(!temp)
    {
        temp = create();
        *root = temp;
    }
    if(insert(temp,key))
    {
        n1 = create();
        n1->child[0] = temp;
        n1->Leaf = 0;
        split(n1,0);
        *root = n1;
    }
}
void printdata(Node *root)

{   
    if(!root)
    	{
    		return;
    	}
    
    int i,j;

			
    for(i = 0;i<root->numkeys;i++)
        {
			printf("%d ",root->keys[i]);
		}
		
        printf("\n");
    for(i = 0;i<=root->numkeys;i++)
        Print(root->c[i]);
}
