#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE;
typedef struct list1
{
	int v1,v2;
	int data;
	struct list1* next;
}LIST;

NODE* create(int data)
{
	NODE* temp = new NODE();
	temp->next=temp;
	temp->data=data;
	return temp;
}

LIST* createGraph(int x,int y,int data)
{
	LIST* temp = new LIST();
	temp->next=NULL;
	temp->data=data;
	temp->v1=x;
	temp->v2=y;
	return temp;
}

void Display(LIST* head){
	LIST* curr=head;
	while(curr!=NULL){
		cout<<"V1:"<<curr->v1<<" V2:"<<curr->v2<<" Edge:"<<curr->data<<endl;
		curr=curr->next;
	}
}
LIST* insertList(LIST* head,int x,int y,int data)
{
	if(!head)
	{
		LIST* temp=createGraph(x,y,data);
		//temp->data=data;
		head=temp;
		return head;
	}
	if(head->next == NULL && data>head->data){
		LIST* temp=createGraph(x,y,data);
		head->next=temp;
		//cout<<"Here1\n";
		return head;
		
			//prev->next=temp;
		//temp->next=curr;
		}
	if( data<head->data){
		LIST* temp=createGraph(x,y,data);
		temp->next=head;
		cout<<"Here2\n";
		return temp;
	}
	else
	{
		LIST* curr=head;
		LIST* prev=NULL;
		//cout<<"Here3\n";
		while(curr->next!=NULL && curr->data < data){
			prev=curr;
			curr=curr->next;
			//Display(head);
		}
		
			if(curr->next == NULL && curr->data < data){
				//cout<<"Here4\n";
				curr->next=createGraph(x,y,data);
				return head;
			}
			else{
			LIST* temp=createGraph(x,y,data);
			prev->next=temp;
			temp->next=curr;
		}
		//curr->next->data=data;
	}
	return head;
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

		while(curr->next!=curr)
		{
			curr=curr->next;
		}
		curr->next=create(data);
		//curr->next->data=data;
	}
}

NODE* find(int i,NODE* head2){

}
LIST* sol(LIST* head,NODE* head2[100],int adj[][100]){
	LIST* curr=head;
	int i,j,data;
	while(curr!=NULL){
		i=curr->v1;
		j=curr->v2;
		k=find(i,head2[v1]);
		l=find(j,head2[v2]);
		if(k!=0 && l!=0){
			create[i]->next=create[j];
		}

	}
}
int main(int argc, char const *argv[])
{
	int n,graph[100][100]={0},data,v1,v2,ch,a,b;
	LIST* head=NULL;
	NODE* ans[100];
	cout<<"Enter n:";
	cin>>n;
	int i=0;
	for(i=0;i<n;i++)
		ans[i]=create(i);

	while(1){
		cout<<"1.Enter 2.Display 3.Exit\n";
		cin>>ch;
		if(ch==1){
			cout<<"Enter Starting and End Vertex:\n";
			cin>>a>>b;
			cout<<"Enter Data:\n";
			cin>>data;
			head = insertList(head,a,b,data);
		}
		else if(ch == 2){
			Display(head);
		}

		else
			break;
	}
	//cout<<
	return 0;
}