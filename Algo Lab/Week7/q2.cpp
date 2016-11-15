#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
typedef struct b
{
    struct b **c;
    int isLeaf;
    int numkeys;
    int* keys;
}Node;
Node* CreateNode()
{
    Node *t = (Node*)malloc(sizeof(Node));
    t->isLeaf = 1;
    t->numkeys = 0;
    t->c = (Node**)calloc((4),sizeof(Node*));
    t->keys = (int*)calloc((3),sizeof(int));
    return t;
}
int SplitChild(Node* parent,int pos)
{
   Node*left = CreateNode();
   Node*right = parent->c[pos];
   int i;
   left->numkeys = right->numkeys = 1;
   left->isLeaf = right->isLeaf;
   left->c[0] = right->c[0];
   left->c[1]  = right->c[1];
   right->c[0] = right->c[2];
   right->c[1] = right->c[3];
   right->c[2] = right->c[3] = NULL;
   left->keys[0] = right->keys[0];
   right->keys[0] = right->keys[2];
   for(i = 2;i>pos;i--)
        parent->keys[i] = parent->keys[i-1];
   for(i = 3;i>pos;i--)
        parent->c[i] = parent->c[i-1];
   parent->c[pos] = left;
   parent->c[pos+1] = right;
   parent->keys[pos] = right->keys[1];
   parent->numkeys++;
   parent->isLeaf = 0;
}
int Insert(Node* root,int key)
{
    int i,pos;
    if(root->isLeaf == 1)
    {
        for(i = 0;i<root->numkeys&&key>root->keys[i];i++);
        i--;
        pos = i;
        for(i = 2;i>pos+1;i--)
        root->keys[i] = root->keys[i-1];
        root->keys[pos+1] = key;
        root->numkeys++;
        if(root->numkeys >= 3)return 1;
        return 0;
    }
    for(i = 0;i<root->numkeys&&key>root->keys[i];i++);
    if(Insert(root->c[i],key))
    {
		SplitChild(root,i);
		if(root->numkeys==3)
		return 1;
	}
    return 0;
}
void InsertTree(Node**root, int key)
{
    Node *newroot,*temp = *root;
    if(!temp)
    {
        temp = CreateNode();
        *root = temp;
    }
    if(Insert(temp,key))
    {
        newroot = CreateNode();
        newroot->c[0] = temp;
        newroot->isLeaf = 0;
        SplitChild(newroot,0);
        *root = newroot;
    }
}
void Print(Node*root)
{  
    if(!root){return;}
   
    int i;

			
    for(i = 0;i<root->numkeys;i++)
        {
			printf("%d ",root->keys[i]);
		}
		
        printf("\n");
    for(i = 0;i<=root->numkeys;i++)
        Print(root->c[i]);
}

int main()
{
int i,val;
Node* root = NULL;
while(1)
{
    printf("1.Insert 2.Print\n");
    scanf("%d",&i);
    switch(i)
    {
    case 1: printf("Enter value: \n");
            scanf("%d",&val);
            InsertTree(&root,val);
    		break;
    case 2:Print(root);
            break;
    default: return 0;
    }
}
}