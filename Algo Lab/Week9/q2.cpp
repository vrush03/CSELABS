#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE* create(int data)
{
	NODE* temp = new NODE();
	temp->next=NULL;
	temp->data=data;
	return temp;
}

NODE* insert(NODE* head,int data)
{
	if(!head)
	{
		NODE* temp=create(data);
		//temp->data=data;
		head=temp;
	}
	else
	{
		NODE* curr=head;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=create(data);
		//curr->next->data=data;
	}
}
int main(int argc, char const *argv[])
{
	//map<int,list<int>> m;
	//int a[10000];
	NODE* List[1000];
	int i,ch,data,rem;
	for(i=0;i<10;i++)
	{
		List[i]=create(i);
	}
	while(1)
	{
		cout<<"1.Enter 2.Display 3.Search 4.Exit:\n";
		cin>>ch;
		if(ch == 1)
		{
			cin>>data;
			rem=data%10;
			insert(List[rem],data);
		}
		else if(ch == 2)
		{
			for(i=0;i<10;i++)
			{
				NODE* curr=List[i];
				while(curr!=NULL)
				{
					cout<<curr->data<<" ";
					curr=curr->next;
				}
				cout<<endl;
			}
		}
		else if(ch == 3)
		{
			cout<<"Enter element to Search:";
			cin>>data;
			rem=data%10;
			NODE* curr=List[rem];
			while(curr!=NULL)
			{
				if(curr->data == data)
					break;
				curr=curr->next;
			}
			if(curr == NULL)
				cout<<"Element is Not present\n";
			else
				cout<<"Elemet Found in the Map in Bucket:"<<rem<<endl;
		}
		else
			break;
	}
	return 0;
}